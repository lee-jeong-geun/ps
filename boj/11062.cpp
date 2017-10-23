#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, Card[1005], memo[2][1005][1005];

int func(int turn, int left, int right)
{
    if(left > right)
    {
        return 0;
    }
    int &ret = memo[turn][left][right];
    if(ret != -1)
    {
        return ret;
    }
    if(turn == 0)
    {
        ret = 0;
        ret = max(ret, func(1, left + 1, right) + Card[left]);
        ret = max(ret, func(1, left, right - 1) + Card[right]);
    }
    else
    {
        ret = 987654321;
        ret = min(ret, func(0, left + 1, right));
        ret = min(ret, func(0, left, right - 1));
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &Card[i]);
        }
        memset(memo, -1, sizeof memo);
        printf("%d\n", func(0, 0, N - 1));
    }
}