#include <cstdio>
#include <iostream>
using namespace std;
long long X, Y;
int result;

/*
X를 Y이하라면 왼쪽으로 계속 쉬프트하면서 쉬프트 횟수를 카운트 하면 된다.
*/

int main()
{
    scanf("%lld %lld", &X, &Y);
    while(X <= Y)
    {
        X = X << 1;
        result++;
    }
    printf("%d", result);
}