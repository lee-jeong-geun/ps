#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a, b, c;
long long result;

/*
ab는 어떻게 두든 항상 옳으므로 상관없고 a, b는 a와 b의 차이가 2를 넘어가게 되면 
차이만큼 큰쪽의 개수가 무용지물이 되므로 차이가 2를 넘을 경우 둘중 작은 값 * 2 + 1을 하면 된다.
*/

int main()
{
    scanf("%d %d %d", &a, &b, &c);
    result = c * 2;
    if(a + 1 < b)
    {
        result += a * 2 + 1;
    }
    else if(a > b + 1)
    {
        result += b * 2 + 1;
    }
    else
    {
        result += a + b;
    }
    printf("%lld", result);
}