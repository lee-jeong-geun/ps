#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int X, Y, N;
double result;

/*
주어진 조건에 맞게 구현하면 된다.
*/

int main()
{
    scanf("%d %d %d", &X, &Y, &N);
    result = (double)1000 / Y * X;
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &X, &Y);
        result = min(result, (double)1000 / Y * X);
    }
    printf("%0.2lf", result);
}