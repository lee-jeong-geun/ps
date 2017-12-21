#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Minx, Miny, Maxx, Maxy, dir, tx, ty, zone[125][125];
int arrA[4] = {0, 1, 0, -1};
int arrB[4] = {-1, 0, 1, 0};

int main()
{
    tx = 60;
    ty = 60;
    dir = 2;
    Minx = tx;
    Maxx = tx;
    Miny = ty;
    Maxy = ty;
    scanf("%d", &N);
    zone[ty][tx] = 1;
    for(int i = 0; i < N; i++)
    {
        char move;
        scanf(" %c", &move);
        if(move == 'R')
        {
            dir = (dir + 1) % 4;
        }
        else if(move == 'L')
        {
            dir = (dir + 3) % 4;
        }
        else
        {
            tx += arrA[dir];
            ty += arrB[dir];
        }
        zone[ty][tx] = 1;
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