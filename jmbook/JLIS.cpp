#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, memo[105][105];
long long A[105], B[105];

int func(int aidx, int bidx)
{
    int &ret = memo[aidx][bidx];
    if(ret != -1)
    {
        return ret;
    }
    ret = 1;
    long long Max = max(A[aidx], B[bidx]);
    for(int i = aidx + 1; i <= n; i++)
    {
        if(Max < A[i])
        {
            ret = max(ret, func(i, bidx) + 1);
        }
    }
    for(int i = bidx + 1; i <= m; i++)
    {
        if(Max < B[i])
        {
            ret = max(ret, func(aidx, i) + 1);
        }
    }
    return ret;
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        memset(memo, -1, sizeof memo);
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            scanf("%ld", &A[i]);
        }
        for(int i = 1; i <= m; i++)
        {
            scanf("%ld", &B[i]);
        }
        A[0] = -12345678900;
        B[0] = -12345678900;
        printf("%d\n", func(0, 0) - 1);
    }
}