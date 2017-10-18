#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char Str[5005];
int Length, Fail[5005], result;

void failchk(int start)
{
    for(int i = start + 1, j = start; i < Length; i++)
    {
        while(j > start && Str[i] != Str[j])
        {
            j = Fail[j - 1];
        }
        if(j < start)
        {
            j = start;
        }
        if(Str[i] == Str[j])
        {
            Fail[i] = j + 1;
            j++;
            result = max(result, Fail[i] - start);
        }
    }
}

int main()
{
    scanf("%s", Str);
    Length = strlen(Str);
    for(int i = 0; i < Length; i++)
    {
        for(int j = 0; j < Length; j++)
        {
            Fail[j] = i;
        }
        failchk(i);
    }
    printf("%d", result);
}