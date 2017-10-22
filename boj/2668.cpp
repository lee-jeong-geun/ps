#include <cstdio>
#include <iostream>
using namespace std;
int N, Number[105], chk[105], result[105], resultcount;

void func(int num)
{
    if(result[num] == 1)
    {
        return;
    }
    if(chk[num] == 1)
    {
        result[num] = 1;
        resultcount++;
        func(Number[num]);
        return;
    }
    chk[num] = 1;
    func(Number[num]);
    chk[num] = 0;
}

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &Number[i]);
    }
    for(int i = 1; i <= N; i++)
    {
        func(i);
    }
    printf("%d\n", resultcount);
    for(int i = 1; i <= N; i++)
    {
        if(result[i] == 1)
        {
            printf("%d\n", i);
        }
    }
}