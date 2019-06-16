#include <cstdio>
#include <iostream>
using namespace std;
long long N, K, arr[100005], Sum, result;

/*
투포인터를 이용해서 오른쪽 포인터는 합들을 계속 누적 시키고 왼쪽 포인터는 합을 지운다.
합을 누적 시킬때는 해당 합이 K이상이라면 그 뒤에 수들을 더해도 항상 K이상이므로 
오른쪽 포인터를 더이상 이동시키지 않고 N - 오른쪽 포인터 해서 개수를 카운트 한다.
그리고 왼쪽 포인터를 증가시켜서 합을 지우고 다시 오른쪽 포인터를 이동 시킨다.
*/

int main()
{
    scanf("%lld %lld", &N, &K);
    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
    }
    int l, r;
    l = -1;
    r = -1;
    while(l <= r && r < N)
    {
        if(Sum >= K)
        {
            //개수 카운트
            result += N - r;
            Sum -= arr[++l];
            continue;
        }
        Sum += arr[++r];
    }
    printf("%lld", result);
}