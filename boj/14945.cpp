#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n, memo[105][105][105];

int func(int depth, int kx, int mx)
{
    if(depth == n - 1)
    {
        return 1;
    }
    int &ret = memo[depth][kx][mx];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    if(kx != mx)
    {
        ret += func(depth + 1, kx, mx) % 10007;
        ret += func(depth + 1, kx + 1, mx + 1) % 10007;
    }
    if(kx + 1 != mx)
    {
        ret += func(depth + 1, kx + 1, mx) % 10007;
    }
    if(mx + 1 != kx)
    {
        ret += func(depth + 1, kx, mx + 1) % 10007;
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    memset(memo, -1, sizeof memo);
    printf("%d", func(0, 0, 0) % 10007);
}