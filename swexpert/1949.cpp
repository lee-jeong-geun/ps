#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int x, y;
}Data;
Data Start[10];
int N, K, zone[15][15], chk[15][15], Scount, Maxheight, result;
int arrA[4] = {0, 0, 1, -1};
int arrB[4] = {1, -1, 0, 0};

void init()
{
    Scount = 0;
    Maxheight = 0;
    result = 0;
}

int range(int a, int b)
{
    if(a >= 0 && a < N && b >= 0 && b < N)
    {
        return 1;
    }
    return 0;
}

void func(int x, int y, int count, int flag)
{
    if(result < count)
    {
        result = count;
    }
    for(int i = 0; i < 4; i++)
    {
        int nextx, nexty;
        nextx = x + arrA[i];
        nexty = y + arrB[i];
        if(range(nextx, nexty) == 1 && chk[nexty][nextx] == 0)
        {
            if(zone[nexty][nextx] < zone[y][x])
            {
                chk[nexty][nextx] = 1;
                func(nextx, nexty, count + 1, flag);
                chk[nexty][nextx] = 0;
            }
            else
            {
                if(flag == 1 && zone[nexty][nextx] - K < zone[y][x])
                {
                    int temp;
                    temp = zone[nexty][nextx];
                    zone[nexty][nextx] = zone[y][x] - 1;
                    chk[nexty][nextx] = 1;
                    func(nextx, nexty, count + 1, 0);
                    chk[nexty][nextx] = 0;
                    zone[nexty][nextx] = temp;
                }
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        init();
        scanf("%d %d", &N, &K);
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                scanf("%d", &zone[i][j]);
                if(Maxheight < zone[i][j])
                {
                    Maxheight = zone[i][j];
                    Scount = 0;
                    Start[Scount].x = j;
                    Start[Scount++].y = i;
                }
                else if(Maxheight == zone[i][j])
                {
                    Start[Scount].x = j;
                    Start[Scount++].y = i;
                }
            }
        }
        for(int i = 0; i < Scount; i++)
        {
            chk[Start[i].y][Start[i].x] = 1;
            func(Start[i].x, Start[i].y, 1, 1);
            chk[Start[i].y][Start[i].x] = 0;
        }
        printf("#%d %d\n", testcase, result);
    }
}