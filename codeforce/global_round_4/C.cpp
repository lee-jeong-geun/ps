#include <bits/stdc++.h>
using namespace std;
int w, h, result = 1;

/*
규칙을 잘 보면 2를 행+열 만큼 곱하면 된다.
*/

int main()
{
    scanf("%d %d", &w, &h);
    for(int i = 0; i < w + h; i++)
    {
        result = (result * 2) % 998244353;
    }
    printf("%d", result);
}