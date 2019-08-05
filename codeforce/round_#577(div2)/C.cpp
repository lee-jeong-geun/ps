#include <bits/stdc++.h>
using namespace std;
int n, k, arr[200005], result;

/*
중간값을 몇번 증가 시킬 수 있는지 이분탐색을 이용하여 구하면 된다.
mid값 만큼 증가 시키고 중간값 이후의 값들이 중간값+mid보다 작으면 중간값+mid값으로 맞추고
크면 넘어간다. 중간값+mid값으로 맞췄을때의 합이 k보다 크면 mid를 줄이고 k이하라면 mid를 늘린다.
*/

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    int l, r;
    l = 0;
    r = 1000000000;
    long long Sum;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        Sum = mid;
        for(int i = n / 2 + 1; i < n; i++)
        {
            //새로 맞춘 중간값 보다 작으면 더함
            if(arr[n / 2] + mid > arr[i])
                Sum += arr[n / 2] + mid - arr[i];
        }
        if(Sum <= k)
        {
            result = arr[n / 2] + mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    printf("%d", result);
}