#include <bits/stdc++.h>
using namespace std;
int q;
long long n, result;

/*
n이 1이 될때까지 주어진 연산들을 하면된다.
*/

int main()
{
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        result = 0;
        scanf("%lld", &n);
        while(n != 1)
        {
            if(n % 2 == 0)
                n /= 2;
            else if(n % 3 == 0)
                n = n * 2 / 3;
            else if(n % 5 == 0)
                n = n * 4 / 5;
            else
            {
                result = -1;
                break;
            }
            result++;
        }
        printf("%lld\n", result);
    }
}