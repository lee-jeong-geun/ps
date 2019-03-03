#include <cstdio>
#include <iostream>
using namespace std;
int N, M, result, chk[55][55];
char zone[55][55];
int arrX[4] = {0, 1, 0, -1};
int arrY[4] = {-1, 0, 1, 0};

/*
사이클이 생기는지 확인하면 된다.
*/

void func(int depth, int x, int y, int dir)
{
    //사이클 조건
    if(depth >= 4 && chk[y][x] == 1)
    {
        result = 1;
    }
    if(chk[y][x] == 1)
    {
        return;
    }
    chk[y][x] = 1;
    for(int i = 0; i < 4; i++)
    {
        //바로 전으로 돌아가지 않음
        if(i == (dir + 2) % 4)
        {
            continue;
        }
        int nextx, nexty;
        nextx = x + arrX[i];
        nexty = y + arrY[i];
        //같은 블록인 경우
        if(zone[nexty][nextx] == zone[y][x])
        {
            func(depth + 1, nextx, nexty, i);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            scanf(" %c", &zone[i][j]);
        }
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            //한번도 가지 않았고 결과가 나오지 않은 경우
            if(chk[i][j] == 0 && result == 0)
            {
                func(0, j, i, 2);
            }
        }
    }
    if(result == 1)
    {
        printf("Yes");
        return 0;
    }
    printf("No");
}