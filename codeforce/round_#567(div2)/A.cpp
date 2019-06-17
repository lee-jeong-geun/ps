#include <bits/stdc++.h>
using namespace std;
long long x, y, z, result, result2;

/*
x와 y를 이용하여 최대한 산다음 남은 x와y를 합쳐서 더 산다.
이때 나머지가 큰쪽으로 작은걸 줘서 산다.
*/

int main()
{
    scanf("%lld %lld %lld", &x, &y, &z);
    //최대한 사는 개수
    result = x / z + y / z;
    //나머지만 남김
    x %= z;
    y %= z;
    //합쳤을때 더 살 수있는지
    if((x + y) / z > 0)
    {
        result += (x + y) / z;
        //필요한 개수만 추출
        if(x > y)
            result2 = y - (x + y) % z;
        else
            result2 = x - (x + y) % z;
    }
    printf("%lld %lld", result, result2);
}