#include <bits/stdc++.h>
using namespace std;
int Str, Int, Exp, result;

/*
Exp를 나눠서 Str, Int에 분배할 때 Str이 Int보다 크게 분배 하면 된다.
Str에 Exp전체를 주고 Int에 0을 주고 다음은 Str에 Exp - 1을 주고 Int에 1을 주는 방법으로
하나씩 하나씩 할 수 있지만 그렇게 하기에는 수의 범위가 너무 크므로 이분탐색을 이용해서
Str에 몇까지 줄 수 있는지 빠르게 확인하면 된다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int tc = 0; tc < T; tc++)
    {
        result = 0;
        scanf("%d %d %d", &Str, &Int, &Exp);
        int l, r, Count = 0;
        l = 0;
        r = Exp;
        while(l <= r)
        {
            int mid;
            mid = (l + r) / 2;
            if(Str + mid > Int + Exp - mid)
            {
                result = Exp - mid + 1;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        printf("%d\n", result);
    }
}