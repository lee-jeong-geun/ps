#include <bits/stdc++.h>
using namespace std;
int result;
long long n;

/*
1, 11, 111, 1111
2, 22, 222, 2222 이것처럼 하나씩 계속 추가 시키면서 n이하라면 카운트 해준다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        result = 0;
        scanf("%lld", &n);
        for(int i = 1; i < 10; i++)
        {
            long long num;
            num = i;
            while(num <= n)
            {
                result++;
                num *= 10;
                num += i;
            }
        }
        printf("%d\n", result);
    }
}