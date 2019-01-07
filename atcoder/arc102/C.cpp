#include <cstdio>
#include <iostream>
using namespace std;
int N, K;
long long result,  Count[200005];

/*
규칙을 잘 찾다 보면 b를 고정 시킬때 a와 c의 값은 K - b가 되는데
이때 a와 c를 더한 값에 K를 나눈 나머지의 값이 0이 되어야 a, b, c가 성립하게 된다.
그리고 이러한 값들이 구간을 이루어서 반복하게 되는데 이러한 구간은 K를 나눴을때 나올 수 있는
나머지들의 값으로 구간을 이루게 된다. 어떤 a와 c가 매칭 되는 것은 K의 나머지 구간에 하나씩만 존재
하게 된다. 즉 N을 K로 나눈 나머지 구간들마다 하나씩 밖에 존재하지 않는 것이다. 따라서 해당 구간이
몇개 나오는지 파악하고 구간이 딱 떨어지지 않는 나머지가 존재 할 시 그 나머지가 b보다 큰 경우
b가 포함 되므로 개수를 하나 늘려준다.
*/

int main()
{
    scanf("%d %d", &N, &K);
    if(K == 1)
    {
        result = (long long)N * N * N;
        printf("%lld", result);
        return 0;
    }
    for(int i = 1; i <= K; i++)
    {
        //b를 고정 시켰을때 나올수 있는 a와 c
        if((K - i) * 2 % K == 0)
        {
            long long temp;
            temp = N / K;
            //완전하지 않는 구간이 존재하는 경우
            if(N % K >= i)
            {
                temp++;
            }
            //순서쌍이므로 제곱
            Count[i] = temp * temp;
            result += Count[i];
        }
    }
    //해당 구간만큼 반복이 되므로 곱함
    result = result * (N / K);
    //나머지 구간은 개수를 따로 더함
    for(int i = 1; i <= N % K; i++)
    {
        result += Count[i];
    }
    printf("%lld",result);
}