#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int swim[10], month[15], result = 987654321;

void init()
{
    result = 987654321;
}

void func(int depth, int money)
{
    if(depth >= 12)
    {
        result = min(result, money);
        return;
    }
    if(month[depth] == 0)
    {
        func(depth + 1, money);
    }
    else
    {
        func(depth + 1, money + month[depth] * swim[0]);
        func(depth + 1, money + swim[1]);
        func(depth + 3, money + swim[2]);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        init();
        for(int i = 0; i < 4; i++)
        {
            scanf("%d", &swim[i]);
        }
        for(int i = 0; i < 12; i++)
        {
            scanf("%d", &month[i]);
        }
        func(0, 0);
        printf("#%d %d\n", testcase, min(result, swim[3]));
    }
}