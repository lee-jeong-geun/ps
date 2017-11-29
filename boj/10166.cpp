#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int D1, D2, chk[2005], Count[2005], result;

void chair(int start, int flag)
{
    for(int i = start; i <= D2; i++)
    {
        int hap = i;
        for(int j = 1; j < i; j++)
        {
            if(i % j == 0)
            {
                if(chk[j] == 1)
                {
                    hap -= Count[j];
                }
                chk[j] = 1;
            }
        }
        chk[i] = 1;
        if(flag == 0)
        {
            Count[i] = hap;
        }
        else
        {
            result += hap;
        }
    }
}

int main()
{
    scanf("%d %d", &D1, &D2);
    chair(1, 0);
    memset(chk, 0, sizeof chk);
    chair(D1, 1);
    printf("%d", result);
}