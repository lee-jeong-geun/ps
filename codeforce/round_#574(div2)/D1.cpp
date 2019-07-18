#include <bits/stdc++.h>
using namespace std;
long long n, arr[100005], mod = 998244353, result;
 
/*
규칙을 잘 보면 어떤 수 ai는 a(1 ~ n)까지에 대해서 매칭을 시킬 때 항상 같은 자리에 수가 들어간다.
예를 들어 123을 a(1 ~ n)까지 매칭 시킬 때 123은 항상 102030의 형식으로 만들어 진다.
그래서 123을 102030형식으로 만든 후 여기에 n을 곱하면 123으로 a(1 ~ n)까지 매칭을 시킨 결과의 합을
구할 수 있다. 다른 수들도 마찬가지로 이방법으로 구하면 된다.
그리고 하나더 구해야 하는데 123은 010203이라는 형식으로도 매칭이 된다. 이것은 a(1 ~ n)까지의 수들이
123과 매칭될 때 된다. 그래서 10203의 형식으로 만든 후 n을 곱하면 된다.
*/

//12를 1020 또는 102로 만드는 함수
long long func(long long num, long long mode)
{
    unsigned long long ret = 0, count = 0, temp, div1 = 1, div2 = 1;
    temp = num;
    while(temp != 0)
    {
        count++;
        div2 *= 10;
        temp /= 10;
    }
    //div1은 unsigned long long을 초과 할 수 있으므로 한번에 구하기 보다 나눠서 구한 후 곱함
    div1 = div2 / 10 * div2;
    div2 /= 10;
    temp = num;
    for(int i = 0; i < count; i++)
    {
        ret += temp / div2 * div1;
        temp %= div2;
        div1 /= 100;
        div2 /= 10;
    }
    return ret / mode % mod;
}
 
int main()
{
    scanf("%lld", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        result = (result + func(arr[i], 1) * n) % mod;
        result = (result + func(arr[i], 10) * n) % mod;
    }
    printf("%lld", result % mod);
}