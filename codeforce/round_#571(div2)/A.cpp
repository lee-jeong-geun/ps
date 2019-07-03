#include <bits/stdc++.h>
using namespace std;
int n, m, k;

/*
단순하게 비교만 해주면 된다.
*/

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    if(n <= m && n <= k)
        printf("Yes");
    else
        printf("No");
}