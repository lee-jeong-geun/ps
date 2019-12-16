#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[200005];
int n;

/*
수를 정렬하고 1부터 n까지 각각의 수에 맞는 구간을 확인하면서 그 구간 안에 1부터 i까지 들어있는지
확인하면 된다. 매번 확인하기에는 시간이 오래 걸리므로 구간의 맨 왼쪽, 오른쪽을 갱신하는 방식으로
오른쪽 - 왼쪽 = i가 되면 1 아니면 0을 출력하면 된다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i].first);
            arr[i].second = i;
        }
        sort(arr, arr + n);
        int l = arr[0].second, r = arr[0].second;
        printf("1");
        for(int i = 1; i < n; i++)
        {
            l = min(l, arr[i].second);
            r = max(r, arr[i].second);
            if(r - l == i)
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
}