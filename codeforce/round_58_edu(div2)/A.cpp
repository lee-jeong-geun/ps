#include <cstdio>
#include <iostream>
using namespace std;
int q, result;

/*
두개의 경우로 나눠서 생각 할 수 있다.
우선 d가 범위에 포함이 되지 않는 경우이다. 그때는 d가 된다. 
d의 배수중 가장 작은 배수를 찾는것이기 때문에 저 범위를 제외 하고는 d가 된다.
이제 d가 l <= d <= r이 되는 경우이다.
이때는 r보다 큰 배수를 찾아야 하는데 r이하의 배수중 가장 큰 배수는
r / d를 할때 나오는 몫에다 d를 곱할 때이다. 여기다 d를 더하면 r보다 큰 d의 배수중 가장 작은 배수가 된다.

*/

int main()
{
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        result = 0;
        int l, r, d;
        scanf("%d %d %d", &l, &r, &d);
        if(d < l || r < d)
        {
            result = d;
        }
        else
        {
            result = r / d * d + d;
        }
        printf("%d\n", result);
    }
}