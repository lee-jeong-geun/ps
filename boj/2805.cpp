#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, result;
long long Tree[1000005];

/*
범위가 너무 크기 때문에 brute force하게 풀면 시간 초과 난다.
높이에 대해서 이분탐색으로 해당 높이에 M미터 이상 나무를 얻지 못하면 높이를 줄이고
나무를 얻는 다면 높이를 높인다.
*/

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &Tree[i]);
    }
    int l, r;
    l = 0;
    r = 1000000000;
    while(l <= r)
    {
        int mid;
        long long hap = 0;
        mid = (l + r) / 2;
        for(int i = 0; i < N; i++)
        {
            //해당 나무보다 높이가 높다면 자르지 못함
            if(Tree[i] - mid > 0)
            {
                hap += Tree[i] - mid;
            }
        }
        //M미터 이상 가능시 높이를 높임
        if(hap >= M)
        {
            result = max(result, mid);
            l = mid + 1;
        }
        //불가능시 높이를 줄임
        else
        {
            r = mid - 1;
        }        
    }
    printf("%d", result);
}