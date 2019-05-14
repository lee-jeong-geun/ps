#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[200005], result = 1;

/*
정렬 후 1, 2, 3,..., k를 만족하는것이 최대 몇개인지 찾으면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= result)
        {
            result++;
        }
    }
    printf("%d", result - 1);
}