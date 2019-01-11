#include <cstdio>
#include <iostream>
using namespace std;
long long result;
int n;

/*
1부터 n까지 다 더한 값을 2로 나누었을때 나머지가 0이면 0 1이면 1이다.
*/

int _abs(long long num)
{
    return num > 0 ? num : -num;
}

int main()
{
    scanf("%d", &n);
    result = (long long)n * (n + 1) / 2;
    printf("%d", _abs(result / 2 - result / 2 + result % 2));
}