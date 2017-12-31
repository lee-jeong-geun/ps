#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int Max, Min, l, n;

/*
개미가 방향을 바꿔서 돌아가나 그냥 가나 똑같다
따라서 가장 빠른 시간은 개미들 중에서 가장 빨리 도착지까지 가는 시간중 최대값이고
가장 늦은 시간은 개미들 중에서 가장 늦게 도착지까지 가는 시간중 최댓값이다.
*/
int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        Max = 0;
        Min = 0;
        scanf("%d %d", &l, &n);
        for(int i = 0; i < n; i++)
        {
            int num;
            scanf("%d", &num);
            Max = max(Max, min(l - num, num - 0));
            Min = max(Min, max(l - num, num - 0));
        }
        printf("%d %d\n", Max, Min);
    }
}