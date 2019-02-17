#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, Num[50005], result, hap;

/*
수2개를 고르고 큰수의 약수를 큰수에서 나누고 작은 수에 곱해서 전체 수들의 합을 최소화 시켜야 한다.
전체중에서 제일 작은수에 곱하는게 수들의 합이 최소가 된다.
따라서 모든 수들의 모든 약수를 나누고 제일 작은수에 곱하면서 합이 최소가 되는것을 찾으면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Num[i]);
        result += Num[i];
        hap = result;
    }
    sort(Num, Num + n);
    for(int i = n; i >= 1; i--)
    {
        int Sqrt;
        Sqrt = sqrt(Num[i]);
        for(int j = 2; j <= Sqrt; j++)
        {
            //약수
            if(Num[i] % j == 0)
            {
                //기존의 합이랑 나누고 곱한 후 합이랑 비교
                result = min(result, hap - Num[0] - Num[i] + Num[0] * j + Num[i] / j);
            }
        }
    }   
    printf("%d", result);
}