#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int x;
    int y;
    int type;
    int Time;
}Data;
int N, M, K, zone[365][365], result;
int arrA[4] = {0, 1, 0, -1};
int arrB[4] = {-1, 0, 1, 0};

queue<Data> q;

/*
문제의 조건에 맞게 시뮬레이션을 구현 하면 된다.
조건에서 맵은 한계가 없지만 잘 보면 시간은 최대 300초 이고 제일 빨리 번식하는 생명주기 1초짜리 세포는
2초마다 한번씩 번식 하게 되므로 최대로 갈 수 있는 길이는 150칸 이다.
따라서 크기를 상하좌우 160칸 정도 늘린 상태에서 구현 하면 된다.
세포를 맵에서 일일이 찾아서 확인 하는것은 시간이 오래 걸리므로 비활성, 활성 세포들을 큐에 넣어서 
큐에 있는 세포들만 확인 해주면 된다.
*/

void func()
{
    //같은 곳에 번식 하는 세포들 처리 용도 큐
    queue<Data> clearq;
    for(int T = 0; T < K; T++)
    {
        //큐 크기 만큼 반복문 돌림
        int qcount;
        qcount = q.size();
        while(qcount-- > 0)
        {
            Data temp, next, nnext;
            temp = q.front();
            next = temp;
            q.pop();
            //세포 번식
            if(temp.type == 0)
            {
                //4방향 확인
                for(int i = 0; i < 4; i++)
                {
                    nnext = next;
                    nnext.type = next.Time;
                    nnext.x = temp.x + arrA[i];
                    nnext.y = temp.y + arrB[i];
                    //세포가 없거나 이제 막 번식해서 자리 잡은 곳일 경우
                    //생명력이 큰 세포를 저장
                    if(zone[nnext.y][nnext.x] >= 0 && zone[nnext.y][nnext.x] < nnext.Time)
                    {
                        zone[nnext.y][nnext.x] = nnext.Time;
                        clearq.push(nnext);
                    }
                }
            }
            //생명력이 남아있는 경우
            if(temp.type - 1 != temp.Time * -1)
            {
                //번식을 끝낸 세포가 K시간 보다 일찍 죽는 경우는 큐에 넣어도 무의미
                if(temp.type < 0 && T + temp.Time + (temp.type - 1) < K)
                {
                    continue;
                }
                next.type--;
                q.push(next);
            }
        }
        //같은 곳에 번식한 세포들 처리
        while(!clearq.empty())
        {
            Data temp;
            temp = clearq.front();
            clearq.pop();
            //해당 위치의 최대값이랑 같은 경우
            if(zone[temp.y][temp.x] == temp.Time)
            {
                zone[temp.y][temp.x] = -temp.Time;
                //시뮬레이션 큐에 저장
                q.push(temp);
            }
        }
    }
    result = q.size();
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        while(!q.empty())
        {
            q.pop();
        }
        result = 0;
        memset(zone, 0, sizeof zone);
        scanf("%d %d %d", &N, &M, &K);
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                int num;
                scanf("%d", &num);
                //맵 확장
                zone[i + 150][j + 150] = -num;
                if(num != 0)
                {
                    q.push({j + 150, i + 150, num, num});
                }
            }
        }
        func();
        printf("#%d %d\n", testcase, result);
    }
}