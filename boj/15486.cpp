#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, T[1500005], P[1500005], memo[1500095];

/*
i번째 일을 잡으면 그 일이 끝나기 전까지 어떤 일도 할 수 없다.
i번째 일을 하면 i + T[i]에 그 값을 저장하면 된다.
i + 1번째 일도 i + 1 + T[i + 1]에 그 값을 저장하면 된다.
그리고 i번째까지 받을 수 있는 최대 금액은 memo[i]에 저장 되어있다.
따라서 점화식은 memo[i + T[i]] = max(memo[i + T[i]], memo[i] + P[i])가 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d %d", &T[i], &P[i]);
        //i번째 까지 모을 수 있는 최대 금액
        memo[i] = max(memo[i], memo[i - 1]);
        memo[i + T[i]] = max(memo[i + T[i]], memo[i] + P[i]);
    }
    printf("%d", max(memo[N], memo[N + 1]));
}