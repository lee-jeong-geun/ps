#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
char Str[10005];

stack<char> s;

char chk(char a)
{
    switch (a)
    {
        case '(' : return ')';
        case '{' : return '}';
        case '[' : return ']';
    }
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        while(!s.empty())
        {
            s.pop();
        }
        int length, flag = 0;
        scanf("%s", Str);
        length = strlen(Str);
        for(int i = 0; i < length; i++)
        {
            if(Str[i] == '(' || Str[i] == '{' || Str[i] == '[')
            {
                s.push(Str[i]);
            }
            else
            {
                if(!s.empty() && chk(s.top()) == Str[i])
                {
                    s.pop();
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0 && s.empty())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}