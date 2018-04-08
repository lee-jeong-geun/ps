#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, door[100005];
long long result;

/*
모든 손님이 끝나는 시간은 손님을 기준으로 시뮬레이션을 돌린다면 마지막 손님이 끝나는 시간이 된다.
하지만 손님은 최대 10억명이 입력으로 들어오기 때문에 할 수 없다.
각각의 심사대는 심사를 끝내자 마자 바로 다음 손님을 받을수 있기때문에 x초때 모든 심사대에서 각각 몇명을
심사했는지를 구하면 된다. 따라서 시간을 기준으로 이분탐색을 돌리면 된다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        result = 0;
        scanf("%d %d", &N, &M);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &door[i]);
        }
        long long l, r, mid, count = 0;
        l = 1;
        r = 1000000000000000000;
        while(l <= r)
        {
            count = 0;
            mid = (l + r) / 2;
            //mid시간때 몇명을 심사했는지 구함
            for(int i = 0; i < N; i++)
            {
                count += mid / door[i];
                //기준보다 더 구했을시 더이상 볼필요 없음
                if(count >= M)
                {
                    break;
                }
            }
            //기준 보다 더 구했다면 시간을 줄임
            if(count >= M)
            {
                result = mid;
                r = mid - 1;
            }
            //못 구했다면 시간을 늘림
            else
            {
                l = mid + 1;
            }
        }
        printf("#%d %lld\n", testcase, result);
    }
}