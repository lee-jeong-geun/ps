#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int A, B, C, memo[105][105][105];

/*
연산들을 이용하여 세수를 같게 만들때 가장 최소연산을 구해야한다.
dp[a][b][c] = min(dp[a][b][c], 연산 + 1)의 점화식으로 재귀 함수를 돌리면 된다.
*/

int func(int a, int b, int c)
{
    //기저사례
    if(a > 100 || b > 100 || c > 100)
    {
        return 1005;
    }
    if(a == b && a == c)
    {
        return 0;
    }
    int &ret = memo[a][b][c];
    if(ret != -1)
    {
        return ret;
    }
    ret = 987654321;
    ret = min(ret, func(a + 1, b + 1, c) + 1);
    ret = min(ret, func(a + 1, b, c + 1) + 1);
    ret = min(ret, func(a, b + 1, c + 1) + 1);
    ret = min(ret, func(a + 2, b, c) + 1);
    ret = min(ret, func(a, b + 2, c) + 1);
    ret = min(ret, func(a, b, c + 2) + 1);
    return ret;
}

int main()
{
    scanf("%d %d %d", &A, &B, &C);
    memset(memo, -1, sizeof memo);
    printf("%d", func(A, B, C));
}