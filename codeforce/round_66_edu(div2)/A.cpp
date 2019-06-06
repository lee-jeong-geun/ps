#include <cstdio>
#include <iostream>
using namespace std;
long long n, k, result;

/*
수가 크니까 하나씩 나눠가면서 하면 시간 초과 난다.
나누어 떨어지지 않는 경우는 단순하게 나머지를 더하고 나누어 떨어지면 나누면 된다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%lld %lld", &n, &k);
        result = 0;
        while(n != 0)
        {
            if(n % k == 0)
            {
                n /= k;
                result++;
            }
            else
            {
                //나머지 더함
                result += n % k;
                n = n - (n % k);
            }
        }
        printf("%lld\n", result);
    }
}