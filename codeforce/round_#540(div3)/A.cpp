#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/*
전부 1리터로 사는것과 2리터와 나머지 존재시 1리터를 사는것 2가지의 경우로 나눠서 생각하면 된다.
*/

int main()
{
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        long long n;
        int a, b;
        scanf("%lld %d %d", &n, &a, &b);
        printf("%lld\n", min(n / 2 * b + n % 2 * a, n * a));
    }
}