#include <cstdio>
#include <iostream>
using namespace std;
int arr[5], k, result;

/*
모든 쌍들의 차의 절대값이 k이하면 Yay!이고 아니라면 :(이다.
*/

int main()
{
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    for(int i = 0; i < 4; i++)
    {
        for(int j = i + 1; j < 5; j++)
        {
            if(arr[j] - arr[i] > k)
            {
                result = 1;
            }
        }
    }
    if(result == 1)
    {
        printf(":(");
        return 0;
    }
    printf("Yay!");
}