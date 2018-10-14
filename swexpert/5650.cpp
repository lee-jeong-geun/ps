#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int x[5];
    int y[5];
    int idx;
}Data;
Data worm[15];
int blockDir[6][4] = {{0, 0, 0, 0}, {2, 3, 1, 0}, {1, 3, 0, 2}, {3, 2, 0, 1}, {2, 0, 3, 1}, {2, 3, 0, 1}};
int N, zone[105][105], result;
int arrA[4] = {0, 1, 0, -1};
int arrB[4] = {-1, 0, 1, 0};

/*
주어진 조건에 맞게 구현 하면 된다.
*/

void init()
{
    for(int i = 6; i <= 10; i++)
    {
        worm[i].idx = 0;
    }
    result = 0;
}

int func(int x, int y, int dir)
{
    int tx, ty, count = 0;
    tx = x;
    ty = y;
    //시뮬레이션
    while(1)
    {
        tx = tx + arrA[dir];
        ty = ty + arrB[dir];
        //맵 밖이라면 방향을 반대로
        if(tx < 0 || tx == N || ty < 0 || ty == N)
        {
            dir = (dir + 2) % 4;
            count++;
            continue;
        }
        //탈출 조건
        if(tx == x && ty == y || zone[ty][tx] == -1)
        {
            return count;
        }
        //웜홀이라면 다른 짝으로 넘어감
        if(zone[ty][tx] >= 6)
        {
            int tempx, tempy;
            tempx = tx;
            tempy = ty;
            if(tx == worm[zone[ty][tx]].x[0] && ty == worm[zone[ty][tx]].y[0])
            {
                tx = worm[zone[tempy][tempx]].x[1];
                ty = worm[zone[tempy][tempx]].y[1];
            }
            else
            {
                tx = worm[zone[tempy][tempx]].x[0];
                ty = worm[zone[tempy][tempx]].y[0];
            }
        }
        //벽이라면 튕겨나감
        else if(zone[ty][tx] > 0)
        {
            count++;
            dir = blockDir[zone[ty][tx]][dir];
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        init();
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                scanf("%d", &zone[i][j]);
                //웜홀일 경우
                if(zone[i][j] >= 6)
                {
                    worm[zone[i][j]].x[worm[zone[i][j]].idx] = j;
                    worm[zone[i][j]].y[worm[zone[i][j]].idx++] = i;
                }
            }
        }
        //맵전체를 탐색
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                //빈곳일 경우만 탐색
                if(zone[i][j] == 0)
                {
                    //4방향으로 탐색
                    for(int k = 0; k < 4; k++)
                    {
                        result = max(result, func(j, i, k));
                    }
                }
            }
        }
        printf("#%d %d\n", testcase, result);
    }
}