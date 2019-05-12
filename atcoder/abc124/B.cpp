#include <cstdio>
#include <iostream>
using namespace std;
int N, arr[25], Max, result;

/*
주어진 배열의 오름차순 길이를 구하면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        if(Max <= arr[i])
        {
            Max = arr[i];
            result++;
        }
    }
    printf("%d", result);
}