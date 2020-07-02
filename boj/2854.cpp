#include <bits/stdc++.h>
using namespace std;
int N, arrA[100005], arrB[100005], Mod = 1000000007;
long long memo[100005][2];

/*
난이도가 i일 때 난이도가 한 개인 문제를 골랐다면 i+1일 때 고를 수 있는 문제는
난이도가 i+1이면서 한 개인 문제 or 난이도가 i+1이면서 두 개인 문제 or 난이도가 i면서 두 개인 문제를 고를 수 있다.
난이도가 i일 때 난이도가 두 개인 문제를 골랐다면 i+1일 때 고를 수 있는 문제는
난이도가 i+1이면서 한 개인 문제 or 난이도가 i+1이면서 두 개인 문제 or 난이도가 i면서 두 개인 문제 -1을 고를 수 있다.
이런 식으로 점화식으로 만들어서 해결하면 된다.
*/

long long func(int depth, int flag)
{
    if(depth == N + 1)
        return 1;
    long long &ret = memo[depth][flag];
    if(ret != -1)
        return ret;
    ret = 0;
    ret += (func(depth + 1, 0) * arrA[depth]) % Mod;
    ret += (func(depth + 1, 1) * arrB[depth]) % Mod;
    if(flag == 1 && arrB[depth - 1] - 1 > 0)
        ret += (func(depth + 1, 0) * (arrB[depth - 1] - 1)) % Mod;
    else if(flag == 0)
        ret += (func(depth + 1, 0) * arrB[depth - 1]) % Mod;
    return ret % Mod;
}

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &arrA[i]);
    }
    for(int i = 1; i <= N - 1; i++)
    {
        scanf("%d", &arrB[i]);
    }
    memset(memo, -1, sizeof memo);
    printf("%d", func(1, 0) % Mod);
}