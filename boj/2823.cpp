#include <cstdio>
#include <iostream>
using namespace std;
int R, C;
char zone[15][15];
int arrX[4] = {0, 1, 0, -1};
int arrY[4] = {-1, 0, 1, 0};

/*
현재 위치에서 4방향중 3방향 이상이 벽이거나 빌딩이라면 반드시 유턴을 해야 하는 상황이다.
따라서 모든 길에 대해 4방향중 3방향 이상이 벽이거나 빌딩인 길이 존재 한다면 1을 출력하면 된다.
*/

int main()
{
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            scanf(" %c", &zone[i][j]);
        }
    }
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(zone[i][j] == '.')
            {
                int count = 0;
                for(int k = 0; k < 4; k++)
                {
                    int nextx, nexty;
                    nextx = j + arrX[k];
                    nexty = i + arrY[k];
                    //벽이거나 빌딩인 경우
                    if(nextx < 0 || nextx >= C || nexty < 0 || nexty >= R || zone[nexty][nextx] == 'X')
                    {
                        count++;
                    }
                }
                //3방향 이상인 경우 유턴을 해야함
                if(count >= 3)
                {
                    printf("1");
                    return 0;
                }
            }
        }
    }
    printf("0");
}