#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, maxObX = -987654321, maxObY = -987654321, minClX = 987654321, minClY = 987654321;

/*
최대 크기가 1000개라서 2중 포문으로 해결 가능하지만
잘보면 균형있게 매칭 시켜야 하므로 범위가 가장 차이나는 좌표들끼리 매칭 시켜 주면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        maxObX = max(maxObX, x);
        maxObY = max(maxObY, y);
    }
    for(int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        minClX = min(minClX, x);
        minClY = min(minClY, y);
    }
    printf("%d %d", maxObX + minClX, maxObY + minClY);
}