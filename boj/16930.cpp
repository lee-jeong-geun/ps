#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef struct _data
{
    int x;
    int y;
    int count;
}Data;
int N, M, K, sx, sy, ex, ey;
bool chk[1005][1005];
char zone[1005][1005];
int arrX[4] = {0, 1, 0, -1};
int arrY[4] = {-1, 0, 1, 0};

/*
BFS돌릴 때 각 방향에 대하여 K번 만큼 전진 시키면 된다.
*/

int BFS()
{
    queue<Data> q;
    q.push({sx, sy, 0});
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        //도착 지점
        if(temp.x == ex && temp.y == ey)
        {
            return temp.count;
        }
        for(int i = 0; i < 4; i++)
        {
            Data next;
            //k번 전진
            for(int j = 1; j <= K; j++)
            {
                next.x = temp.x + arrX[i] * j;
                next.y = temp.y + arrY[i] * j;
                next.count = temp.count + 1;
                //빈공간인 경우
                if(zone[next.y][next.x] == '.')
                {
                    if(chk[next.y][next.x] == 0)
                    {
                        chk[next.y][next.x] = 1;
                        q.push(next);
                    }
                }
                //멈춰야될 경우
                else
                {
                    break;
                }
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            scanf(" %c", &zone[i][j]);
        }
    }
    scanf("%d %d %d %d", &sy, &sx, &ey, &ex);
    printf("%d", BFS());
}