#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, K, walkTime[105], walkMoney[105], biTime[105], biMoney[105], memo[105][100005];

/*
완전탐색을 이용하면 2^100이라는 경우의 수가 나오므로 다른 방법을 선택해야 한다.
잘보면 K가 100000이므로 각각의 도시들을 선택했을때 소요한 시간이 어떤지를 테이블로 잡을 수 있다.
dp[도시][시간] = max(dp[다음도시][시간 + 도보 선택 시간] + 도보 선택 모금액, dp[다음도시][시간 + 자전거 선택 시간] + 자전거 선택 모금액)
이라는 점화식이 나오게 된다.
시간이 K를 초과 할 때가 있는데 이때는 나올수 없는 가장 최소값을 리턴해 주어야 한다.
그렇지 않으면 모든 도시를 다 돌았는지 아닌지 알 수 없기 때문에 값이 틀릴수가 있다.
*/

int func(int depth, int Time)
{
    int Max = -987654321;
    //마지막 도시일 경우
    if(depth == N)
    {
        return 0;
    }
    int &ret = memo[depth][Time];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    //도보 선택
    if(Time + walkTime[depth] <= K)
    {
        Max = func(depth + 1, Time + walkTime[depth]) + walkMoney[depth];
    }
    //자전거 선택
    if(Time + biTime[depth] <= K)
    {
        Max = max(Max, func(depth + 1, Time + biTime[depth]) + biMoney[depth]);
    }
    ret = Max;
    return ret;
}

int main()
{
    memset(memo, -1, sizeof memo);
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d %d %d", &walkTime[i], &walkMoney[i], &biTime[i], &biMoney[i]);
    }
    printf("%d", func(0, 0));
}