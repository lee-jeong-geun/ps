#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef struct _data
{
    int x;
    int y;
    int wallCount;
}Data;
int N, M, K, zone[1005][1005], chk[1002][1002][11], result = 987654321;
int arrX[4] = {0, 1, 0, -1};
int arrY[4] = {-1, 0, 1, 0};

/*
조건에 맞게 BFS를 구현하면 된다. 벽을 1번 부순것이랑 2번 부순것은 다른 상태이므로 chk배열을 3차원으로
만들어서 벽을 부순횟수를 따로 관리 해줘야 한다. 그리고 벽을 부술때 낮에만 가능하므로 밤인 상태라면
낮이 될때까지 기다리지 않고 낮을 기다리는 시간인 1을 더해주면 된다. 이때 가중치가 달라지게 되므로
chk배열에 최소 이동시간을 저장해야 한다.
*/

void BFS()
{
    queue<Data> q;
    q.push({0, 0, 0});
    //가장 처음은 1
    chk[0][0][0] = 1;
    while(!q.empty())
    {
        int tCount = 0;
        Data temp;
        temp = q.front();
        q.pop();
        tCount = chk[temp.y][temp.x][temp.wallCount];
        //도착한 경우
        if(temp.x == M - 1 && temp.y == N - 1)
        {
            result = min(result, tCount);
        }
        for(int i = 0; i < 4; i++)
        {
            int nextCount = 0;
            Data next;
            next.x = temp.x + arrX[i];
            next.y = temp.y + arrY[i];
            next.wallCount = temp.wallCount;
            //맵 안에 들어옴
            if(next.x >= 0 && next.x < M && next.y >= 0 && next.y < N)
            {
                //벽인 경우
                if(zone[next.y][next.x] == 1)
                {
                    //벽을 더 부술수 있는 경우
                    if(next.wallCount < K)
                    {
                        next.wallCount++;
                        //밤인 경우
                        if((tCount + 1) % 2 == 1)
                        {
                            nextCount = 1;
                        }
                    }
                    //더 못부수면 continue 시킴
                    else
                    {
                        continue;
                    }
                }
                //다음 위치에 저장된 이동시간 보다 더 작은 경우
                if(chk[next.y][next.x][next.wallCount] > tCount + nextCount + 1)
                {
                    chk[next.y][next.x][next.wallCount] = tCount + nextCount + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%1d", &zone[i][j]);
        }
    }
    memset(chk, 0x3f, sizeof chk);
    BFS();
    //도착하지 못한 경우
    if(result == 987654321)
    {
        result = -1;
    }
    printf("%d", result);
}