#include <cstdio>
#include <iostream>
using namespace std;
int N, X, arr[105], result;

/*
N까지 시뮬레이션을 돌리면서 X이하인 값들을 카운트하면 된다.
*/

int main()
{
    scanf("%d %d", &N, &X);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
    }
    int start = 0;
    for(int i = 1; i <= N; i++)
    {
        start += arr[i];
        if(start <= X)
            result++;
    }
    printf("%d", result + 1);
}