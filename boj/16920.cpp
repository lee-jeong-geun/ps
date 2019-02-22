#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef struct _data
{
    int x;
    int y;
    int Time;
    int player;
}Data;
vector<Data> vec[15];
int N, M, P, Num[15], result[15];
char zone[1005][1005];
int arrX[4] = {0, 1, 0, -1};
int arrY[4] = {-1, 0, 1, 0};

/*
큐2개를 이용하여 모든 플레이어들을 1번부터 순서대로 첫번째 큐에 넣고 
첫번째 큐에서 해당 플레이어의 모든 성들을 두번째 큐에 넣는다.
두번째 큐에서 BFS를 돌고 끝나는 것들을 첫번째 큐에 넣는다.
움직이는것들이 없을때까지 돌면 된다.
*/

void BFS()
{
    queue<Data> q[5];
    for(int i = 1; i <= P; i++)
    {
        for(int j = 0; j < vec[i].size(); j++)
        {
            //i번 플레이어의 성들을 1번 큐에 푸쉬
            q[0].push({vec[i][j].x, vec[i][j].y, Num[i], i});
        }
    }
    int player = 1;
    while(1)
    {
        int flag = 0;
        while(!q[0].empty())
        {
            flag = 1;
            Data temp;
            temp = q[0].front();
            //플레이어가 다르면 종료
            if(temp.player != player)
            {
                player = temp.player;
                break;
            }
            q[0].pop();
            //2번 큐에 푸쉬
            q[1].push(temp);
        }
        //BFS
        while(!q[1].empty())
        {
            Data temp;
            temp = q[1].front();
            q[1].pop();
            for(int i = 0; i < 4; i++)
            {
                Data next;
                next = temp;
                next.x = temp.x + arrX[i];
                next.y = temp.y + arrY[i];
                next.Time = temp.Time - 1;
                if(next.x >= 0 && next.x < M && next.y >= 0 && next.y < N && zone[next.y][next.x] == '.')
                {
                    zone[next.y][next.x] = next.player + '0';
                    result[next.player]++;
                    //이동 횟수가 남은 경우
                    if(next.Time > 0)
                    {
                        q[1].push(next);
                    }
                    else
                    {
                        next.Time = Num[next.player];
                        //1번큐에 푸쉬
                        q[0].push(next);
                    }
                }
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &P);
    for(int i = 1; i <= P; i++)
    {
        scanf("%d", &Num[i]);
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf(" %c", &zone[i][j]);
            if(zone[i][j] >= '1' && zone[i][j] <= '9')
            {
                //각 플레이어들의 성 위치 저장
                vec[zone[i][j] - '0'].push_back({j, i, 0, 0});
                result[zone[i][j] - '0']++;
            }
        }
    }
    BFS();
    for(int i = 1; i <= P; i++)
    {
        printf("%d ", result[i]);
    }
}