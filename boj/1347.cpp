#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Minx, Miny, Maxx, Maxy, dir, tx, ty, zone[125][125];
int arrA[4] = {0, 1, 0, -1};
int arrB[4] = {-1, 0, 1, 0};

int main()
{
    //최대 50번 직진 할수있고 상하좌우 다 가능하기 떄문에 맵을 120 by 120으로 잡아 놓고 중간 지점으로
    //초기화 하였다.
    tx = 60;    //초기 위치
    ty = 60;    //초기 위치
    dir = 2;    //이동방향
    Minx = tx;
    Maxx = tx;
    Miny = ty;
    Maxy = ty;
    scanf("%d", &N);
    zone[ty][tx] = 1;   //지나온길은 1로 체크
    for(int i = 0; i < N; i++)
    {
        char move;
        scanf(" %c", &move);
        //우회전
        if(move == 'R')
        {
            dir = (dir + 1) % 4;
        }
        //좌회전
        else if(move == 'L')
        {
            dir = (dir + 3) % 4;
        }
        //직진
        else
        {
            tx += arrA[dir];
            ty += arrB[dir];
        }
        zone[ty][tx] = 1;
        //출력을 위해서 최소값 최대값 갱신
        Minx = min(Minx, tx);
        Maxx = max(Maxx, tx);
        Miny = min(Miny, ty);
        Maxy = max(Maxy, ty);
    }
    for(int i = Miny; i <= Maxy; i++)
    {
        for(int j = Minx; j <= Maxx; j++)
        {
            if(zone[i][j] == 0)
            {
                printf("#");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}