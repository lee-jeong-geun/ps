#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, Num[300005], m;
long long Sum;

/*
전부 더하고 q번째 값을 뺐을때 결과를 출력하면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Num[i]);
        Sum += Num[i];
    }
    sort(Num, Num + n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        int q;
        scanf("%d", &q);
        printf("%lld\n", Sum - Num[n - q]);
    }
}