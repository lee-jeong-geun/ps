#include <bits/stdc++.h>
using namespace std;
long long k, n, a, b, result;

/*
k를 0이 안되게 하면서 n개를 최대한 a에 배분해야 한다.
a가 안되면 남은 값을 b에 배분하는 방식으로 최대 몇개 까지 할 수 있는지 확인해야 한다.
이때 n은 최대 10^9까지 나오므로 완전탐색은 불가능하고 잘보면 a에 10개를 할당 했을때 k가 0이 안된다면
a에 0 ~ 9개를 할당 해도 k가 0이 되지 않는다. 이러한 규칙을 이용하여 a에 x개를 할당 했을때 k가 0이 되는지
안되는지를 이분탐색으로 답을 구하면 된다.
*/

int main()
{
    int q;
    scanf("%d", &q);
    for(int tc = 0; tc < q; tc++)
    {
        result = -1;
        scanf("%lld %lld %lld %lld", &k, &n, &a, &b);
        //a에 n개 전체를 할당 가능한 경우
        if(n * a < k)
        {
            printf("%lld\n", n);
            continue;
        }
        int l, r;
        l = 0;
        r = n;
        while(l <= r)
        {
            long long mid;
            mid = (l + r) / 2;
            //a에 mid개 할당 하고 남은것들을 b에 할당 했을때 k 미만인 경우
            if(a * mid + b * (n - mid) < k)
            {
                result = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        printf("%lld\n", result);
    }
}