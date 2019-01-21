#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, Num[100005];

/*
수 하나를 제거해서 최대값 - 최소값을 최소화 시켜야 한다.
최소값과 최대값의 차이를 줄이기 위해서는 최소값을 제거하거나
최대값을 제거해야 한다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Num[i]);
    }
    sort(Num, Num + n);
    printf("%d", min(Num[n - 2] - Num[0], Num[n - 1] - Num[1]));
}