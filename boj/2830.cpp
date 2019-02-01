#include <cstdio>
#include <iostream>
using namespace std;
int N, chk[30];
long long result;

/*
모든 수들의 비트들을 카운트 하여 배열에 저장 한다.
그리고 각각의 비트들의 XOR 값을 결과에 저장 한다.
해당 비트의 1의 개수 * 0의 개수 * (1 << 해당 비트) 만큼 결과에 저장 하면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        for(int j = 0; j < 20; j++)
        {
            //비트의 개수를 배열에 저장
            if((num & (1 << j)) != 0)
            {
                chk[j]++;
            }
        }
    }
    for(int i = 0; i < 20; i++)
    {
        result += (long long)chk[i] * (N - chk[i]) * (1 << i);
    }
    printf("%lld", result);
}