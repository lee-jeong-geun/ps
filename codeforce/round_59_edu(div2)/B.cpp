#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;

/*
프로세스를 계속 돌렸을때 x가 나오는 n번째 수를 찾는 것이다.
1부터 9까지 9가 차이나고 거기에 x를 더하면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        long long k;
        int x;
        scanf("%lld %d", &k, &x);
        if(k == 1)
        {
            printf("%d\n", x);
            continue;
        }
        printf("%lld\n", (k - 1) * 9 + x);
    }
}