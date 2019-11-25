#include <bits/stdc++.h>
using namespace std;
int n, result, lMax, rMin;

/*
주어진 구간을 다 포함하는 구간을 만들어야 하는데 길이를 최소로 해야 한다.
단순하게 생각해보면 주어진 구간을 다 포함 시키려면 가장 앞에 있는 구간의 끝나는 지점과
가장 뒤에 있는 구간의 시작점을 포함시키면 가장 짧게 다 포함 시킬 수 있다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        lMax = 0;
        rMin = 1234567890;
        result = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            lMax = max(lMax, l);
            rMin = min(rMin, r);
        }
        result = lMax - rMin;
        if(result < 0)
            result = 0;
        printf("%d\n", result);
    }
}