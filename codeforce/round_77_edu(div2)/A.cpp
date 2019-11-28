#include <bits/stdc++.h>
using namespace std;
int n, c, sum, result;

/*
c1 + c2 + c3.... = sum일때 c1^2 + c2^2 + c3^2.... 의 최소값은 구하기 위해서는
c1, c2, c3...에 최대한 차이가 덜나는 수들을 할당 하면 된다
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        result = 0;
        scanf("%d %d", &c, &sum);
        if(c >= sum)
            result = sum;
        else
        {
            int temp;
            temp = sum /c;
            result = temp * temp * c;
            if(sum % c != 0)
                result += (sum % c) * (temp * 2 + 1);
        }
        printf("%d\n", result);
    }
}