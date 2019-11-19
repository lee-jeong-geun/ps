#include <bits/stdc++.h>
using namespace std;
int n, m, arr[200005];
long long Sum[200005], memo[200005];

/*
작은것들을 최대한 많이 쓰는게 이득이므로 정렬을 하고
m일 까지는 하루에 하나씩만 고르는게 최선의 선택이므로 
1 ~ m까지 한개만 고르는 값을 출력하면 된다.
그 이후부터는 i까지의 전체 합 + (i - m)까지의 값을 출력 하면 된다.
*/

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr + 1, arr + n + 1);
    for(int i = 1; i <= n; i++)
    {
        Sum[i] = Sum[i - 1] + arr[i];
    }
    for(int i = 1; i <= m; i++)
    {
        printf("%lld ", Sum[i]);
        memo[i] = Sum[i];
    }
    for(int i = m + 1; i <= n; i++)
    {
        printf("%lld ", Sum[i] + memo[i - m]);
        memo[i] = Sum[i] + memo[i - m];
    }
}