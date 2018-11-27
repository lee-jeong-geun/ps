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
Data point[505];
int N, K, memo[505][505];

/*
500개중에서 처음과 끝 2개를 제외한 498개중에서 K개를 제외한 것들중 최소값을 찾는 것이므로 498 C K 개의 경우의 수들 중에서 찾는 것이다.
잘보면 어떤 체크포인트에 도달 했을때 x번을 건너뛴 상태에 대하여 메모이제이션을 할 수 있다.
d[idx][x] = min(d[idx][x], 0이상을 건너 뛰었을때의 값)의 점화식이 나오게 된다.
*/

//거리 구함
int distance(int a, int b)
{
    return abs(point[a].x - point[b].x) + abs(point[a].y - point[b].y);
}

int func(int depth, int count)
{
    //맨 마지막 체크포인트일 경우
    if(depth == N - 1)
    {
        return 0;
    }
    int &ret = memo[depth][count];
    if(ret != -1)
    {
        return ret;
    }
    ret = 987654321;
    //건너뛰지 않음
    ret = min(ret, func(depth + 1, count) + distance(depth, depth + 1));
    //1칸이상 건너뜀
    for(int i = 1; i <= count; i++)
    {
        //건너뛰었을때 마지막 체크포인트 보다 크다면
        if(depth + i + 1 > N - 1)
        {
            break;
        }
        ret = min(ret, func(depth + i + 1, count - i) + distance(depth, depth + i + 1));
    }
    return ret;
}

int main()
{
    memset(memo, -1, sizeof memo);
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &point[i].x, &point[i].y);
    }
    printf("%d", func(0, K));
}