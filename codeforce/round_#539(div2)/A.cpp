#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, v, result, oil;

/*
최소로 도착지까지 가면 된다.
현재 기름으로 도착지를 못가면 충전하면 된다.
*/

int main()
{
    scanf("%d %d", &n, &v);
    result = min(n - 1, v);
    int oil = 2;
    for(int i = v; i < n - 1; i++)
    {
        result += oil;
        oil++;
    }
    printf("%d", result);
}