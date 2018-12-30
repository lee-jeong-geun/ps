#include <cstdio>
#include <iostream>
using namespace std;
int N, K;
long long result;

/*
B를 고정으로 잡고 A를 1부터 N까지 증가 시키면서 A % B를 수행하면
0 ~ B-1의 값들이 반복해서 나오게 된다. 이러한 반복 구간들이 몇번 나오는지 찾고
그러한 구간에서 K이상인 값이 몇개가 나오는것은 쉽게 찾을 수 있다.
N을 B로 나눴을때 몫이 구간의 개수가 되고 한개의 구간에서 K이상인 값들의 개수는
B - K가 된다. N을 B로 나눴을때 나머지는 한개의 구간이 짤렸다는것을 의미한다.
따라서 짤린 구간에서 K이상인 값들이 몇개 나오는지 찾으면 총 개수를 구할 수 있다.
*/

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++)
    {
        //K이상인 나머지가 존재 할 경우
        if(i - K >= 0)
        {
            int temp;
            //N / i개의 구간이 존재하고 i - K개의 K이상 나머지가 존재
            result += (N / i) * (i - K);
            //짤린 구간이 어디 까지 짤렸는지 확인
            temp = N % i + 1 - K;
            //짤린 구간에서 K이상인 나머지가 존재
            if(temp > 0)
            {
                result += temp;
            }
        }
    }
    //temp = N % i + 1 - K <--- 이 식의 예외 처리
    if(K == 0)
    {
        result -= N;
    }
    printf("%lld", result);
}