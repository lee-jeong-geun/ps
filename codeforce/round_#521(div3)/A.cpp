#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int t;
long long result;

/*
k / 2번 만큼 오른쪽으로 가고 k / 2번 만큼 왼쪽으로 가는데 k % 2 == 1이라면 오른쪽으로 한번
더 가면 된다.
*/

int main()
{
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);
        result = (long long)b * (k / 2) * -1;
        result += (long long)a * (k / 2);
        if(k % 2 == 1)
        {
            result += a;
        }
        printf("%lld\n", result);
    }
}