#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[2005], Sum1, Sum2;

/*
정렬을 해서 절반의 앞부분 합과 뒷부분 합이 다른지 아닌지만 확인 하면 된다.
*/

int main()
{
    scanf("%d", &n);
    n *= 2;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i++)
    {
        if(i < n / 2)
        {
            Sum1 += arr[i];
        }
        else
        {
            Sum2 += arr[i];
        }
    }
    if(Sum1 == Sum2)
    {
        printf("-1");
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}