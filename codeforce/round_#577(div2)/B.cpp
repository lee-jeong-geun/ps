#include <bits/stdc++.h>
using namespace std;
int n, arr[100005], result;
long long Sum;

/*
우선 모든 수들의 합이 홀수면 절대 0으로 만들 수 없고
합이 짝수인 상태에서 제일 큰 값이 나머지 값들의 합보다 크면 0으로 만들 수 없다.
이 두 조건을 만족한다면 매 연산마다 가장 큰 값 2개를 1씩 계속 감소 시킬 때
모든 합이 짝수이므로 결국은 모든 원소를 0으로 만든다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        Sum += arr[i];
    }
    if(Sum % 2 == 1)
        result = 1;
    sort(arr, arr + n);
    if(Sum - arr[n - 1] < arr[n - 1])
        result = 1;
    if(result == 1)
        printf("NO");
    else
        printf("YES");
}