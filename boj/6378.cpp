#include <cstdio>
#include <iostream>
using namespace std;
int length;
char Str[1005];

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

void itoa(char *str, int a)
{
    int idx = 0;
    char temp[1005];
    while(a != 0)
    {
        temp[idx++] = (char)(a % 10 + '0');
        a /= 10;
    }
    temp[idx] = NULL;
    for(int i = 0; i < idx; i++)
    {
        str[i] = temp[idx - i - 1];
    }
    str[idx] = NULL;
}

char change()
{
    while(1)
    {
        int len, hap = 0;
        len = strlen(Str);
        if(len == 1)
        {
            return Str[0];
        }
        for(int i = 0; i < len; i++)
        {
            hap += Str[i] - '0';
        }
        itoa(Str, hap);
    }
}

int main()
{
    while(1)
    {
        scanf("%s", Str);
        if(Str[0] == '0')
        {
            break;
        }
        length = strlen(Str);
        printf("%c\n", change());
    }
}