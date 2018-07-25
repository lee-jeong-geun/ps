#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
stack<char> s;
char Str[105];

/*
여는 괄호면 스택에 푸쉬하고 닫는 괄호면 스택의 top에있는 값을 비교해서 짝이 맞는 괄호면 팝
아니라면 틀린 답이다. 비교를 다 끝내고 스택에 값이 있으면 틀린 답이다.
*/

int main()
{
    while(gets(Str) != 0)
    {
        int flag = 0;
        while(s.size() > 0)
        {
            s.pop();
        }
        int length;
        if(Str[0] == '.')
        {
            break;
        }
        length = strlen(Str);
        for(int i = 0; i < length; i++)
        {
            if(Str[i] == '(' || Str[i] == '[')
            {
                s.push(Str[i]);
            }
            else if(Str[i] == ')' || Str[i] == ']')
            {
                if(s.size() > 0)
                {
                    if(s.top() == '(' && Str[i] == ')')
                    {
                        s.pop();
                    }
                    else if(s.top() == '[' && Str[i] == ']')
                    {
                        s.pop();
                    }
                    else
                    {
                        flag = 1;
                    }
                }
                else
                {
                    flag = 1;
                }
            }
        }
        if(s.size() > 0)
        {
            flag = 1;
        }
        flag == 1 ? printf("no\n") : printf("yes\n");
    }
}