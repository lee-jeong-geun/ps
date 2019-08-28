#include <bits/stdc++.h>
using namespace std;
long long result;

/*
전부 더하고 2로 나누면 된다.
*/

int main()
{
    int q;
    scanf("%d", &q);
    for(int tc = 0; tc < q; tc++)
    {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        result = (a + b + c) / 2;
        printf("%lld\n", result);
    }
}