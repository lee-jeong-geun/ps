#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, K, Sum[100005], result = -987654321;

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++)
    {
        int num;
        scanf("%d", &num);
        Sum[i] = Sum[i - 1] + num;
    }
    int l, r;
    l = 0;
    r = K;
    while(r <= N)
    {
        result = max(result, Sum[r] - Sum[l]);
        r++;
        l++;
    }
    printf("%d", result);
}