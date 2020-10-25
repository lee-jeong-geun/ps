#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[100005];
int N, M;
long long result;

/*
p를 기준으로 오름차순 정렬 후 c값이 이전 값보다 높은 경우 높이를 갱신하고 낮은 값이 나온다면 
그 차이를 결과값에 더하고 높이를 낮은 값으로 갱신하면 된다.
*/

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    sort(arr, arr + N);
    arr[N].first = M + 1;
    arr[N].second = 0;
    int height = 0;
    for(int i = 0; i <= N; i++)
    {
        if(height > arr[i].second)
            result += height - arr[i].second;
        height = arr[i].second;
    }
    printf("%lld", result);
}