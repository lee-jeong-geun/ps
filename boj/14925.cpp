#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int M, N, zone[1005][1005], memo[1005][1005], result;
int arrX[3] = {1, 0, 1};
int arrY[3] = {0, 1, 1};

/*
현재 칸에서 만들수 있는 최대 정사각형 크기는 현재 칸에서 오른쪽, 아래쪽, 오른쪽 아래 대각선으로 
칸을 확장 했을때 0으로만 되어있는 부분들중에서 가장 작은 부분이다. 즉 다음 칸으로 갈때 현재 칸까지의
최대 크기 + 1을 하면 된다. 0이 아닌 부분을 만나면 0으로 만들어준다.
이 작업을 매번 하기에는 시간이 오래 걸리므로 dp[y][x] = min(dp[y][x], 다음 칸 + 1) 점화식으로 
메모이제이션 해주면 된다.
*/

int func(int x, int y)
{
    //0이아닌 경우 리턴
    if(zone[y][x] != 0 || x == N || y == M)
    {
        return 0;
    }
    int &ret = memo[y][x];
    if(ret != -1)
    {
        return ret;
    }
    ret = 987654321;
    for(int i = 0; i < 3; i++)
    {
        ret = min(ret, func(x + arrX[i], y + arrY[i]) + 1);
    }
    return ret;
}

int main()
{
    scanf("%d %d", &M, &N);
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &zone[i][j]);
        }
    }
    memset(memo, -1, sizeof memo);
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            result = max(result, func(j, i));
        }
    }
    printf("%d", result);
}