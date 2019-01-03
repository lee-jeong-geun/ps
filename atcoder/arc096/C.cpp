#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int A, B, C, X, Y, result;

/*
3가지의 경우로 나눠서 풀면 된다.
A + B <= 2 * C인 경우는 어떻게 하든 C로 구입하는게 손해라서 A, B로만 구입하면 된다.
A + B > 2 * C인 경우는 C로 다 구입 하거나 개수가 작은 피자 까지만 C로 구입 하고
나머지는 따로 구입하는 것이다.
*/

int main()
{
    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
    if(A + B <= 2 * C)
    {
        result = A * X + B * Y;
    }
    else
    {
        //C로만 구입
        result = max(X, Y) * 2 * C;
        //C로 개수가 작은것 까지만 구입하고 나머지는 개별로 구입
        if(X > Y)
        {
            result = min(result, Y * 2 * C + (X - Y) * A);
        }
        else
        {
            result = min(result, X * 2 * C + (Y - X) * B);
        }
    }
    printf("%d", result);
}