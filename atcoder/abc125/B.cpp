#include <cstdio>
#include <iostream>
using namespace std;
int N, result, arr[25];

/*
X - Y의 최대값을 구해야 한다. 최대값은 V > C인 값들만 구하면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        if(num < arr[i])
        {
            result += arr[i] - num;
        }
    }
    printf("%d", result);
}