#include <bits/stdc++.h>
using namespace std;
int n, arr[400005], g, s, b, idx;

/*
g를 제일 적게 할당하고 s를 g보다 크게 할당하면서 최대한 적게 할당하고 나머지를 b에 할당 하면 된다.
할당 할땐 같은 수들은 다 같이 할당해야 하므로 같은 수들을 압축시켜서 개수로 관리한다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        g = s = b = 0;
        idx = 0;
        scanf("%d", &n);
        int prev = -1, count = 0;
        //수 압축
        for(int i = 0; i < n; i++)
        {
            int num;
            scanf("%d", &num);
            if(num != prev)
            {
                prev = num;
                arr[idx++] = count;
                count = 0;
            }
            count++;
        }
        arr[idx++] = count;
        g = arr[1];
        int Cur = 2;
        //s를 g보다 크게만 할당
        while(s <= g && Cur <= idx)
        {
            s += arr[Cur++];
        }
        //나머지는 b에 올인
        while(g + b + s + arr[Cur] <= n / 2 && Cur <= idx)
        {
            b += arr[Cur++];
        }
        //그렇게 했는데도 g보다 작으면 x
        if(g >= b)
        {
            printf("0 0 0\n");
            continue;
        }
        printf("%d %d %d\n", g, s, b);
    }
}