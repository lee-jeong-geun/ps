#include <bits/stdc++.h>
using namespace std;
int N, M, arrA[105], arrC[105], memo[105][10005];

/*
단순하게 생각하면 dp[N][M] = min(dp[N][M], f(N + 1, M + A[N]) + C[N])의 점화식이 나오지만
N은 최대 10^2이고 M은 최대 10^7이므로 메모리와 시간은 제한을 초과하게 된다. 다른 점화식을 찾아야 한다.
잘보면 N은 10^2이고 N * C = 최대 10^4이므로 총 10^6밖에 안되므로 메모리와 시간은 충분하게 된다.
점화식은 dp[N][C] = max(dp[N][C], f(N + 1, C + C[i]) + A[i])가 나오게 되고 M이상인 값중
C가 가장 작은것을 고르면 된다.
*/

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arrA[i]);
    }
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arrC[i]);
    }
    memo[0][arrC[0]] = arrA[0];
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j <= 10000; j++)
        {
            //memo[i - 1][j] == i번째를 선택하지 않은 값중 최대
            //memo[i - 1][j - arrC[i]] + arrA[i] == i번째를 선택한 값
            memo[i][j] = memo[i - 1][j];
            if(j - arrC[i] >= 0)
                memo[i][j] = max(memo[i][j], memo[i - 1][j - arrC[i]] + arrA[i]);
        }
    }
    for(int i = 0; i <= 10000; i++)
    {
        if(memo[N - 1][i] >= M)
        {
            printf("%d", i);
            break;
        }
    }
}