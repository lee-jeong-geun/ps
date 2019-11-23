#include <bits/stdc++.h>
using namespace std;
int X, Y, n, r, mod = 1000000007;
long long result = 1, rfact = 1, nrfact = 1;

/*
(0, 0)에서 주어진 이동 (x + 1, y + 2), (x + 2, y + 1)을 이용하여 (X, Y)로 가야한다.
1번 이동은 x + 1, 2번 이동은 x + 2이므로 1번 이동을 A로 잡고 2번 이동을 B로 잡는다면
A + 2B = X를 만족 시켜야 하고 y + 2, y + 1이므로 2A + B = Y를 만족 시켜야 한다.
그리고 항상 3칸씩 이동하게 되므로 X, Y는 3의 배수여야 한다.
위의 연립방정식을 이용해 구한 A, B는 순서에 상관없이 (0, 0)에서 (X, Y)로 보낼 수 있는
명령의 집합이다. 예를 들어 A가 4, B가 2라면 1번 연산을 4번, 2번연산을 2번 이용하면
(X, Y)로 명령 순서에 상관없이 보낼 수 있다. 따라서 A, B의 조합을 구하면 된다.
(A + B)C(A)의 조합을 구하면 된다. A + B는 많이 커질 수 있는 관계로 O(N^2)조합을 구하는 방법 말고
페르마의 소정리를 이용해서 구하면 된다.
*/

//log n만에 지수 구하기
long long func(long long num, int count)
{
    if(count == 1)
        return num;
    long long temp;
    temp = func(num, count / 2) % mod;
    temp = (temp % mod * temp % mod) % mod;
    if(count % 2 != 0)
        temp = temp * num % mod;
    return temp;
}

int main()
{
    scanf("%d %d", &X, &Y);
    n = (X + Y) / 3;
    r = Y - n;
    //3의 배수가 아니거나 X - n or Y - n이 0이상이여야 함
    if((X + Y) % 3 != 0 || min(X, Y) < n)
    {
        printf("0");
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        result = (result * i) % mod;
    }
    for(int i = 1; i <= r; i++)
    {
        rfact = (rfact * i) % mod;
    }
    for(int i = 1; i <= n - r; i++)
    {
        nrfact = (nrfact * i) % mod;
    }
    //페르마의 소정리
    result = (result * func(rfact, mod - 2) % mod * func(nrfact, mod - 2) % mod) % mod;
    printf("%d", result);
}