#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, zone[25][25], chk[25], memo[25][25], func2arr[5], result = 987654321, funccount;

int func2(int flag, int depth, int idx)
{
    int temp = 0;
    if(depth == 2)
    {
        temp = zone[func2arr[0]][func2arr[1]] + zone[func2arr[1]][func2arr[0]];
        return temp;
    }
    for(int i = idx + 1; i < N; i++)
    {
        if(chk[i] == flag)
        {
            func2arr[depth] = i;
            temp = temp + func2(flag, depth + 1, i);
        }
    }
    return temp;
}

void func(int depth, int idx)
{
    if(depth == N / 2)
    {
        int start = 0, link = 0;
        funccount++;
        start = func2(1, 0, -1);
        link = func2(0, 0, -1);
        result = min(result, abs(start - link));
        return;
    }
    for(int i = idx + 1; i < N; i++)
    {
        chk[i] = 1;
        func(depth + 1, i);
        chk[i] = 0;
        if(funccount == memo[N][N/2])
        {
            return;
        }
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &zone[i][j]);
        }
    }
    memo[1][1] = 1;
    for(int i = 2; i <= N; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j];
        }
    }
    func(0, -1);
    printf("%d", result);
}