#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int length, memo[10005], mode[5] = {0, -1, 1};
char pi[10005];

int chk(int start, int end)
{
    int count = 0;
    for(int i = 0; i < 3; i++)
    {
        count = 0;
        for(int j = start; j < end; j++)
        {
            if(pi[j] - pi[j + 1] == mode[i])
            {
                count++;
            }
        }
        if(count == end - start)
        {
            if(i == 2)
            {
                i = 1;
            }
            return i + 1;
        }
    }
    int temp = 0;
    for(int i = 0; i < 2; i++)
    {
        count = 0;
        temp = pi[start] - pi[start + 1];
        for(int j = start; j < end; j++)
        {
            if(pi[j] - pi[j + 1] == temp)
            {
                count++;
            }
            if(i == 0)
            {
                temp *= -1;
            }
        }
        if(count == end - start)
        {
            return i + 4;
        }
    }
    return 10;
}

int func(int idx)
{
    if(idx == length - 1)
    {
        return 0;
    }
    int &ret = memo[idx + 1];
    if(ret != -1)
    {
        return ret;
    }
    ret = 987654321;
    for(int i = 3; i <= 5; i++)
    {
        if(idx + i < length)
        {
            ret = min(ret, func(idx + i) + chk(idx + 1, idx + i));
        }
    }
    return ret;
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        memset(memo, -1, sizeof memo);
        scanf("%s", pi);
        length = strlen(pi);
        printf("%d\n", func(-1));
    }
}