#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, zone[25][25], chk[105], result;
int arrA[4] = {1, 1, -1, -1};
int arrB[4] = {-1, 1, 1, -1};

int range(int a, int b)
{
    if(a >= 0 && a < N && b >= 0 && b < N)
    {
        return 1;
    }
    return 0;
}

void func(int sx, int sy, int x, int y, int count, int dir)
{
    if(dir == 0 && x == sx && y == sy)
    {
        result = max(result, count);
    }
    if(range(x, y) == 0 || chk[zone[y][x]] == 1)
    {
        return;
    }
    chk[zone[y][x]] = 1;
    int nextx, nexty;
    func(sx, sy, x + arrA[dir], y + arrB[dir], count + 1, dir);
    if(dir == 1)
    {
        func(sx, sy, x + arrA[2], y + arrB[2], count + 1, 2);
    }
    else if(dir == 2)
    {
        func(sx, sy, x + arrA[3], y + arrB[3], count + 1, 3);
    }
    else if(dir == 3)
    {
        func(sx, sy, x + arrA[0], y + arrB[0], count + 1, 0);
    }
    chk[zone[y][x]] = 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        result = 0;
        scanf("%d", &N);
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
                func(j, i, j, i, 1, 1);
            }
        }
        printf("#%d ", testcase);
        if(result < 5)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", result - 1);
        }
    }
}