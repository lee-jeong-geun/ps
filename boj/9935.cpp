#include <cstdio>
#include <iostream>
using namespace std;
int Strlength, bomblength, Stack[1000005], Top, idx, flag;
char Str[1000005], bomb[40];

/*
문자들을 하나씩 탐색하면서 폭탄과 관련된 문자들은 스택에 푸쉬한다.
관련되지 않은 문자가 나온다면 스택을 다 팝 해주면서 출력을 바로한다.
폭탄은 완전히 연결된 경우에만 터지기 때문에 중간에 다른 문자가 있다는건 폭탄이
터지는 않는 조건 이기 때문에 다 출력 하는것이다.
*/

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

//폭탄이 터지는 조건
void bombchk()
{
    //폭탄이 터지면 Top을 줄임
    if(bomb[Stack[Top]] == bomb[bomblength - 1])
    {
        Top -= bomblength;
    }
}

int main()
{
    scanf("%s", Str);
    scanf("%s", bomb);
    Strlength = strlen(Str);
    bomblength = strlen(bomb);
    Stack[0] = -1;
    for(int i = 0; i < Strlength; i++)
    {
        //폭탄의 첫부분임
        if(bomb[0] == Str[i])
        {
            Stack[++Top] = 0;
            bombchk();
        }
        //폭탄의 중간 부분
        else if(bomb[Stack[Top] + 1] == Str[i])
        {
            Stack[Top + 1] = Stack[Top] + 1;
            Top++;
            bombchk();
        }
        //폭탄의 연속이 끊겼거나 폭탄이 아닐경우
        else
        {
            flag = 1;
            //바로 출력
            for(int j = 1; j <= Top; j++)
            {
                printf("%c", bomb[Stack[j]]);
            }
            Top = 0;
            printf("%c", Str[i]);
        }
    }
    for(int i = 1; i <= Top; i++)
    {
        flag = 1;
        printf("%c", bomb[Stack[i]]);
    }
    //출력되는 문자가 하나도 없을 경우
    if(flag == 0)
    {
        printf("FRULA");
    }
}