#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long N, a, Min, result;

/*
사람들을 이동 시킬 때 가장 시간이 많이 걸리는 부분은 수용량이 가장 작은 이동 수단 부분이다.
그 이유는 가장 큰 이동수단으로 많이 이동 시켜도 가장 작은 이동 수단에서 막히기 때문이다.
가장 작은 이동수단을 찾고 사람들이 이동되는 시간 4를 더해주면 된다.
*/

int main()
{
    scanf("%lld %lld", &N, &Min);
    for(int i = 0; i < 4; i++)
    {
        scanf("%lld", &a);
        Min = min(Min, a);
    }
    int temp = 0;
    if(N % Min != 0)
    {
        temp = 1;
    }
    printf("%lld", N / Min + 4 + temp);
}