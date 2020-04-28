#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[500005];
int N, minTable[500005];
long long result, Sum, minA = 1234567890, maxB = -1234567890;

/*
각 쿼리마다 최소 가격을 고르는 방법은 단순하게 생각해서 B값을 작은 순으로 i-1개 고른 후
나머지 한 개는 고르지 않은 값 중 최소 A 값이다. 하지만 i-1개의 B를 고른 값 중에서 A 값을 골랐을 때 
최적일 경우가 있다. 이 경우에는 어떤 것을 A 값으로 골랐을 때 최적인지 확인하면 된다. 그 방법은
B - A가 제일 큰 것을 선택하면 된다. 따라서 최솟값은 min(i까지의 B의 합 + 최적 A - 최적 A의 B값,
i-1까지의 B의 합 + 고르지 않은 값 중 최소 A)이다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &arr[i].second, &arr[i].first);
    }
    //B의 값으로 정렬
    sort(arr, arr + N);
    minTable[N] = 1234567890;
    for(int i = N - 1; i >= 0; i--)
    {
        //i ~ N까지 A의 최솟값 저장
       minTable[i] = min(minTable[i + 1], arr[i].second); 
    }
    for(int i = 0; i < N; i++)
    {
        result = min(Sum + minTable[i], Sum + arr[i].first + minA - maxB);
        Sum += arr[i].first;
        //최적 A 갱신
        if(maxB - minA < arr[i].first - arr[i].second)
        {
            maxB = arr[i].first;
            minA = arr[i].second;
        }
        printf("%lld\n", result);
    }
}