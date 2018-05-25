#include <cstdio>
#include <iostream>
using namespace std;
int N, result;

/*
방정식을 만족하면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        if(i * i + i == N - 1)
        {
            printf("%d", i);
            break;
        }
    }
}