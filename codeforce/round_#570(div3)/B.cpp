#include <bits/stdc++.h>
using namespace std;
int n, k, arr[105];

/*
어떠한 값을 추가 했을때 주어진 배열의 원소들과의 차가 k이하여야 한다.
간단하게 최소값과 최대값의 차가 2k보다 크면 어떤 값을 넣어도 모든 원소들과의 차가 k이하일 수 없다.
최소값과 최대값의 차가 2k 이하라면 최소값 + k를 출력하면 된다.
*/

int main()
{
    int q;
    scanf("%d", &q);
    for(int tc = 0; tc < q; tc++)
    {
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);
        if(arr[n - 1] - arr[0] > k * 2)
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n", arr[0] + k);
    }
}