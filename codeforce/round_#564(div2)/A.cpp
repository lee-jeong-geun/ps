#include <cstdio>
#include <iostream>
using namespace std;
int x, y, z;

/*
문제에 조건에 맞게 구현 하면 된다.
*/

int main()
{
    scanf("%d %d %d", &x, &y, &z);
    if(x > y + z)
    {
        printf("+");
    }
    else if(x + z < y)
    {
        printf("-");
    }
    else if(x == y && z == 0)
    {
        printf("0");
    }
    else
    {
        printf("?");
    }
}