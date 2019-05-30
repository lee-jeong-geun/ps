#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int N, memo[105][6][6][6];

/*
완전탐색을 하기에는 4 ^ 100 이라서 시간 초과가 나게 된다.
ACG, AGC, GAC 같이 연결된 경우와 A*GC, AG*C와 같이 한번 바꿀수 있는 경우를 처리해주면서
dp[현재 인덱스][앞 문자][앞앞 문자][앞앞앞 문자]에 값을 저장 하면 된다.
*/

int func(int idx, int before, int bbfore, int bbbfore)
{
    if(idx == N)
    {
        return 1;
    }
    int &ret = memo[idx][before][bbfore][bbbfore];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    for(int i = 1; i <= 4; i++)
    {
        //나오면 안되는 조건들
        if(i == 2 && ((before == 1 && bbfore == 3) || (before == 3 && bbfore == 1)))
        {
            continue;
        }
        if(i == 3 && before == 2 && bbfore == 1)
        {
            continue;
        }
        if(i == 2 && ((before == 3 && bbbfore == 1) || (bbfore == 3 && bbbfore == 1)))
        {
            continue;
        }
        ret = (ret + func(idx + 1, i, before, bbfore)) % 1000000007;
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    memset(memo, -1, sizeof memo);
    printf("%d\n", func(0, 0, 0, 0));
}