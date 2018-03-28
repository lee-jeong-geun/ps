#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Number[15], op[5], Max, Min;

/*
단순 백트래킹
*/

void init()
{
    Max = -987654321;
    Min = 987654321;
}

void func(int depth, int hap)
{
    //기저사례
    if(depth == N)
    {
        Max = max(Max, hap);
        Min = min(Min, hap);
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        //연산자 사용가능하면 사용
        if(op[i] != 0)
        {
            int temp;
            op[i]--;
            switch (i)
            {
                case 0: temp = hap + Number[depth]; break;
                case 1: temp = hap - Number[depth]; break;
                case 2: temp = hap * Number[depth]; break;
                case 3: temp = hap / Number[depth]; break;
            }
            func(depth + 1, temp);
            op[i]++;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        init();
        scanf("%d", &N);
        for(int i = 0; i < 4; i++)
        {
            scanf("%d", &op[i]);
        }
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &Number[i]);
        }
        func(1, Number[0]);
        printf("#%d %d\n", testcase, Max - Min);
    }
}