#include <cstdio>
#include <iostream>
using namespace std;
int n, S, F;
char Str[105];

int main()
{
    scanf("%d %s", &n, Str);
    for(int i = 0; i < n - 1; i++)
    {
        if(Str[i] == 'S' && Str[i + 1] == 'F')
        {
            S++;
        }
        else if(Str[i] == 'F' && Str[i + 1] == 'S')
        {
            F++;
        }
    }
    S > F ? printf("YES") : printf("NO");
}