#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, chk[100005], child[100005], result;

/*
1씩 증가하는 LIS를 찾는 문제이다.
배열에 카운트를 저장한다. 자기보다 1 작은 번호의 카운트를 가지고 +1을 하고 배열에 저장한다.
이런식으로 최대값을 추려내고 전체에서 빼주면 답이 나온다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        memset(chk, 0, sizeof chk);
        result = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &child[i]);
        }
        for(int i = 0; i < N; i++)
        {
            //자신보다 1작은 값의 카운트 + 1
            chk[child[i]] = chk[child[i] - 1] + 1;
            result = max(result, chk[child[i]]);
        }
        printf("#%d %d\n", testcase, N - result);
    }
}