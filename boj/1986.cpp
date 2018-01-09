#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, y;
}Data;
Data queen[105], knight[105];
int n, m, Q, K, P, zone[1005][1005], chk[1005][1005], result;
int knA[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int knB[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int QuA[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int QuB[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

/*
단순 시뮬레이션 문제
각 체스 말들의 위치를 체크해주고 이동경로들을 체크 해주어서 전체 에서 빼면 된다.
*/

//맵 범위 확인
bool range(int a, int b)
{
    if(a >= 1 && a <= m && b >= 1 && b <= n)
    {
        return 1;
    }
    return 0;
}

//퀸 이동 함수
void func(Data num)
{
    for(int i = 0; i < 8; i++)
    {
        int nextx, nexty;
        nextx = num.x;
        nexty = num.y;
        while(1)
        {
            nextx += QuA[i];
            nexty += QuB[i];
            if(range(nextx, nexty) == 0 || zone[nexty][nextx] == 1)
            {
                break;
            }
            if(chk[nexty][nextx] == 0)
            {
                chk[nexty][nextx] = 1;
                result++;
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &Q);
    for(int i = 0; i < Q; i++)
    {
        scanf("%d %d", &queen[i].y, &queen[i].x);
        zone[queen[i].y][queen[i].x] = 1;
        result++;
    }
    scanf("%d", &K);
    for(int i = 0; i < K; i++)
    {
        scanf("%d %d", &knight[i].y, &knight[i].x);
        zone[knight[i].y][knight[i].x] = 1;
        result++;
    }
    scanf("%d", &P);
    for(int i = 0; i < P; i++)
    {
        int x, y;
        scanf("%d %d", &y, &x);
        zone[y][x] = 1;
        result++;
    }
    for(int i = 0; i < Q; i++)
    {
        func(queen[i]);
    }
    //나이트 이동
    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            int nextx, nexty;
            nextx = knight[i].x + knA[j];
            nexty = knight[i].y + knB[j];
            if(range(nextx, nexty) == 1 && chk[nexty][nextx] == 0 && zone[nexty][nextx] == 0)
            {
                chk[nexty][nextx] = 1;
                result++;
            }
        }
    }
    printf("%d", n * m - result);
}