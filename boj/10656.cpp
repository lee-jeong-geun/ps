#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x;
    int y;
}Data;
Data result[2005];
int N, M, ridx;
char zone[55][55];
int arrX[4] = {0, 1, 0, -1};
int arrY[4] = {-1, 0, 1, 0};

/*
주어진 조건에 맞게 구현하면 된다.
*/

//가로 세로 확인
int func(int x, int y)
{
    for(int i = 1; i <= 2; i++)
    {
        int xx, yy, nextx, nexty, count = 0;
        xx = x + arrX[(i + 2) % 4];
        yy = y + arrY[(i + 2) % 4];
        //단서의 시작점인지 확인
        if(xx == -1 || yy == -1 || zone[yy][xx] == '#')
        {
            nextx = x;
            nexty = y;
            //2칸 비어있는지 확인
            for(int j = 0; j < 2; j++)
            {
                nextx += arrX[i];
                nexty += arrY[i];
                if(nextx >= 0 && nextx < M && nexty >= 0 && nexty < N && zone[nexty][nextx] == '.')
                {
                    count++;
                }
            }
            if(count == 2)
            {
                return 1;
            }
        }
    }
    return 0;
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
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(zone[i][j] == '.' )
            {
                if(func(j, i) == 1)
                {
                    result[ridx].x = j + 1;
                    result[ridx++].y = i + 1;
                }
            }
        }
    }
    printf("%d\n", ridx);
    for(int i = 0; i < ridx; i++)
    {
        printf("%d %d\n", result[i].y, result[i].x);
    }
}