#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, K, M, L, memo[1 << 13][12], result;
int First[15];
int Semester[15];

int countchk(int num)
{
    int count = 0;
    for(int i = 0; (1 << i) <= num; i++)
    {
        if((num & (1 << i)) != 0)
        {
            count++;
        }
    }
    return count;
}

int func(int state, int depth)
{
    int temp = 0;
    if(countchk(state) >= K)
    {
        return 0;
    }
    if(depth == M)
    {
        return 987654321;
    }
    int &ret = memo[state][depth];
    if(ret != -1)
    {
        return ret;
    }
    ret = 987654321;
    ret = min(ret, func(state, depth + 1));
    temp = Semester[depth] & ~state;
    for(int i = 0; i < N; i++)
    {
        if((temp & (1 << i)) != 0 && (First[i] & state) != First[i])
        {
            temp &= ~(1 << i);
        }
    }
    for(int i = temp; (temp & i) != 0; i = (temp & (i - 1)))
    {
        if(countchk(i) <= L)
        {
            ret = min(ret, func(state | i, depth + 1) + 1);
        }
    }
    return ret;
}

int main()
{
    int TC;
    scanf("%d", &TC);
    for(int testcase = 0; testcase < TC; testcase++)
    {
        memset(First, 0, sizeof First);
        memset(Semester, 0, sizeof Semester);
        memset(memo, -1, sizeof memo);
        scanf("%d %d %d %d", &N, &K, &M, &L);
        for(int i = 0; i < N; i++)
        {
            int R;
            scanf("%d", &R);
            for(int j = 0; j < R; j++)
            {
                int num;
                scanf("%d", &num);
                First[i] |= (1 << num);
            }
        }
        for(int i = 0; i < M; i++)
        {
            int C;
            scanf("%d", &C);
            for(int j = 0; j < C; j++)
            {
                int num;
                scanf("%d", &num);
                Semester[i] |= (1 << num);
            }
        }
        result = func(0, 0);
        if(result > 100000000)
        {
            printf("IMPOSSIBLE\n");
        }
        else
        {
            printf("%d\n", result);
        }
    }
}