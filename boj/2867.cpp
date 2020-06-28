#include <bits/stdc++.h>
using namespace std;
int N, arr[300005], toLeftMin[300005], toLeftMax[300005], toRightMin[300005], toRightMax[300005], s[300005], idx = -1;
long long result;

/*
모든 수에 대해서 포함되는 구간을 구한다. 그리고 수열의 값을 하나씩 구하는 게 아니라
나올 수 있는 최댓값을 모두 더하고 거기에 최솟값을 모두 빼주는 방식으로 수열의 값의 합을 쉽게 구할 수 있다.
i번째 수의 구간의 시작점과 끝점을 구한다면 합은 (i - 구간의 시작점 + 1) * (구간의 끝점 - i + 1) * 값이 된다.
이제 시작점과 끝점을 구해야 하는 데 스택을 이용해서 구간의 끝점은 -> 방향으로 최댓값을 갱신하는 방식으로 구하고
구간의 시작점은 <- 방향으로 최댓값을 갱신하는 방식으로 구한다. 최솟값도 같은 방식으로 구해준다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
    }
    arr[N + 1] = 987654321;
    for(int i = 1; i <= N + 1; i++)
    {
        while(idx > -1 && arr[s[idx]] <= arr[i])
        {
            toRightMax[s[idx--]] = i - 1;
        }
        s[++idx] = i;
    }
    idx = -1;
    arr[N + 1] = -1;
    for(int i = 0; i <= N + 1; i++)
    {
        while(idx > -1 && arr[s[idx]] > arr[i])
        {
            toRightMin[s[idx--]] = i - 1;
        }
        s[++idx] = i;
    }
    idx = -1;
    arr[0] = 987654321;
    for(int i = N; i >= 0; i--)
    {
        while(idx > -1 && arr[s[idx]] < arr[i])
        {
            toLeftMax[s[idx--]] = i + 1;
        }
        s[++idx] = i;
    }
    idx = -1;
    arr[0] = -1;
    for(int i = N; i >= 0; i--)
    {
        while(idx > -1 && arr[s[idx]] >= arr[i])
        {
            toLeftMin[s[idx--]] = i + 1;
        }
        s[++idx] = i;
    }
    for(int i = 1; i <= N; i++)
    {
        result += (long long)(i - toLeftMax[i] + 1) * (toRightMax[i] - i + 1) * arr[i];
        result -= (long long)(i - toLeftMin[i] + 1) * (toRightMin[i] - i + 1) * arr[i];
    }
    printf("%lld", result);
}