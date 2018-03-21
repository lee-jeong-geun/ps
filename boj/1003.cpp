#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int N, memo[55][3];

/*
전형적인 dp문제
memo[N][0]에 0의 호출 개수 memo[N][1]에 1의 호출 개수를 담으면 된다.
*/

int func(int num, int flag)
{
    //기저사례
    if(num == 1 || num == 0)
    {
        if(num == flag)
        {
            return 1;
        }
        return 0;
    }
    int &ret = memo[num][flag];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    ret = func(num - 1, flag) + func(num - 2, flag);
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        memset(memo, -1, sizeof memo);
        scanf("%d", &N);
        printf("%d %d\n", func(N, 0), func(N, 1));
    }
}