#include <cstdio>
#include <iostream>
using namespace std;
int N, result, Stack[100005], Top;
char Str[100005];

/*
간단하게 스택을 이용해서 각 문자들을 스택에 넣고 스택의 Top에 있는 문자와 같은 문자라면 스택에서
팝 해준다. 그래서 스택에 데이터가 하나도 없다면 좋은 단어이다.
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

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int length = 0;
        Top = 0;
        Stack[Top] = 1;
        scanf("%s", Str);
        length = strlen(Str);
        for(int j = 0; j < length; j++)
        {
            //Top에 있는 문자와 같다면 pop해줌
            if(Stack[Top] == Str[j])
            {
                Top--;
            }
            //아니라면 스택에 push해줌
            else
            {
                Stack[++Top] = Str[j];
            }
        }
        //스택에 데이터가 없다면 카운트
        if(Top == 0)
        {
            result++;
        }
    }
    printf("%d", result);
}