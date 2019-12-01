#include <bits/stdc++.h>
using namespace std;
long long r, b, k, Gcd, Lcm;

/*
r, b의 최소공배수를 Lcm이라 했을때 r은 Lcm까지 (Lcm / r) - 1개의 수가 존재하게 되고
b는 Lcm까지 Lcm / b개의 수가 존재한다. r의 개수 / b의 개수를 하면 b하나당 몫만큼 
r의 수를 배정 받게 된다. 나머지가 존재한다면 몫 + 1을 시켜준 상태에서 k이상 이라면
REBEL 아니라면 OBEY를 출력하면 된다.
*/

long long gcd(long long a, long long b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int tc = 0; tc < T; tc++)
    {
        scanf("%lld %lld %lld", &r, &b, &k);
        if(r > b)
            swap(r, b);
        Gcd = gcd(r, b);
        Lcm = r * b / Gcd;
        r = Lcm / r - 1;
        b = Lcm / b;
        long long temp;
        temp = r / b;
        if(r % b != 0)
            temp++;
        if(temp >= k)
            printf("REBEL\n");
        else
            printf("OBEY\n");
    }
}