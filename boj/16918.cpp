#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x;
    int y;
}Data;
int R, C, N, chk[205][205];
char zone[205][205];
int arrX[4] = {0, 1, 0, -1};
int arrY[4] = {-1, 0, 1, 0};

/*
시간이 짝수일 때 빈자리에 폭탄들을 설치해 주고 홀수일 떄 해당 시간에 터지는 폭탄들을 처리해 주면 된다.
*/

int main()
{
    scanf("%d %d %d", &R, &C, &N);
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            scanf(" %c", &zone[i][j]);
            if(zone[i][j] == 'O')
            {
                //폭탄이 터지는 시간
                chk[i][j] = 1;
            }
        }
    }
    for(int k = 0; k < N - 1; k++)
    {
        for(int i = 1; i <= R; i++)
        {
            for(int j = 1; j <= C; j++)
            {
                //폭탄 설치
                if(k % 2 == 0)
                {
                    if(zone[i][j] == '.')
                    {
                        zone[i][j] = 'O';
                        chk[i][j] = k + 3;
                    }
                }
                else
                {
                    //터지는 폭탄인 경우
                    if(chk[i][j] == k)
                    {
                        chk[i][j] = 0;
                        //빈자리로 만듬
                        zone[i][j] = '.';
                        //4방향 확인
                        for(int l = 0; l < 4; l++)
                        {
                            zone[i + arrY[l]][j + arrX[l]] = '.';
                        }
                    }
                }
            }
        }
    }
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            printf("%c", zone[i][j]);
        }
        printf("\n");
    }
}