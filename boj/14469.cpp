#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int start;
    int time;
}Data;
Data cow[105];
int N, result;

/*
정렬 후 현재 시간이랑 소들의 도착 시간을 비교후 더 큰 시간에 소들의 검문 시간을 더해주면 된다.
*/

bool comp(Data t, Data u)
{
    return t.start < u.start;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &cow[i].start, &cow[i].time);
    }
    sort(cow, cow + N, comp);
    for(int i = 0; i < N; i++)
    {
        result = max(result, cow[i].start) + cow[i].time;
    }
    printf("%d", result);
}