#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
double camera[205], result;

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        result = 0;
        scanf("%d %d", &N, &M);
        for(int i = 0; i < M; i++)
        {
            scanf("%lf", &camera[i]);
        }
        double l, r;
        l = 0;
        r = 240.0;
        while(l < r)
        {
            int count = 1, ll, rr;
            ll = 0;
            rr = 1;
            double mid = (l + r) / 2;
            while(rr < M)
            {
                if(camera[rr] - camera[ll] >= mid)
                {
                    count++;
                    ll = rr;
                }
                rr++;
            }
            if(count >= N)
            {
                result = max(result, mid);
                l = mid + 0.001;
            }
            else
            {
                r = mid - 0.001;
            }
        }
        printf("%0.2lf\n", result);
    }
}