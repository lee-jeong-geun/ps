#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/*
l <= x, y <= r 이고 x != y 이고 y % x == 0 인 x y를 찾아야 한다.
l도 x가 될 수 있으므로 l의 배수인 l * 2를 y로 두고 l을 x로 두면 된다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d %d\n", l, l * 2);
    }
}