#include <bits/stdc++.h>
using namespace std;
int N, K, zone[1005][5];
long long memo[1001][1001][8];

/*
완전 탐색을 하면 시간이 오래 걸리므로 dp[행][K][이전 행 상태]의 점화식을 이용하여
답을 구하면 된다. 그리고 도미노를 최대한 많이 둬야 한다. N이 짝 수라면 2행 마다
도미노 3개를 둘 수 있다. 홀 수라면 짝 수만큼 다 두고 마지막 행 하나에 대해 도미노 1개를 둘 수 있다.
따라서 둘 수 있는 최대 도미노는 min(K, N / 2 * 3 + N % 2)가 된다.
*/

long long func(int depth, int count, int state)
{
    if(depth == N + 1)
    {
        if(count < K)
            return (long long)-123456789123456;
        return 0;
    }
    long long &ret = memo[depth][count][state];
    if(ret != -1)
        return ret;
    ret = (long long)-123456789123456;
    int bit[5] = {0}, choice[5] = {0}, Sum[5] = {0};
    for(int i = 0; i < 3; i++)
    {
        choice[0] = 0;
        Sum[0] = 0;
        bit[0] = 0;
        if(i == 2 && (state & (1 << 2)) != 0)
            continue;
        if(i > 0)
        {
            choice[0] = 1;
            if(i == 1)
            {
                bit[0] = 6;
                Sum[0] = zone[depth][0] + zone[depth][1];
            }
            else
            {
                bit[0] = 4;
                Sum[0] = zone[depth][0] + zone[depth - 1][0];
            }
        }
        for(int j = 0; j < 3; j++)
        {
            choice[1] = 0;
            Sum[1] = 0;
            bit[1] = 0;
            if(j > 0)
            {
                if(i == 1)
                    break;
                if(j == 2 && (state & (1 << 1)) != 0)
                    continue;
                choice[1] = 1;
                if(j == 1)
                {
                    bit[1] = 3;
                    Sum[1] = zone[depth][1] + zone[depth][2];
                }
                else
                {
                    bit[1] = 2;
                    Sum[1] = zone[depth][1] + zone[depth - 1][1];
                }
            }
            for(int k = 0; k < 3; k++)
            {
                if(j == 1 && k > 0)
                    break;
                if(k == 1 || k == 2 && (state & 1) != 0)
                    continue;
                if(depth == 1 && (i == 2 || j == 2 || k == 2))
                    continue;
                choice[2] = 0;
                Sum[2] = 0;
                bit[2] = 0;
                if(k > 0)
                {
                    choice[2] = 1;
                    bit[2] = 1;
                    Sum[2] = zone[depth][2] + zone[depth - 1][2];
                }
                if(count + choice[0] + choice[1] + choice[2] > K)
                    continue;
                ret = max(ret, func(depth + 1, count + choice[0] + choice[1] + choice[2], bit[0] | bit[1] | bit[2]) + Sum[0] + Sum[1] + Sum[2]);
            }
        }
    }
    return ret;
}

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &zone[i][j]);
        }
    }
    K = min(K, N / 2 * 3 + N % 2);
    memset(memo, -1, sizeof memo);
    printf("%lld", func(1, 0, 0));
}