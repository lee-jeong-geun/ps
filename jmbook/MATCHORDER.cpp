#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, R[105], K[105], result;

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        result = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &R[i]);
        }
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &K[i]);
        }
        sort(R, R + N);
        sort(K, K + N);
        int l, r;
        l = 0;
        r = 0;
        while(l < N && r < N)
        {
            if(R[l] <= K[r])
            {
                result++;
                l++;
            }
            r++;
        }
        printf("%d\n", result);
    }
}