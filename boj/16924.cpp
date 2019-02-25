#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef struct _data
{
    int x;
    int y;
    int s;
}Data;
vector<Data> result;
int N, M, chk[105][105];
char zone[105][105];
int arrX[4] = {0, 1, 0, -1};
int arrY[4] = {-1, 0, 1, 0};

/*
모든 맵을 탐색하면서 *인 부분에서 십자가를 만들수 있는지 확인하면 된다.
만들수 있다면 chk배열에 chk를 하고 결과 벡터에 저장을 하면 된다.
다 확인 하고 마지막에 chk배열에 *인 부분에서 방문을 한적이 없다면 -1을 출력하면 된다.
*/

int chkZone(int x, int y, int size)
{
    //4방향 탐색
    for(int i = 0; i < 4; i++)
    {
        int nextx, nexty, count = 0;
        nextx = x + arrX[i] * size;
        nexty = y + arrY[i] * size;
        //조건에 만족하지 않으면 종료
        if(nextx < 0 || nextx >= M || nexty < 0 || nexty >= N || zone[nexty][nextx] != '*')
        {
            return 0;
        }
    }
    chk[y][x] = 1;
    //4방향 체크
    for(int i = 0; i < 4; i++)
    {
        int nextx, nexty;
        nextx = x + arrX[i] * size;
        nexty = y + arrY[i] * size;
        chk[nexty][nextx] = 1;
    }
    //결과배열에 저장
    result.push_back({x + 1, y + 1, size});
    return 1;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf(" %c", &zone[i][j]);
        }
    }
    for(int i = 1; i < N - 1; i++)
    {
        for(int j = 1; j < M - 1; j++)
        {
            int size = 1;
            if(zone[i][j] == '.')
            {
                continue;
            }
            //크기를 늘릴수 있다면 계속 늘림
            while(1)
            {
                if(!chkZone(j, i, size))
                {
                    break;
                }
                size++;
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            //*이면서 방문 한적이 없다면 -1
            if(zone[i][j] == '*' && chk[i][j] == 0)
            {
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d\n", result.size());
    for(int i = 0; i < result.size(); i++)
    {
        printf("%d %d %d\n", result[i].y, result[i].x, result[i].s);
    }
}