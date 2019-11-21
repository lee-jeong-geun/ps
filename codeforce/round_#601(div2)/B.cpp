#include <bits/stdc++.h>
using namespace std;
int n, m, arr[1005], result;

/*
우선 m이 n보다 작으면 절대 완성 시킬 수 없다.
문제의 조건에 맞는 방법은 빙 둘러서 체인을 거는 방법밖에 없다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int tc = 0; tc < T; tc++)
    {
        result = 0;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            result += arr[i];
        }
        if(n > m || n == 2)
        {
            printf("-1\n");
            continue;
        }
        result *= 2;
        printf("%d\n", result);
        for(int i = 0; i < n - 1; i++)
        {
            printf("%d %d\n", i + 1, i + 2);
        }
        printf("%d %d\n", n, 1);
    }
}