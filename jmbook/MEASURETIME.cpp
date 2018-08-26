#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, A[50005], fenwick[1000005];
long long result;

int sum(int idx)
{
    idx++;
    int hap = 0;
    while(idx > 0)
    {
        hap += fenwick[idx];
        idx &= (idx - 1);
    }
    return hap;
}

void update(int idx, int num)
{
    idx++;
    while(idx <= 1000000)
    {
        fenwick[idx] += num;
        idx += (idx & -idx);
    }
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        memset(fenwick, 0, sizeof fenwick);
        result = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &A[i]);
        }
        for(int i = 0; i < N; i++)
        {
            result += sum(999999) - sum(A[i]);
            update(A[i], 1);
        }
        printf("%lld\n", result);
    }
}