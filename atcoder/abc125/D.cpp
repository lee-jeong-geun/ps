#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, arr[100005];
long long memo[2][100005];

/*
각각의 수들은 부호를 바꿨거나 안바꿨거나로 경우를 나눌 수 있다.
현재 인덱스에서 부호를 바꾸지 않은 상태인데 부호를 바꾼다면 음수를 곱해서 더하고
부호를 바꾸지 않는다면 그냥 더한다.
현재 인덱스에서 부호를 바꾼 상태인데 부호를 바꾼다면 그냥 더하고
부호를 바꾸지 않는다면 음수를 곱해서 더한다.
완전탐색은 오래걸리기 때문에 메모이제이션을 이용하면 된다.
*/

long long func(int flag, int idx)
{
    if(idx == N - 1)
    {
        if(flag == 1)
        {
            return arr[idx] * -1;
        }
        return arr[idx];
    }
    long long &ret = memo[flag][idx];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    //부호를 바꾼 상태
    if(flag == 1)
    {
        //부호를 바꾸지 않는다면
        ret = max(ret, func(0, idx + 1) + arr[idx] * -1);
        //부호를 바꾼다면
        ret = max(ret, func(1, idx + 1) + arr[idx]);
    }
    //부호를 안바꾼 상태
    else
    {
        //부호를 바꾸지 않는다면
        ret = max(ret, func(0, idx + 1) + arr[idx]);
        //부호를 바꾼다면
        ret = max(ret, func(1, idx + 1) + arr[idx] * -1);
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    memset(memo, -1, sizeof memo);
    printf("%lld", func(0, 0));
}