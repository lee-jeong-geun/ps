#include <bits/stdc++.h>
using namespace std;
int N, M, arr[100005];
long long result;

/*
N개의 심사대에 M명의 사람을 잘 배치해서 걸리는 시간을 최소화 해야 한다.
N이 10만이고 M이 10억이므로 시뮬레이션으로는 불가능하다.
따라서 이분 탐색을 이용하여 x 시간일 때 M명을 다 배치 할 수 있는지 확인한다.
오버플로가 날 수 있어서 예외처리를 해주어야 한다.
*/

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    long long l, r;
    l = 0;
    r = 1000000000000000000;
    while(l <= r)
    {
        long long mid, Sum = 0;
        mid = (l + r) / 2;
        for(int i = 0; i < N; i++)
        {
            //오버플로 방지
            if(Sum >= M)
                break;
            Sum += mid / arr[i];
        }
        if(Sum >= M)
        {
            result = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    printf("%lld", result);
}