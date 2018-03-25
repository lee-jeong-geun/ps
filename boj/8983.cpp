#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int x, y;
}Data;
Data ani[100005];
int M, N, L, sand[100005], result;

/*
사대를 오름차순으로 정렬 시키고 각 동물들이 어떤 사대에 포함 되어있는지
사대를 이분탐색으로 찾으면 된다.
*/

int abs(int a)
{
    return a > 0 ? a : a * -1;
}

int main()
{
    scanf("%d %d %d", &M, &N, &L);
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &sand[i]);
    }
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &ani[i].x, &ani[i].y);
    }
    sort(sand, sand + M);
    int sandidx;
    for(int i = 0; i < N; i++)
    {
        int l, r;
        l = 0;
        r = M - 1;
        while(l <= r)
        {
            int mid;
            mid = (l + r) / 2;
            if(abs(sand[mid] - ani[i].x) + ani[i].y <= L)
            {
                sandidx = mid;
                break;
            }
            if(sand[mid] > ani[i].x)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if(abs(sand[sandidx] - ani[i].x) + ani[i].y <= L)
        {
            result++;
        }
    }
    printf("%d", result);
}