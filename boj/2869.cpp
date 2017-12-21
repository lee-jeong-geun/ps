#include <cstdio>
#include <iostream>
using namespace std;
long long A, B, V, result;

//x일 일때 나무 막대 이상을 올라갔으면 right를 줄여주고 못올라갔으면 left를 높여준다.
int main()
{
    scanf("%lld %lld %lld", &A, &B, &V);
    long long l, r, mid;
    l = 0;
    r = 1000000000;
    //이분 탐색
    while(l <= r)
    {
        mid = (l + r) / 2;
        //밤에 미끄러 지므로 낮일때가 최고치이다 그래서 계산을할때 미끄러지는 부분을 하루치 빼준다.
        if(A * mid - B * (mid - 1) >= V)
        {
            result = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%lld", result);
}