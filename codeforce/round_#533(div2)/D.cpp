#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef struct _data
{
    int x;
    int y;
    int idx;
    int Time;
}Data;
Data playerStart[10][1000005];
int playerStartIdx[10];
int n, m, p, playerMove[15], chk[1005][1005], result[15];
char zone[1005][1005];
int arrX[4] = {0, 1, 0, -1};
int arrY[4] = {-1, 0, 1, 0};

/*
처음에 모든 플레이어들의 시작 위치를 저장후 BFS를 돌린다.
BFS를 돌릴때 큐 2개를 이용해서 첫번째 큐는 플레이어 들의 위치만 저장 하고
두번째 큐를 이용해서 실제로 플레이어들을 움직인다.
두번째 큐에서 이동을 다 한 플레이어 위치는 첫번째 큐에 저장 해서 다음 차례를 기다린다.
*/

void BFS()
{
    queue<Data> q, q2;
    for(int i = 1; i <= p; i++)
    {
        for(int j = 0; j < playerStartIdx[i]; j++)
        {
            //시작 위치를 첫번째 큐에 저장
            q.push({playerStart[i][j].x, playerStart[i][j].y, i, playerMove[i]});
        }
    }
    int Player = 1;
    while(1)
    {
        int flag = 0;
        while(!q.empty())
        {
            flag = 1;
            Data temp;
            temp = q.front();
            //동일한 플레이어 위치를 두번째 큐에 저장
            if(temp.idx == Player)
            {
                q2.push(temp);
                q.pop();
            }
            else
            {
                Player = temp.idx;
                break;
            }
        }
        while(!q2.empty())
        {
            Data temp;
            temp = q2.front();
            q2.pop();
            for(int i = 0; i < 4; i++)
            {
                Data next;
                next.x = temp.x + arrX[i];
                next.y = temp.y + arrY[i];
                next.idx = temp.idx;
                next.Time = temp.Time - 1;
                if(next.x >= 0 && next.x < m && next.y >= 0 && next.y < n)
                {
                    if(zone[next.y][next.x] == '.' && chk[next.y][next.x] == 0)
                    {
                        chk[next.y][next.x] = 1;
                        result[temp.idx]++;
                        //이동 횟수가 남아있는 경우
                        if(next.Time > 0)
                        {
                            q2.push(next);
                        }
                        //이동 횟수 없는 경우
                        else
                        {
                            //첫번째 큐에 저장
                            next.Time = playerMove[temp.idx];
                            q.push(next);
                        }
                    }
                }
            }
        }
        if(flag == 0)
        {
            return;
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &p);
    for(int i = 1; i <= p; i++)
    {
        scanf("%d", &playerMove[i]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf(" %c", &zone[i][j]);
            //플레이어 위치 저장
            if(zone[i][j] >= '1' && zone[i][j] <= '9')
            {
                playerStart[zone[i][j] - '0'][playerStartIdx[zone[i][j] - '0']].x = j;
                playerStart[zone[i][j] - '0'][playerStartIdx[zone[i][j] - '0']++].y = i;
                result[zone[i][j] - '0']++;
                chk[i][j] = 1;
            }
        }
    }
    BFS();
    for(int i = 1; i <= p; i++)
    {
        printf("%d ", result[i]);
    }
}