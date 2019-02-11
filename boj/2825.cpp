#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int N, bitCount[1030];
long long result;

/*
단순하게 O(N^2)의 복잡도로 모든 쌍을 구하지 못하므로 0 ~ 9를 각각의 비트로 대조 시킨 후 개수를 저장한다.
그러면 최대 1023개의 수들이 나오게 되는데 1023은 완전탐색으로 충분히 쌍을 찾을 수 있으므로 찾으면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        long long num;
        int temp = 0;
        scanf("%lld", &num);
        while(num)
        {
            //0 ~ 9를 비트로 만들고 OR연산 시킴
            temp |= (1 << (num % 10));
            num /= 10;
        }
        bitCount[temp]++;
    }
    for(int i = 1; i <= 1023; i++)
    {
        for(int j = i + 1; j <= 1023; j++)
        {
            //두 수를 &연산 시켰을때 0이 아니라면 친구 관계
            if((i & j) != 0)
            {
                result += (long long)bitCount[i] * bitCount[j];
            }
        }
    }
    for(int i = 1; i <= 1023; i++)
    {
        //두 수가 같은 경우
        result += (long long)bitCount[i] * (bitCount[i] - 1) / 2;
    }
    printf("%lld", result);
}