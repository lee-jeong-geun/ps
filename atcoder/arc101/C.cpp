#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, K, Num[100005];
long long rightSum[100005], leftSum[100005], result = (long long) 1 << 62;

/*
양초를 켜는 최소의 시간은 연속으로 된 양초들을 켜는 것이다.
부분합을 이용하여 연속된 시간의 합들을 구하면 된다.
여기서 주의해야 할 점은 연속이 꼭 오른쪽으로만 연속이 아니고 기준점에서 왼쪽일수도 있다는 것이다.
따라서 왼쪽 오른쪽 부분합을 구하여 최소를 구하면 된다.
*/

int abs(int num)
{
    return num > 0 ? num : -num;
}

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &Num[i]);
        //오른쪽으로 연속인 부분합
        if(i > 1)
        {
            rightSum[i] = rightSum[i - 1] + abs(Num[i] - Num[i - 1]);
        }
    }
    //왼쪽으로 연속인 부분합
    for(int i = N - 1; i >= 1; i--)
    {
        leftSum[i] = leftSum[i + 1] + abs(Num[i] - Num[i + 1]);
    }
    //최소 시간 구하기
    for(int i = 1; i <= N - K + 1; i++)
    {
        result = min(result, rightSum[i + K - 1] - rightSum[i] + abs(Num[i]));
    }
    for(int i = N; i >= K; i--)
    {
        result = min(result, leftSum[i - K + 1] - leftSum[i] + abs(Num[i]));
    }
    printf("%lld", result);
}