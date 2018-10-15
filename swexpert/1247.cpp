#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct _data
{
    int x;
    int y;
}Data;
Data Point[15];
int N, memo[15][2055];

/*
회사에서 고객들을 다 돌고 집으로 돌아올 때 최소 값을 저장하면 찾으면 된다.
회사 - 고객들 - 집 이런 방식이다.
회사를 0이라 하고 고객을 1 ~ 4 집을 5라고 한다면
0 1 2 3 4 5 or 0 1 2 4 3 5 or 0 1 3 2 4 5 이렇게
고객들을 탐색 할 때 어떤 고객에서 어떤 고객으로는 못가는 조건이 없기 때문에
모든 경우의 수를 나열하면 N! 즉 순열이 된다.
비트마스크를 이용하여 메모이제이션을 해서 풀면 된다.
*/

//거리 계산 함수
int distance(int a, int b)
{
    return abs(Point[a].x - Point[b].x) + abs(Point[a].y - Point[b].y);
}

int func(int idx, int state)
{
    //집 도착시 리턴
    if(idx == N + 1)
    {
        return 0;
    }
    int &ret = memo[idx][state];
    if(ret != -1)
    {
        return ret;
    }
    ret = 987654321;
    //모든 고객들을 다 돌았을 경우 집으로 이동
    if(state == (1 << (N + 1)) - 2)
    {
        ret = min(ret, func(N + 1, state) + distance(idx, N + 1));
    }
    for(int i = 1; i <= N; i++)
    {
        //해당 고객을 안골랐을 경우
        if((state & (1 << i)) != (1 << i))
        {
            ret = min(ret, func(i, state | (1 << i)) + distance(idx, i));
        }
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        memset(memo, -1, sizeof memo);
        scanf("%d", &N);
        //회사와 집을 입력
        scanf("%d %d", &Point[0].x, &Point[0].y);
        scanf("%d %d", &Point[1].x, &Point[1].y);
        for(int i = 2; i < N + 2; i++)
        {
            scanf("%d %d", &Point[i].x, &Point[i].y);
        }
        //집과 마지막 고객 스왑
        swap(Point[1], Point[N + 1]);
        printf("#%d %d\n", testcase, func(0, 0));
    }
}