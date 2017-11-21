#include <cstdio>
#include <iostream>
using namespace std;
int length, chk[10005], result;
char word[25];

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

int main()
{
    for(int i = 2; i < 10000; i++)
    {
        if(chk[i] == 0)
        {
            for(int j = i + i; j < 10000; j = j + i)
            {
                chk[j] = 1;
            }
        }
    }
    scanf("%s", word);
    length = strlen(word);
    for(int i = 0; i < length; i++)
    {
        if(word[i] <= 'Z')
        {
            result += word[i] - 'A' + 27;
        }
        else
        {
            result += word[i] - 'a' + 1;
        }
    }
    if(chk[result] == 1)
    {
        printf("It is not a prime word.");
    }
    else
    {
        printf("It is a prime word.");
    }
}