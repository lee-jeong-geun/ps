#include <cstdio>
#include <iostream>
using namespace std;
int A, B;
long long g;

long long gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    gcd(b, a % b);
}

int main()
{
    scanf("%d %d", &A, &B);
    g = gcd(A, B);
    printf("%ld", (long long)A * B / g);
}