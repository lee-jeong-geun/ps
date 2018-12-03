#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, K, B, arr[100005], Sum[100005], result = 987654321;

/*
누적합을 이용해 각 구간중에서 고장난 신호등이 가장 작은 구간을 찾으면 된다.
*/

int main()
{
    scanf("%d %d %d", &N, &K, &B);
    for(int i = 0; i < B; i++)
    {
        int num;
        scanf("%d", &num);
        arr[num] = 1;
    }
    for(int i = 1; i <= N; i++)
    {
        Sum[i] = Sum[i - 1] + arr[i];
    }
    for(int i = K; i <= N; i++)
    {
        result = min(result, Sum[i] - Sum[i - K]);
    }
    printf("%d", result);
}