#include <cstdio>
#include <iostream>
using namespace std;
int N, K, prime[100005], resultNum[100005], result;

/*
에라토스테네스 체 방식을 이용하면 된다.
K-세준수가 아닌 수들은 K보다 큰 소수와 그 배수들이다.
따라서 N까지의 소수들을 구하면서 K보다 큰 소수와 그 배수들을 제거해 주면
K-세준수를 구할 수 있다.
*/

int main()
{
    scanf("%d %d", &N, &K);
    result = N;
    //N까지 소수 구함
    for(int i = 2; i <= N; i++)
    {
        if(prime[i] == 0)
        {
            for(int j = i + i; j <= N; j += i)
            {
                //K보다 크면서 그의 배수일 경우
                if(i > K && resultNum[j] == 0)
                {
                    resultNum[j] = 1;
                    result--;
                }
                prime[j] = 1;
            }
            //K보다 큰 소수일 경우
            if(i > K)
            {
                result--;
            }
        }
    }
    printf("%d", result);
}