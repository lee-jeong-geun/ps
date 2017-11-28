#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int A, B, Min = 987654321, resultA, resultB;

int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    gcd(b, a % b);
}

int main()
{
    int temp;
    scanf("%d %d", &A, &B);
    temp = B;
    for(int i = A; i <= temp; i += A)
    {
        if((long long)A * B % i == 0)
        {
            temp = (long long)A * B / i;
            if(gcd(i, temp) == A && Min > i + temp)
            {
                Min = i + temp;
                resultA = i;
                resultB = temp;
            }
        }
    }
    printf("%d %d", min(resultA, resultB), max(resultA, resultB));
}