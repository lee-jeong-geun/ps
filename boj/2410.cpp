#include <cstdio>
#include <iostream>
using namespace std;
int N, memo[1000005], Mod = 1000000000;

int main()
{
    scanf("%d", &N);
    memo[0] = 1;
    for(int i = 0; i < 20; i++)
    {
        for(int j = (1 << i); j <= N; j++)
        {
            memo[j] = (memo[j] + memo[j - (1 << i)]) % Mod;
        }
    }
    printf("%d", memo[N] % Mod);
}