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
int N, M, zone[1005][1005];
bool chk[1005][1005];
int H, W, Sr, Sc, Fr, Fc;
int arrX[4] = {0, 1, 0, -1};
int arrY[4] = {-1, 0, 1, 0};

/*
직사각형을 움직이고 해당 좌표들에 벽이 있는지 없는지를 확인할 때
단순하게 직사각형 크기만큼 확인하면 시간초과가 나게 된다.
따라서 벽의 개수들의 부분합을 구해 놓고 직사각형이 움직인 위치에 
벽이 몇개 있는지 확인하면서 BFS를 돌리면 된다.
*/

int BFS()
{
    queue<Data> q;
    q.push({Sc, Sr, 0});
    chk[Sr][Sc] = 1;
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        //도착 지점
        if(temp.x == Fc && temp.y == Fr)
        {
            return temp.count;
        }
        for(int i = 0; i < 4; i++)
        {
            int xSize, ySize;
            Data next;
            next.x = temp.x + arrX[i];
            next.y = temp.y + arrY[i];
            next.count = temp.count + 1;
            xSize = next.x + W - 1;
            ySize = next.y + H - 1;
            //맵안에 존재, 한번도 가지 않은 경우
            if(next.x >= 1 && next.y >= 1 && xSize <= M && ySize <= N && chk[next.y][next.x] == 0)
            {
                //벽의 개수가 0인 경우
                if(zone[ySize][xSize] - zone[next.y - 1][xSize] - zone[ySize][next.x - 1] + zone[next.y - 1][next.x - 1] == 0)
                {
                    chk[next.y][next.x] = 1;
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            scanf("%d", &zone[i][j]);
            //부분합
            zone[i][j] += zone[i - 1][j] + zone[i][j - 1] - zone[i - 1][j - 1];
        }
    }
    scanf("%d %d %d %d %d %d", &H, &W, &Sr, &Sc, &Fr, &Fc);
    printf("%d", BFS());
}