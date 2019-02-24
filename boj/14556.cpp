#include <cstdio>
#include <iostream>
using namespace std;
int N, Num[10] = {0, 1, 3, 15, 105, 945}, Mod = 1000000009;
long long result = 945;

/*
규칙을 잘 찾으면 1, 3, 15, 105, 945 이후로 앞의 수에서 (2 * i - 1)을 곱하면 된다.
*/

int main()
{
    scanf("%d", &N);
    if(N < 6)
    {
        result = Num[N];
    }
    for(int i = 6; i <= N; i++)
    {
        result = (result * (2 * i - 1)) % Mod;
    }
    printf("%lld", result);
}