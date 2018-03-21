#include <cstdio>
#include <iostream>
using namespace std;
char Str[65], result[5][65];
int flag, idx[5];

/*
주어진 문제에 맞게 구현하면 된다.
*/

void init()
{
    flag = 0;
    for(int i = 0; i < 5; i++)
    {
        result[i][0] = NULL;
        idx[i] = 0;
    }
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

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        init();
        scanf("%s", Str);
        int Strlength;
        Strlength = strlen(Str);
        for(int i = 0; i < Strlength; i++)
        {
            if(flag == 0)
            {
                if(Str[i] == ':')
                {
                    flag = 1;
                    i += 2;
                    continue;
                }
            }
            else if(flag == 1)
            {
                if(Str[i] == ':')
                {
                    flag = 2;
                    continue;
                }
                else if(Str[i] == '/')
                {
                    flag = 3;
                    continue;
                }
            }
            else if(flag == 2)
            {
                if(Str[i] == '/')
                {
                    flag = 3;
                    continue;
                }
            }
            result[flag][idx[flag]++] = Str[i];
        }
        for(int i = 0; i < 4; i++)
        {
            result[i][idx[i]] = 0;
        }
        printf("URL #%d\n", testcase);
        printf("Protocol = %s\n", result[0]);
        printf("Host     = %s\n", result[1]);
        printf("Port     = ");
        if(strlen(result[2]) == 0)
        {
            printf("<default>\n");
        }
        else
        {
            printf("%s\n", result[2]);
        }
        printf("Path     = ");
        if(strlen(result[3]) == 0)
        {
            printf("<default>\n");
        }
        else
        {
            printf("%s\n", result[3]);
        }
        if(testcase != T)
        {
            printf("\n");
        }
    }
}