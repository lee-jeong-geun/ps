#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, Num[105], result;

/*
101을 찾아야 한다. 101을 찾으면 2번째 1을 지우고 다시 101을 찾으면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Num[i]);
    }
    Num[n] = -1;
    for(int i = 0; i < n; i++)
    {
        if(Num[i] == 1 && Num[i + 1] == 0 && Num[i + 2] == 1)
        {
            result++;
            Num[i + 2] = 0;
        }
    }
    printf("%d", result);
}