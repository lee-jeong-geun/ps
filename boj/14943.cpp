#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int N, human[100005], phuman[100005], mhuman[100005], pidx, midx;
long long result;

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &human[i]);
        if(human[i] > 0)
        {
            phuman[pidx++] = i;
        }
        else
        {
            human[i] *= -1;
            mhuman[midx++] = i;
        }
    }
    int idx = 0;
    for(int i = 0; i < pidx; i++)
    {
        while(1)
        {
            if(human[phuman[i]] == 0)
            {
                break;
            }
            if(human[phuman[i]] <= human[mhuman[idx]])
            {
                human[mhuman[idx]] -= human[phuman[i]];
                result += abs(phuman[i] - mhuman[idx]) * human[phuman[i]];
                human[phuman[i]] = 0;
            }
            else
            {
                human[phuman[i]] -= human[mhuman[idx]];
                result += abs(phuman[i] - mhuman[idx]) * human[mhuman[idx]];
                human[mhuman[idx]] = 0;
            }
            if(human[mhuman[idx]] == 0)
            {
                idx++;
            }
        }
    }
    printf("%lld", result);
}