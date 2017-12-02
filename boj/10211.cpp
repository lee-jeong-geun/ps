#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, Sum[1005], result;

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        result = -987654321;
        memset(Sum, 0, sizeof Sum);
        scanf("%d", &N);
        for(int i = 1; i <= N; i++)
        {
            int num;
            scanf("%d", &num);
            Sum[i] = Sum[i - 1] + num;
        }
        int l, r;
        l = 0;
        r = 1;
        while(r <= N)
        {
            result = max(result, Sum[r] - Sum[l]);
            if(Sum[r] - Sum[l] < 0)
            {
                l = r;
            }
            r++;
        }
        printf("%d\n", result);
    }
}