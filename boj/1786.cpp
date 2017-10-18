#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int Tlength, Plength, Fail[1000005], result, resultarr[1000005];
char T[1000005], P[1000005];

void failchk()
{
    for(int i = 1, j = 0; i < Plength; i++)
    {
        while(j > 0 && P[i] != P[j])
        {
            j = Fail[j - 1];
        }
        if(P[i] == P[j])
        {
            Fail[i] = j + 1;
            j++;
        }
    }
}

int main()
{
    gets(T);
    gets(P);
    Tlength = strlen(T);
    Plength = strlen(P);
    failchk();
    for(int i = 0, j = 0; i < Tlength; i++)
    {
        while(j > 0 && T[i] != P[j])
        {
            j = Fail[j - 1];
        }
        if(T[i] == P[j])
        {
            j++;
            if(j == Plength)
            {
                resultarr[result] = i - Plength + 2;
                result++;
                j = Fail[j - 1];
            }
        }
    }
    printf("%d\n", result);
    for(int i = 0; i < result; i++)
    {
        printf("%d ", resultarr[i]);
    }
}