#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, candy[2][105], result;

/*
x길이가 100밖에 안되고 y도 2밖에 안되므로 완탐 돌려도 무방하다.
*/

void func(int x, int y, int count)
{
    if(x == N - 1 && y == 1)
    {
        result = max(result, count + candy[y][x]);
        return;
    }
    if(x != N - 1)
    {
        func(x + 1, y, count + candy[y][x]);
    }
    if(y == 0)
    {
        func(x, y + 1, count + candy[y][x]);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &candy[i][j]);
        }
    }
    func(0, 0, 0);
    printf("%d", result);
}