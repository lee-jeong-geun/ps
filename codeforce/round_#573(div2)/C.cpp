#include <bits/stdc++.h>
using namespace std;
long long n, m, k, arr[100005], result, Count;

/*
m개의 수들이 n을 k로 나눴을 때 어떤 구간에 있는지 확인 하면 된다.
*/

int main()
{
    scanf("%lld %lld %lld", &n, &m, &k);
    for(int i = 0; i < m; i++)
    {
        scanf("%lld", &arr[i]);
    }
    int idx = 0, tcount;
    while(1)
    {
        result++;
        long long temp;
        //맨 앞에 있는 수의 구간
        temp = (arr[idx] - 1 - Count) / k;
        tcount = 0;
        for(int i = idx; i < m; i++)
        {
            //해당 구간에 속한 수들을 전부 제거
            if((arr[i] - 1 - Count) / k != temp)
            {
                idx = i;
                break;
            }
            tcount++;
        }
        Count += tcount;
        if(Count == m)
            break;
    }
    printf("%lld", result);
}