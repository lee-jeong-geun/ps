#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int K, N;
long long LAN[10005], result;

/*
범위가 크기 때문에 brute force하게 접근하면 시간 초과가 나기 때문에
랜선 길이에 대해서 이분탐색으로 해당 길이로 N개 이상을 만들수 있다면 길이를 더 늘리고
못 만든다면 길이를 줄인다.
*/

int main()
{
    scanf("%d %d", &K, &N);
    for(int i = 0; i < K; i++)
    {
        scanf("%lld", &LAN[i]);
    }
    long long l, r;
    l = 0;
    r = 2276543210;
    while(l <= r)
    {
        long long count = 0, mid;
        mid = (l + r) / 2;
        for(int i = 0; i < K; i++)
        {
            //해당 길이로 랜선 하나를 몇개로 만들수 있는지 확인
            count += LAN[i] / mid;
        }
        //N개 이상일시 길이를 더 늘림
        if(count >= N)
        {
            result = max(result, mid);
            l = mid + 1;
        }
        //N개를 못 만들시 길이를 줄임
        else
        {
            r = mid - 1;
        }
    }
    printf("%lld", result);
}