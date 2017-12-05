#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int N, M, Sx, Sy, Max = -1, result, chk[505][505], Voflag;
char zone[505][505], rprint[5] = {'U', 'R', 'D', 'L'};
int arrA[4] = {0, 1, 0, -1};
int arrB[4] = {-1, 0, 1, 0};
int pointA[4] = {1, 0, 3, 2};
int pointB[4] = {3, 2, 1, 0};

int range(int a, int b)
{
    if(a >= 0 && a < M && b >= 0 && b < N)
    {
        return 1;
    }
    return 0;
}

void func()
{
    Sx--;
    Sy--;
    for(int i = 0; i < 4; i++)
    {
        memset(chk, 0, sizeof chk);
        int point, tempx, tempy, count = 0;
        tempx = Sx;
        tempy = Sy;
        point = i;
        while(1)
        {
            if(Max < count)
            {
                Max = count;
                result = i;
            }
            if(zone[tempy][tempx] == 'C' || range(tempx, tempy) == 0)
            {
                break;
            }
            if(chk[tempy][tempx] == 2)
            {
                result = i;
                Voflag = 1;
                return;
            }
            chk[tempy][tempx]++;
            tempx += arrA[point];
            tempy += arrB[point];
            count++;
            if(zone[tempy][tempx] == '/')
            {
                point = pointA[point];
            }
            else if(zone[tempy][tempx] == '\\')
            {
                point = pointB[point];
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%s", zone[i]);
    }
    scanf("%d %d", &Sy, &Sx);
    func();
    printf("%c\n", rprint[result]);
    if(Voflag == 0)
    {
        printf("%d", Max);
    }
    else
    {
        printf("Voyager");
    }
}