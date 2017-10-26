#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Number[15], Op[5], Max = -1234567890, Min = 1234567890;

void func(int depth, int hap, int plus, int minus, int gop, int div)
{
    if(depth == N)
    {
        Max = max(Max, hap);
        Min = min(Min, hap);
        return;
    }
    if(plus != 0)
    {
        func(depth + 1, hap + Number[depth], plus - 1, minus, gop, div);
    }
    if(minus != 0)
    {
        func(depth + 1, hap - Number[depth], plus, minus - 1, gop, div);
    }
    if(gop != 0)
    {
        func(depth + 1, hap * Number[depth], plus, minus, gop - 1, div);
    }
    if(div != 0)
    {
        if(hap < 0)
        {
            int temp;
            temp = (hap * - 1) / Number[depth];
            temp *= -1;
            func(depth + 1, temp, plus, minus, gop, div - 1);
        }
        else
        {
            func(depth + 1, hap / Number[depth], plus, minus, gop, div - 1);
        }
    }
    return;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Number[i]);
    }
    for(int i = 0; i < 4; i++)
    {
        scanf("%d", &Op[i]);
    }
    func(1, Number[0], Op[0], Op[1], Op[2], Op[3]);
    printf("%d\n%d", Max, Min);
}