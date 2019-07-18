#include <bits/stdc++.h>
using namespace std;
int n, arr[3][100005];
long long result, memo[3][100005];

/*
규칙을 잘 보면 (1, 1)의 값의 최대값은 max((2, 2), (2, 3)) + (1, 1)이 된다.
(2, 2)의 최대값도 max((1, 3), (1, 4)) + (2, 2)가 된다. 이러한 규칙을 이용하여
메모이제이션을 해서 빠르게 최대값을 구하면 된다.
*/

long long func(int R, int C)
{
    if(C >= n)
        return 0;
    long long &ret = memo[R][C];
    if(ret != -1)
        return ret;
    ret = 0;
    ret = max(ret, func(R ^ 1, C + 1) + arr[R][C]);
    ret = max(ret, func(R ^ 1, C + 2) + arr[R][C]);
    return ret;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[0][i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[1][i]);
    }
    memset(memo, -1, sizeof memo);
    for(int i = 0; i < min(2, n); i++)
    {
        result = max(result, func(0, i));
        result = max(result, func(1, i));
    }
    printf("%lld", result);
}