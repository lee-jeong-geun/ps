#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, C, zone[15][15], result;

int func2(int sx, int ex, int y, int hap, int money)
{
    int Max = 0;
    Max = max(Max, money);
    for(int i = sx; i <= ex; i++)
    {
        if(hap + zone[y][i] <= C)
        {
            Max = max(Max, func2(i + 1, ex, y, hap + zone[y][i], money + zone[y][i] * zone[y][i]));
        }
    }
    return Max;
}

void func(int sx, int ex, int y)
{
    int fhap, shap;
    for(int i = y; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i == y && j <= ex)
            {
                continue;
            }
            if(j + M - 1 >= N)
            {
                continue;
            }
            fhap = func2(sx, ex, y, 0, 0);
            shap = func2(j, j + M - 1, i, 0, 0);
            result = max(result, fhap + shap);
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        result = 0;
        scanf("%d %d %d", &N, &M, &C);
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                scanf("%d", &zone[i][j]);
            }
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(j + M - 1 >= N)
                {
                    continue;
                }
                func(j, j + M - 1, i);
            }
        }
        printf("#%d %d\n", testcase, result);
    }
}