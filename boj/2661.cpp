#include <cstdio>
#include <iostream>
using namespace std;
int N, result[85], flag;

int chk(int idx, int num)
{
    int comp1idx, comp2idx, count = 0, cmpcount = 0;
    result[idx] = num;
    comp1idx = idx;
    comp2idx = idx - 1;
    while(comp2idx - count >= 0)
    {
        count++;
        cmpcount = 0;
        for(int i = 0; i < count; i++)
        {
            if(result[comp1idx - i] == result[comp2idx - i])
            {
                cmpcount++;
            }
        }
        if(cmpcount == count)
        {
            return 0;
        }
        comp2idx--;
    }
    return 1;
}

void func(int idx)
{
    if(flag == 1)
    {
        return;
    }
    if(idx == N)
    {
        for(int i = 0; i < N; i++)
        {
            printf("%d", result[i]);
        }
        flag = 1;
        return;
    }
    for(int i = 1; i <= 3; i++)
    {
        if(chk(idx, i) == 1)
        {
            result[idx] = i;
            func(idx + 1);
        }
    }
}

int main()
{
    scanf("%d", &N);
    func(0);
}