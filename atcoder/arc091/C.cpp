#include <cstdio>
#include <iostream>
using namespace std;
int N, M;

/*
규칙을 계속 찾아보면 주위의 사각형들이 짝수면 그대로고 홀수면 뒤집어 진다.
*/

long long _abs(long long num)
{
    return num > 0 ? num : num * -1;
}

int main()
{
    scanf("%d %d", &N, &M);
    printf("%lld", _abs((long long)(N - 2) * (M - 2)));
}