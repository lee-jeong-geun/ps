#include <cstdio>
#include <iostream>
using namespace std;
int result, zone[5][5], t;
int arrA[4] = {0, 0, 1, -1};
int arrB[4] = {1, -1, 0, 0};

short chk[10000000];

/*
모든 경우의 수를 구해봤자 100만도 안넘어 가기 때문에 완전탐색을 하면 된다.
*/

void init()
{
    result = 0;
}

void func(int x, int y, int depth, int hap)
{
    if(depth == 7)
    {
        //저장 안 되어 있을 경우
        if(chk[hap] != t)
        {
            chk[hap] = t;
            result++;
        }
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        int nextx, nexty;
        nextx = x + arrA[i];
        nexty = y + arrB[i];
        if(nextx < 0 || nextx >= 4 || nexty < 0 || nexty >= 4)
        {
            continue;
        }
        func(nextx, nexty, depth + 1, hap * 10 + zone[nexty][nextx]);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        t = testcase;
        init();
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                scanf("%d", &zone[i][j]);
            }
        }
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                func(j, i, 1, zone[i][j]);
            }
        }
        printf("#%d %d\n", testcase, result);
    }
}