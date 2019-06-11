#include <bits/stdc++.h>
using namespace std;
int n;
long long result;

/*
2의 n / 2승을 하면된다.
*/

int main()
{
    scanf("%d", &n);
    if(n % 2 == 0)
    {
        result = pow(2, n / 2);
    }
    printf("%lld", result);
}