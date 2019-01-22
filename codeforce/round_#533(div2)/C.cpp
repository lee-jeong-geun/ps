#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n, l, r, Sum[5], Mod = 1000000007;
long long memo[3][200005];

/*
수들의 합이 3으로 나누어 떨어져야 한다. 고로 모든 수들의 나머지 합이 0이 되어야 한다.
l부터 r까지 모든 수를 탐색할 필요 없이 나머지가 몇개 나오는지 파악 하면 된다.
나머지는 0, 1, 2 이렇게 나오는데 l부터 r까지 모든 나머지가 0, 1, 2, 0, 1, 2이런식으로 반복이
되기 때문에 구간이 몇개 나오는지 (r - l + 1) / 3을 통하여 확인 후 이제 완전하지 못한 구간에서
나머지가 어떤게 있는지 파악 하고 더해주면 된다.
그리고 dp[현재 까지 나머지][인덱스]로 메모이제이션 하면서 탐색하면 된다.
*/

long long func(int m, int depth)
{
    if(depth == n)
    {
        //n개의 합의 나머지가 0인 경우
        if(m == 0)
        {
            return 1;
        }
        return 0;
    }
    long long &ret = memo[m][depth];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    for(int i = 0; i < 3; i++)
    {
        //나머지가 i인 수들의 개수를 곱함
        ret = (ret + func((m + i) % 3, depth + 1) * Sum[i]) % Mod;
    }
    return ret;
}

int main()
{
    scanf("%d %d %d", &n, &l, &r);
    int div;
    //구간 개수
    div = (r - l + 1) / 3;
    for(int i = 0; i < 3; i++)
    {
        Sum[i] = div;
    }
    //온전하지 못한 구간 확인
    for(int i = l + div * 3; i <= r; i++)
    {
        Sum[i % 3]++;
    }
    memset(memo, -1, sizeof memo);
    printf("%d", func(0, 0));
}