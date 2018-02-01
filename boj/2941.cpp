#include <cstdio>
#include <iostream>
using namespace std;
int result;
char Str[105], cro[7][10] = {"c=", "c-", "d-", "lj", "nj", "s=", "z="};

/*
일반 구현 문제
*/

//문자열 비교 함수
int _strcmp(char *str1, char *str2)
{
    while(*str1 != 0 || *str2 != 0)
    {
        if(*str1 != *str2)
        {
            return 1;
        }
        str1++;
        str2++;
    }
    return 0;
}

//크로아티아 알파벳 체크 함수
int wordchk(char *str)
{
    for(int i = 0; i < 7; i++)
    {
        if(_strcmp(str, cro[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%s", Str);
    for(int i = 0; Str[i] != 0; i++)
    {
        char temp[5];
        if(Str[i + 1] != 0)
        {
            temp[0] = Str[i];
            temp[1] = Str[i + 1];
            temp[2] = NULL;
            if(wordchk(temp) == 1)
            {
                i++;
            }
        }
        if(Str[i] == 'd' && Str[i + 1] == 'z' && Str[i + 2] == '=')
        {
            i += 2;
        }
        result++;
    }
    printf("%d", result);
}