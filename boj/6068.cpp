#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int Time;
    int end;
}Data;
Data work[1005];
int N, endTime;

/*
끝내야하는 시간을 기준으로 정렬 후 가장 늦게 끝내도 되는 일부터 차근차근 접근한다.
늦게 끝나는 것들을 부터 먼저 처리를 하면 마지막 일을 처리하고 남은 시간을 다 쉴수 있게 된다.
처리 할 때 0보다 작아지면 해당 일들을 다 끝내지 못하게 된다는 뜻이므로 -1을 출력 시키면 된다.
*/

bool comp(Data t, Data u)
{
    return t.end > u.end;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &work[i].Time, &work[i].end);
    }
    sort(work, work + N, comp);
    endTime = work[0].end;
    for(int i = 0; i < N; i++)
    {
        //min(현재까지 일을 완수해서 최대 쉴수 있는시간, 끝내야 하는 시간)에서 필요한 시간을 뺐을때 0보다
        //작으면 해당 일을 못끝낸다는 뜻
        if(min(endTime, work[i].end) - work[i].Time >= 0)
        {
            endTime = min(endTime, work[i].end) - work[i].Time;
        }
        else
        {
            endTime = -1;
            break;
        }
    }
    printf("%d", endTime);
}