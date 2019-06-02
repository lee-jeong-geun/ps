#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a, x, b, y;

/*
시뮬레이션 하면서 만나는 경우가 있는지 확인하면 된다.
*/

int main()
{
    scanf("%d %d %d %d %d", &n, &a, &x, &b, &y);
    a--;
    x--;
    b--;
    y--;
    while(a != x && b != y)
    {
        if(a == b)
        {
            printf("YES");
            return 0;
        }
        a = (a + 1) % n;
        b = (b - 1 + n) % n;
    }
    if(a == b)
    {
        printf("YES");
        return 0;
    }
    printf("NO");
}