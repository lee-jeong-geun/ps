#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
set<long long> s;
int n;

/*
규칙을 잘 찾다보면 n의 약수들에 대해서만 값이 다르다. 즉 약수가 아닌 수들은 이미 약수들에서 나온
값을 가지고 있다. 따라서 n의 약수에 대하여 등차수열을 구해주면 된다.
*/

int main()
{
    scanf("%d", &n);
    int Sqrt = sqrt(n);
    long long temp;
    for(int i = 1; i <= Sqrt; i++)
    {
        //n / i와 i 동시에 다 구함
        if(n % i == 0)
        {
            long long div;
            div = n / i;
            temp = div * (2 + (div - 1) * i) / 2;
            s.insert(temp);
            temp = (long long)i * (2 + (i - 1) * div) / 2;
            s.insert(temp);
        }
    }
    for(auto it = s.begin(); it != s.end(); it++)
    {
        printf("%lld ", *it);
    }
}