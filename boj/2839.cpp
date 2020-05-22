#include <bits/stdc++.h>
using namespace std;
int N, arr[5] = {3, 5}, memo[5005];

/*
3과 5를 이용하여 메모이제이션 하면 된다.
*/

int main()
{
    scanf("%d", &N);
    memset(memo, 0x3f, sizeof memo);
    memo[0] = 0;
    for(int i = 0; i < 2; i++)
    {
        for(int j = arr[i]; j <= N; j++)
        {
            memo[j] = min(memo[j], memo[j - arr[i]] + 1);
        }
    }
    if(memo[N] > 987654321)
        memo[N] = -1;
    printf("%d", memo[N]);
}