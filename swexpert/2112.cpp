#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int D, W, K, zone[15][25], result = 987654321;

int schk(int x)
{
    int count = 1, temp = zone[0][x];
    for(int i = 1; i < D; i++)
    {
        if(temp == zone[i][x])
        {
            count++;
            if(count >= K)
            {
                return 1;
            }
        }
        else
        {
            count = 1;
            temp = zone[i][x];
        }
    }
    if(count >= K)
    {
        return 1;
    }
    return 0;
}

void func(int idx, int changecount)
{
    int tempzone[25];
    int chkcount = 0;
    if(idx == D)
    {
        for(int i = 0; i < W; i++)
        {
            int tcount;
            tcount = schk(i);
            if(tcount == 0)
            {
                break;
            }
            chkcount += tcount;
        }
        if(chkcount == W)
        {
            result = min(result, changecount);
        }
        return;
    }
    if(changecount >= result)
    {
        return;
    }
    func(idx + 1, changecount);
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < W; j++)
        {
            tempzone[j] = zone[idx][j];
            zone[idx][j] = i;
        }
        func(idx + 1, changecount + 1);
        for(int j = 0; j < W; j++)
        {
            zone[idx][j] = tempzone[j];
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        result = 987654321;
        scanf("%d %d %d", &D, &W, &K);
        for(int i = 0; i < D; i++)
        {
            for(int j = 0; j < W; j++)
            {
                scanf("%d", &zone[i][j]);
            }
        }
        func(0, 0);
        printf("#%d %d\n", testcase, result);
    }
}