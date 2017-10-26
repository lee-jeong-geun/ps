#include <cstdio>
#include <iostream>
using namespace std;
int K, sosuchk[1005], sosu[1005], sidx, result[5], flag;

void func(int depth, int hap)
{
    if(depth == 3)
    {
        if(hap == K)
        {
            for(int i = 0; i < 3; i++)
            {
                printf("%d ", result[i]);
            }
            flag = 1;
        }
        return;
    }
    for(int i = 0; i < sidx; i++)
    {
        result[depth] = sosu[i];
        func(depth + 1, hap + sosu[i]);
        if(flag == 1)
        {
            return;
        }
    }
}

int main()
{
    for(int i = 2; i < 1000; i++)
    {
        if(sosuchk[i] == 0)
        {
            sosu[sidx++] = i;
            for(int j = i + i; j < 1000; j = j + i)
            {
                sosuchk[j] = 1;
            }
        }
    }
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        flag = 0;
        scanf("%d", &K);
        func(0, 0);
        if(flag == 0)
        {
            printf("0");
        }
        printf("\n");
    }
}