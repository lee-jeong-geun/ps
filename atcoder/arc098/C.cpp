#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, eSum[300005], wSum[300005], result = 987654321;

/*
하나의 인덱스 양옆에 E개수와 W개수를 파악하면 된다.
*/

int main()
{
    scanf("%d ", &N);
    for(int i = 1; i <= N; i++)
    {
        char c;
        scanf("%c", &c);
        eSum[i] = eSum[i - 1];
        wSum[i] = wSum[i - 1];
        if(c == 'E')
        {
            eSum[i]++;
        }
        if(c == 'W')
        {
            wSum[i]++;
        }
    }
    for(int i = 1; i <= N; i++)
    {
        result = min(result, eSum[N] - eSum[i] + wSum[i - 1] - wSum[0]);
    }
    printf("%d", result);
}