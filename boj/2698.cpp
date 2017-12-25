#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n, k, memo[105][5][105];

//점화식 d[해당idx][0 or 1][1 쌍의 개수]
int func(int idx, int flag, int Count)
{
    //끝에 도달하였을때
    if(idx == n - 1)
    {
        //쌍의 개수가 k개일경우 리턴 1
        if(Count == k)
        {
            return 1;
        }
        return 0;
    }
    int &ret = memo[idx + 1][flag][Count];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    ret += func(idx + 1, 0, Count);
    //앞의 idx에서 1을 선택하고 지금도 1을 선택시 쌍의개수 + 1
    if(flag == 1)
    {
        ret += func(idx + 1, 1, Count + 1);
    }
    if(flag == 0)
    {
        ret += func(idx + 1, 1, Count);
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        scanf("%d %d", &n, &k);
        memset(memo, -1, sizeof memo);
        //시작idx를 -1로 해주고 재귀함수 안에서 0번째 idx에서 나올수 있는 두개의 경우를 한번에 처리함
        printf("%d\n", func(-1, 0, 0));
    }
}