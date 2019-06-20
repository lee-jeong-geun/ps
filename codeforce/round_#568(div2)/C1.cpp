#include <bits/stdc++.h>
using namespace std;
int n, M, T[105], Sum;

/*
합이 M이하가 되는 곳은 전부 0을 출력하고 합이 M보다 커지는 경우부터는
정렬을 하여 값을 큰것부터 하나씩 빼면서 해당 수를 더 했을때 M이하라면 제거한 수의 개수 출력
그게 아니라면 계속 지워 나가면 된다.
*/

int main()
{
    scanf("%d %d", &n, &M);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &T[i]);
    }
    int idx = 987654321;
    for(int i = 0; i < n; i++)
    {
        if(Sum + T[i] > M)
        {
            idx = i;
            break;
        }
        //M이하라면 0을 출력
        printf("%d ", 0);
        Sum += T[i];
    }
    int count = 0;
    for(int i = idx; i < n; i++)
    {
        Sum = 0;
        count = 0;
        sort(T, T + i);
        for(int j = 0; j < i; j++)
        {
            Sum += T[j];
        }
        //M이하가 될때까지 하나씩 계속 지움
        for(int j = i - 1; j >= 0; j--)
        {
            Sum -= T[j];
            count++;
            if(Sum + T[i] <= M)
            {
                printf("%d ", count);
                break;
            }
        }
    }
}