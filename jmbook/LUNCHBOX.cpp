#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int M;
    int E;
}Data;
Data lunchBox[10005];
int N, result;

bool comp(Data t, Data u)
{
    return t.E > u.E;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        result = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &lunchBox[i].M);
        }
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &lunchBox[i].E);
        }
        sort(lunchBox, lunchBox + N, comp);
        int hap = 0;
        for(int i = 0; i < N; i++)
        {
            hap += lunchBox[i].M;
            result = max(result, hap + lunchBox[i].E);
        }
        printf("%d\n", result);
    }
}