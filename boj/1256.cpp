#include <bits/stdc++.h>
using namespace std;
int N, M;
long long K, memo[205][205], Count;

/*
10억개의 순서를 전부 확인 할 수 없으니 가지치기 방법을 이용해야 한다.
a와 z를 조합했을때 전체 조합의 개수는 N+M C N이다.
a를 하나 썼을때 나올수 있는 조합의 개수는 N-1+M C N-1이다.
a를 하나 썼을때 나올수 있는 조합의 개수가 K보다 작다면 a가 아닌 z를 써야 한다.
그게 아닌 경우 a를 써야 한다. 이러한 방법으로 K번째가 되도록 a, z를 계속해서 선택해주면 된다.
*/

int main()
{
    scanf("%d %d %lld", &N, &M, &K);
    for(int i = 0; i <= 200; i++)
    {
        memo[i][0] = 1;
        for(int j = 1; j <= i; j++)
        {
            if(memo[i - 1][j - 1] + memo[i - 1][j] <= 12345678901)
                memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j];
            else
                memo[i][j] = 12345678900;
        }
    }
    if(memo[N + M][N] < K)
    {
        printf("-1");
        return 0;
    }
    while(N != 0 || M != 0)
    {
        //지금까지 가지친 개수 + a를 썼을때 조합의 개수가 K보다 작으면 z를 선택
        if(N == 0 || Count + memo[N + M - 1][N - 1] < K)
        {
            printf("z");
            Count += memo[N + M - 1][N - 1];
            M--;
        }
        else
        {
            printf("a");
            N--;
        }
    }
}