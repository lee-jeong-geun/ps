#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, memo[5][50005], Sum[50005];

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        int train;
        scanf("%d", &train);
        Sum[i] = Sum[i - 1] + train;
    }
    scanf("%d", &M);
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= N - M + 1; j++)
        {
            if(i == 1)
            {
                memo[i][j] = max(memo[i][j - 1], Sum[j + M - 1] - Sum[j - 1]);
            }
            if(j - M >= 1)
            {
                memo[i][j] = max(memo[i][j - 1], memo[i - 1][j - M] + Sum[j + M - 1] - Sum[j - 1]);
            }
        }
    }
    printf("%d", memo[3][N - M + 1]);
}