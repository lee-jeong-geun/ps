#include <cstdio>
#include <iostream>
using namespace std;
int N, chk[1005], Max;
char book[1005][55], Maxbook[55];

int strcmp(char *str1, char *str2)
{
    while(*str1 != 0 || *str2 != 0)
    {
        if(*str1 > *str2)
        {
            return 1;
        }
        else if(*str1 < *str2)
        {
            return -1;
        }
        str1++;
        str2++;
    }
    return 0;
}

void strcpy(char *str1, char *str2)
{
    while(*str2 != 0)
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%s", book[i]);
    }
    for(int i = 0; i < N; i++)
    {
        int count = 0;
        for(int j = 0; j < N; j++)
        {
            if(strcmp(book[i], book[j]) == 0 && chk[j] == 0)
            {
                chk[j] = 1;
                count++;
            }
        }
        if(Max < count)
        {
            Max = count;
            strcpy(Maxbook, book[i]);
        }
        if(Max == count && strcmp(Maxbook, book[i]) == 1)
        {
            strcpy(Maxbook, book[i]);
        }
    }
    printf("%s", Maxbook);
}