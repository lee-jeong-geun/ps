#include <cstdio>
#include <iostream>
using namespace std;
int M, x, S;
char Str[10];

/*
각 연산에 맞게 하면 된다.
*/

int main()
{
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        scanf("%s %d", Str, &x);
        if(Str[0] == 'a')
        {
            if(Str[1] == 'd')
            {
                S = S | (1 << x);
            }
            else
            {
                S = (1 << 21) - 1;
            }
        }
        else if(Str[0] == 'c')
        {
            printf("%d\n", (S & (1 << x)) ? 1 : 0);
        }
        else if(Str[0] == 'e')
        {
            S = 0;
        }
        else if(Str[0] == 'r')
        {
            S = S & ~(1 << x);
        }
        else
        {
            S = S ^ (1 << x);
        }
    }
}