#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char A[90], B[90], result[90];
int Alength, Blength, flag, resultflag;

void change(char *str, int length)
{
    char temp[90];
    for(int i = 0; i < length; i++)
    {
        temp[i] = str[length - i - 1];
    }
    for(int i = length; i < 86; i++)
    {
        temp[i] = '0';
    }
    temp[86] = '\0';
    strcpy(str, temp);
}

int main()
{
    scanf("%s %s", A, B);
    if(strlen(A) < strlen(B))
    {
        char temp[90];
        strcpy(temp, A);
        strcpy(A, B);
        strcpy(B, temp);
    }
    Alength = strlen(A);
    Blength = strlen(B);
    change(A, Alength);
    change(B, Blength);
    for(int i = 0; i < Alength; i++)
    {
        if(A[i] + B[i] == 96)
        {
            result[i] = '0';
            if(flag == 1)
            {
                result[i] = '1';
                flag = 0;
            }
        }
        else if(A[i] + B[i] == 97)
        {
            result[i] = '1';
            if(flag == 1)
            {
                result[i] = '0';
            }
        }
        else
        {
            result[i] = '0';
            if(flag == 1)
            {
                result[i] = '1';
            }
            flag = 1;
        }
    }
    if(flag == 1)
    {
        printf("1");
        resultflag = 1;
    }
    for(int i = Alength - 1; i >= 0; i--)
    {
        if(resultflag == 0 && result[i] == '0')
        {
            continue;
        }
        else if(result[i] == '1')
        {
            resultflag = 1;
        }
        printf("%c", result[i]);
    }
    if(resultflag == 0)
    {
        printf("0");
    }
}