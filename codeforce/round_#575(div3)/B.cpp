#include <bits/stdc++.h>
using namespace std;
int n, k, arr[200005], Sum[200005];

/*
k개의 그룹으로 분할 하는데 합이 전부 홀수여야 한다.
우선 주어진 수들중 짝수는 버리고 홀수만 취한다.
그 이유는 짝수는 몇번을 더하든 짝수이고 홀수는 몇번을 더하든 홀수이다. 또 짝수 더하기 홀수는
홀수이기 때문에 짝수는 필요가 없다.
홀수만 취하고 누적합을 이용하여 홀수가 홀수개인 부분들을 그룹핑 해주면 된다.
이때 마지막으로 남은 홀수의 개수가 짝수개면 안된다.
*/

int main()
{
    int q; 
    scanf("%d", &q);
    for(int tc = 0; tc < q; tc++)
    {
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            arr[i] %= 2;
            Sum[i] = Sum[i - 1] + arr[i];
        }
        //홀수를 전부 더한게 k보다 작거나 마지막 그룹을 지을때 홀수의 개수가 짝수개면 NO
        if(Sum[n] < k || (Sum[n] - k + 1) % 2 == 0)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        int idx = 0, count = 0;
        for(int i = 1; i <= n; i++)
        {
            if(count == k - 1)
                break;
            //해당 구간에 홀수가 존재하면 출력
            if(Sum[i] - Sum[idx] == 1)
            {
                printf("%d ", i);
                idx = i;
                count++;
            }
        }
        printf("%d\n", n);
    }
}