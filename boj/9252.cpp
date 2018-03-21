#include <cstdio>
#include <iostream>
using namespace std;
char Str1[1005], Str2[1005], result[1005];
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

void func(int x, int y, int depth)
{
    if(depth == -1)
    {
        return;
    }
    if(Str1[y] == Str2[x])
    {
        result[depth] = Str1[y];
        func(x - 1, y - 1, depth - 1);
    }
    else if(memo[y][x - 1] == memo[y][x])
    {
        func(x - 1, y, depth);
    }
    else if(memo[y - 1][x] == memo[y][x])
    {
        func(x, y - 1, depth);
    }
}

int main()
{
    scanf("%s %s", Str1 + 1, Str2 + 1);
    Str1[0] = '.';
    Str2[0] = '.';
    length1 = strlen(Str1);
    length2 = strlen(Str2);
    for(int i = 1; i < length1; i++)
    {
        for(int j = 1; j < length2; j++)
        {
            if(Str1[i] == Str2[j])
            {
                memo[i][j] = memo[i - 1][j - 1] + 1;
            }
            else
            {
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }
    int t;
    t = memo[length1 - 1][length2 - 1];
    printf("%d\n", t);
    result[t] = 0;
    func(length2 - 1, length1 - 1, t - 1);
    printf("%s", result);
}