#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int N, memo[1005][5][5];

int func(int day, int ab, int late)
{
    if(day == N)
    {
        return 1;
    }
    int &ret = memo[day][ab][late];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    ret += func(day + 1, 0, late) % 1000000;
    if(ab != 2)
    {
        ret += func(day + 1, ab + 1, late) % 1000000;
    }
    if(late != 1)
    {
        ret += func(day + 1, 0, late + 1) % 1000000;
    }
    return ret % 1000000;
}

int main()
{
    scanf("%d", &N);
    memset(memo, -1, sizeof memo);
    printf("%d", func(0, 0, 0) % 1000000);
}