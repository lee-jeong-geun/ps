#include <cstdio>
#include <iostream>
using namespace std;
int a, b, GCD;

int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        int i;
        scanf("%d %d", &a, &b);
        i = b / a + 1;
        while(a != 1)
        {
            a = a * i - b;
            b = b * i;
            i = b / a + 1;
            GCD = gcd(a, b);
            a = a / GCD;
            b = b / GCD;
        }
        printf("%d\n", b);
    }
}