#include <bits/stdc++.h>
using namespace std;
long long M, N, arr[100005], Sum, result;

/*
분노를 줄이기 위해선 사탕을 최대한 고르게 분배해야 한다. 사탕의 총 개수에 M을
빼면 반드시 나누어 줘야 할 사탕의 개수가 된다. 이 사탕을 이용해서 i번째 친구가
원하는 사탕의 개수, 반드시 나눠 줘야 할 사탕의 개수 / 남은 사람 중에 작은 값을
주면 된다.
*/

int main()
{
    scanf("%lld %lld", &M, &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
        Sum += arr[i];
    }
    Sum -= M;
    sort(arr, arr + N);
    for(int i = 0; i < N; i++)
    {
        long long Min = min(arr[i], Sum / (N - i));
        result += Min * Min;
        Sum -= Min;
    }
    printf("%lld", result);
}