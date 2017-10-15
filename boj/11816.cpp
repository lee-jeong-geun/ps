#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int result, gop = 1;
char X[105];

int main()
{
    scanf("%s", X);
    if(X[0] == '0' && X[1] == 'x')
    {
        for(int i = strlen(X) - 1; i >= 2; i--)
        {
            if(X[i] <= '9')
            {
                result += (X[i] - '0') * gop;
            }
            else
            {
                result += (X[i] - 'a' + 10) * gop;
            }
            gop *= 16;
        }
    }
    else if(X[0] == '0')
    {
        for(int i = strlen(X) - 1; i >= 1; i--)
        {
            result += (X[i] - '0') * gop;
            gop *= 8;
        }
    }
    else
    {
        printf("%s", X);
        return 0;
    }
    printf("%d", result);
}