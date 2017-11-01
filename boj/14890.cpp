#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, y, dir;
}Data;
Data Start[205];
int N, L, zone[105][105], chk[5][105][105], sidx, result;
int arrA[4] = {0, 1, 0, -1};
int arrB[4] = {-1, 0, 1, 0};

int range(int a, int b)
{
    if(a >= 0 && a < N && b >= 0 && b < N)
    {
        return 1;
    }
    return 0;
}

int main()
{
    scanf("%d %d", &N, &L);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &zone[i][j]);
        }
    }
    for(int i = 0; i < N; i++)
    {
        if(zone[0][i] >= zone[N - 1][i])
        {
            Start[sidx].x = i;
            Start[sidx].y = 0;
            Start[sidx++].dir = 2;
        }
        else
        {
            Start[sidx].x = i;
            Start[sidx].y = N - 1;
            Start[sidx++].dir = 0;
        }
        if(zone[i][0] >= zone[i][N - 1])
        {
            Start[sidx].x = 0;
            Start[sidx].y = i;
            Start[sidx++].dir = 1;
        }
        else
        {
            Start[sidx].x = N - 1;
            Start[sidx].y = i;
            Start[sidx++].dir = 3;
        }
    }
    for(int i = 0; i < sidx; i++)
    {
        int tempx, tempy;
        tempx = Start[i].x;
        tempy = Start[i].y;
        while(1)
        {
            int flag = 0;
            int nextx, nexty;
            nextx = tempx + arrA[Start[i].dir];
            nexty = tempy + arrB[Start[i].dir];
            if(range(nextx, nexty) == 0)
            {
                result++;
                break;
            }
            if(zone[tempy][tempx] == zone[nexty][nextx])
            {
                tempx = nextx;
                tempy = nexty;
            }
            else if(zone[tempy][tempx] == zone[nexty][nextx] - 1)
            {
                int nnextx, nnexty;
                nnextx = tempx;
                nnexty = tempy;
                for(int j = 0; j < L; j++)
                {
                    if(range(nnextx, nnexty) == 1 && zone[tempy][tempx] == zone[nnexty][nnextx] && chk[Start[i].dir][nnexty][nnextx] == 0)
                    {
                        chk[Start[i].dir][nnexty][nnextx] = 1;
                        tempx = nnextx;
                        tempy = nnexty;        
                    }
                    else
                    {
                        flag = 1;
                        break;
                    }
                    nnextx = tempx + arrA[(Start[i].dir + 2) % 4];
                    nnexty = tempy + arrB[(Start[i].dir + 2) % 4];
                }
                if(flag == 1)
                {
                    break;
                }
                else
                {
                    tempx = nextx;
                    tempy = nexty;
                }
            }
            else if(zone[tempy][tempx] == zone[nexty][nextx] + 1)
            {
                int nnextx, nnexty;
                nnextx = nextx;
                nnexty = nexty;
                for(int j = 0; j < L; j++)
                {
                    if(range(nnextx, nnexty) == 1 && zone[nexty][nextx] == zone[nnexty][nnextx] && chk[Start[i].dir][nnexty][nnextx] == 0)
                    {
                        chk[Start[i].dir][nnexty][nnextx] = 1;
                        nextx = nnextx;
                        nexty = nnexty;        
                    }
                    else
                    {
                        flag = 1;
                        break;
                    }
                    nnextx = nextx + arrA[Start[i].dir];
                    nnexty = nexty + arrB[Start[i].dir];
                }
                if(flag == 1)
                {
                    break;
                }
                else
                {
                    tempx = nextx;
                    tempy = nexty;
                }
            }
            else
            {
                break;
            }
        }
    }
    printf("%d", result);
}