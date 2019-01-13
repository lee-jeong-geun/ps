#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int L;
    int M;
    int G;
}Data;
typedef struct _data2
{
    int idx;
    int start;
    int end;
}Data2;
Data city[5005];
Data2 cityPoint[5005];
int N, K, result;
long long Sum[5005];

bool comp(Data2 &t, Data2 &u)
{
    if(t.end == u.end)
    {
        return t.start < u.start;
    }
    return t.end < u.end;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        scanf("%d %d", &N, &K);
        for(int i = 0; i < N; i++)
        {
            scanf("%d %d %d", &city[i].L, &city[i].M, &city[i].G);
            cityPoint[i].idx = i;
            cityPoint[i].start = city[i].L - city[i].M;
            cityPoint[i].end = city[i].L;
            Sum[i] = 0;
        }
        sort(cityPoint, cityPoint + N, comp);
        Sum[0] = city[cityPoint[0].idx].M / city[cityPoint[0].idx].G + 1;
        for(int i = 1; i < N; i++)
        {
            Sum[i] = Sum[i - 1] + city[cityPoint[i].idx].M / city[cityPoint[i].idx].G + 1;
        }
        int l, r, ll, rr;
        l = 0;
        r = 8030000;
        while(l <= r)
        {
            int mid, point = -1;
            long long hap = 0;
            mid = (l + r) / 2;
            ll = 0;
            rr = N - 1;
            while(ll <= rr)
            {
                int mid2;
                mid2 = (ll + rr) / 2;
                if(cityPoint[mid2].end <= mid)
                {
                    point = mid2;
                    ll = mid2 + 1;
                }
                else
                {
                    rr = mid2 - 1;
                }
            }
            if(point != -1)
            {
                hap = Sum[point];
            }
            if(hap >= K)
            {
                result = mid;
                r = mid - 1;
                continue;
            }
            for(int i = point + 1; i < N; i++)
            {
                if(cityPoint[i].start <= mid && mid <= cityPoint[i].end)
                {
                    hap += (mid - cityPoint[i].start) / city[cityPoint[i].idx].G + 1;
                }
            }
            if(hap >= K)
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        printf("%d\n", result);
    }
}