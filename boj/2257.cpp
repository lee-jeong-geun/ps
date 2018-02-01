#include <cstdio>
#include <iostream>
using namespace std;
char Str[105];
int Stack[205], Top, alph[30], result;

/*
간단한 스택 문제이다.
C, H, O를 만나면 스택에 해당 질량 값을 넣어주고 숫자를 만나면 스택에 Top에 있는 값과 곱한다.
( 괄호를 만나면 스택에 -1을 push 하고 ) 괄호를 만나면 -1을 만날때까지 값을 pop하면서 그 값들을 다
더해주고 스택에 push 한다.
마지막에 스택에 남은 값들을 모두 더하면 된다.
*/

void push(int data)
{
    Stack[++Top] = data;
}

void pop()
{
    Top--;
}

int main()
{
    alph['H' - 'A'] = 1;
    alph['C' - 'A'] = 12;
    alph['O' - 'A'] = 16;
    scanf("%s", Str);
    for(int i = 0; Str[i] != 0; i++)
    {
        if(Str[i] == '(')
        {
            push(-1);
        }
        else if(Str[i] == ')')
        {
            int hap = 0;
            while(Stack[Top] != -1)
            {
                hap += Stack[Top];
                pop();
            }
            pop();
            push(hap);
        }
        else if(Str[i] <= '9')
        {
            Stack[Top] *= (Str[i] - '0');
        }
        else
        {
            push(alph[Str[i] - 'A']);
        }
    }
    while(Top != 0)
    {
        result += Stack[Top];
        pop();
    }
    printf("%d", result);
}