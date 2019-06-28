#include <bits/stdc++.h>
using namespace std;
int n, m, flag;

/*
101010 이런식으로 번갈아 하는 방법으로 하면 정답이다.
*/

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d", flag);
        flag ^= 1;
    }
}