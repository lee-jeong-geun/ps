#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, y, count, dir;
}Data;
Data virus[1005];
int N, M, K, result, chk[5][105][105];
int arrA[4] = {0, 0, -1, 1};
int arrB[4] = {-1, 1, 0, 0};
int Dir[4] = {1, 0, 3, 2};

void init()
{
    result = 0;
}

bool range(int a, int b)
{
    if(a == 0 || a == N - 1 || b == 0 || b == N - 1)
    {
        return 1;
    }
    return 0;
}

void func()
{
    int clearcount = 0;
    Data clearzone[1005];
    while(M--)
    {
        clearcount = 0;
        for(int i = 0; i < K; i++)
        {
            if(virus[i].count == 0)
            {
                continue;
            }
            virus[i].x += arrA[virus[i].dir];
            virus[i].y += arrB[virus[i].dir];
            if(range(virus[i].x, virus[i].y) == 1)
            {
                virus[i].count /= 2;
                virus[i].dir = Dir[virus[i].dir];
            }
            chk[1][virus[i].y][virus[i].x] += virus[i].count;
            if(chk[0][virus[i].y][virus[i].x] < virus[i].count)
            {
                if(chk[0][virus[i].y][virus[i].x] != 0)
                {
                    virus[chk[2][virus[i].y][virus[i].x]].count = 0;
                }
                clearzone[clearcount].x = virus[i].x;
                clearzone[clearcount++].y = virus[i].y;
                chk[0][virus[i].y][virus[i].x] = virus[i].count;
                chk[2][virus[i].y][virus[i].x] = i;
            }
            else
            {
                virus[i].count = 0;
            }
        }
        for(int i = 0; i < clearcount; i++)
        {
            if(chk[1][clearzone[i].y][clearzone[i].x] == 0)
            {
                continue;
            }
            virus[chk[2][clearzone[i].y][clearzone[i].x]].count = chk[1][clearzone[i].y][clearzone[i].x];
            chk[0][clearzone[i].y][clearzone[i].x] = 0;
            chk[1][clearzone[i].y][clearzone[i].x] = 0;
        }
    }
    for(int i = 0; i < K; i++)
    {
        result += virus[i].count;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        init();
        scanf("%d %d %d", &N, &M, &K);
        for(int i = 0; i < K; i++)
        {
            scanf("%d %d %d %d", &virus[i].y, &virus[i].x, &virus[i].count, &virus[i].dir);
            virus[i].dir--;
        }
        func();
        printf("#%d %d\n", testcase, result);
    }
}