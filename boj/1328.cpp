#include <bits/stdc++.h>
using namespace std;
int N, L, R, Mod = 1000000007;
long long memo[105][105][105];

/*
완전탐색을 하는것은 경우의 수가 100!이 나오기 때문에 안된다.
N개의 건물을 배치하는 방법은 1~N-1까지 건물을 배치한 상태에서 전부 1을 올리고 
높이 1인 건물을 양쪽 끝이랑 건물 사이 사이에 배치하는 것이다. 이때 잘 보면
왼쪽 끝에 배치하면 L이 하나 증가하게 되고 오른쪽 끝에 배치하면 R이 하나 증가하게 된다.
건물 사이에 배치하는 것은 L, R에 영향이 없다. 따라서 dp[N][L][R] = dp[N - 1][L - 1][R]
+ dp[N - 1][L][R - 1] + dp[N - 1][L][R] * (N - 2)가 된다.
*/

long long func(int depth, int left, int right)
{
    if(depth <= 1)
    {
        if(left == 1 && right == 1)
            return 1;
        return 0;
    }
    if(left == 0 || right == 0)
        return 0;
    long long &ret = memo[depth][left][right];
    if(ret != -1)
        return ret;
    ret = 0;
    ret = (ret + func(depth - 1, left - 1, right)) % Mod;
    ret = (ret + func(depth - 1, left, right - 1)) % Mod;
    ret = (ret + func(depth - 1, left, right) * (depth - 2)) % Mod;
    return ret;
}

int main()
{
    scanf("%d %d %d", &N, &L, &R);
    memset(memo, -1, sizeof memo);
    printf("%lld", func(N, L, R));
    
}