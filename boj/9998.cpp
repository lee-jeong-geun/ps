#include <bits/stdc++.h>
using namespace std;
int N;
long long arrA[300005], arrB[300005], result = (1ll << 62) - 1;

/*
가운데 블록을 기준으로 건물이 완성되기 때문에 높이를 0부터 10^12까지 바꿔 보면서
하면 되지만 시간이 오래 걸린다. 따라서 이분 탐색을 이용하여 찾는다.
이때 구간을 두 개로 나눠서 왼쪽 구간보다 오른쪽 구간이 작으면 오른쪽으로 탐색하고
왼쪽이 작으면 왼쪽으로 탐색하면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &arrA[i]);
    }
    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &arrB[i]);
    }
    long long l, r;
    l = 0;
    r = (long long)1000000000000;
    while(l <= r)
    {
        long long mid, midLeft, countLeft = 0, countRight = 0;
        mid = (l + r) / 2;
        midLeft = mid - 1;
        for(int i = 0; i < N; i++)
        {
            countLeft += abs(arrA[i] - (abs(i - N / 2) + midLeft)) + abs(arrB[i] - (abs(i - N / 2) + midLeft));
            countRight += abs(arrA[i] - (abs(i - N / 2) + mid)) + abs(arrB[i] - (abs(i - N / 2) + mid));
        }
        if(countLeft < countRight)
        {
            r = mid - 1;
            result = min(result, countLeft);
        }
        else
        {
            l = mid + 1;
            result = min(result, countRight);
        }
    }
    printf("%lld", result);
}