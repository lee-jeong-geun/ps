#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, K, D[100005], Sum[100005], chk[100005], result2, memo[100005], Prev[100005];
long long result1;

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
		memset(chk, 0, sizeof chk);
		memset(Sum, 0, sizeof Sum);
		memset(memo, 0, sizeof memo);
		memset(Prev, -1, sizeof Prev);
		result1 = 0;
		result2 = 0;
        scanf("%d %d", &N, &K);
		chk[0] = 1;
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &D[i]);
			Sum[i] = (Sum[i - 1] + D[i]) % K;
			chk[Sum[i]]++;
        }
		for(int i = 0; i < K; i++)
		{
			long long temp;
			if(chk[i] >= 2)
			{
				temp = (long long)chk[i] * (chk[i] - 1) / 2;
				result1 = (result1 + temp) % 20091101;
			}
		}
		Prev[0] = 0;
		for(int i = 1; i <= N; i++)
		{
			if(Prev[Sum[i]] == -1)
			{
				memo[i] = memo[i - 1];
			}
			else
			{
				memo[i] = max(memo[i - 1], memo[Prev[Sum[i]]] + 1);
			}
			Prev[Sum[i]] = i;
		}
		result2 = memo[N];
		printf("%lld %d\n", result1, result2);
    }
}