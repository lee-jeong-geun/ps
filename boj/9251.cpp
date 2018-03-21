#include <cstdio>
#include <iostream>
using namespace std;
char Str1[1005], Str2[1005];
int length1, length2, memo[1005][1005];

int max(int a, int b)
{
    return a > b ? a : b;
}

int strlen(char *str)
{
    int len = 0;
    while(*str != 0)
    {
        len++;
        str++;
    }
    return len;
}

int func(int idx1, int idx2)
{
    if(idx1 == length1 || idx2 == length2)
    {
        return 0;
    }
    int &ret = memo[idx1][idx2];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    if(Str1[idx1] == Str2[idx2])
    {
        ret = max(ret, func(idx1 + 1, idx2 + 1) + 1);
    }
    ret = max(ret, func(idx1 + 1, idx2));
    ret = max(ret, func(idx1, idx2 + 1));
    return ret;
}

int main()
{
    scanf("%s %s", Str1, Str2);
    for(int i = 0; i < 1004; i++)
    {
        for(int j = 0; j < 1004; j++)
        {
            memo[i][j] = -1;
        }
    }
    length1 = strlen(Str1);
    length2 = strlen(Str2);
    printf("%d", func(0, 0));
}