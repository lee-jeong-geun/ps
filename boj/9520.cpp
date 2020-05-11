#include <bits/stdc++.h>
using namespace std;
int N, zone[1505][1505], memo[1505][1505];

/*
도시를 추가하는 규칙을 잘 보면 항상 오른쪽 아니면 왼쪽에 추가된다.
예를 들어 1번 도시에서 2번 도시를 가는 경우는 1, 2 or 2, 1이 된다.
3번 도시를 가는 경우는 (1, 2, 3) or (3, 1, 2) or (2, 1, 3) or (3, 2, 1)이 된다.
즉 i번까지 도시를 이동했고 i+1번 도시를 가는 경우는 (left, i+1) or (i+1, right)가 된다.
이러한 규칙을 이용하면 dp[left][right] = min(dp[left][i + 1] + (right, i + 1),
 dp[i + 1][right] + (i + 1, left))의 점화식이 나오게 된다.
*/

int func(int left, int right)
{
    int maxNode = max(left, right);
    if(maxNode == N - 1)
        return 0;
    int &ret = memo[left][right];
    if(ret != -1)
        return ret;
    ret = 987654321;
    ret = min(ret, func(left, maxNode + 1) + zone[right][maxNode + 1]);
    ret = min(ret, func(maxNode + 1, right) + zone[maxNode + 1][left]);
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &zone[i][j]);
        }
    }
    memset(memo, -1, sizeof memo);
    printf("%d", func(0, 0));
}