#include <cstdio>
#include <iostream>
using namespace std;
long long S, hap;
int Count;

/*
1부터 차례대로 합이 S를 넘을때까지 더해주면서 카운트를 하면 된다.
*/

int main()
{
    scanf("%ld", &S);
    for(int i = 1; ; i++)
    {
        if(hap + i > S)
        {
            break;
        }
        hap += i;
        Count++;
    }
    printf("%d", Count);
}