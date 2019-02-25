#include <cstdio>
#include <iostream>
using namespace std;
int R, C, N;
char zone[5][205][205];
int arrX[5] = {0, 1, 0, -1, 0};
int arrY[5] = {-1, 0, 1, 0, 0};

/*
단순 시뮬레이션으로 하기에는 N이 너무 크므로 규칙을 찾아야 한다.
잘보면 상태는 3개가 나오게 된다. 가장 첫번째 상태를 제외하고는 N이 2로 나누어 떨어질 때는
전부 폭탄으로 채워져 있고 첫번째 상태의 폭탄이 터질때의 상태와 거기서 남은 폭탄들이 터질때의 상태가
나오게 된다.
*/

int main()
{
    scanf("%d %d %d", &R, &C, &N);
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            scanf(" %c", &zone[0][i][j]);
            zone[1][i][j] = 'O';
            zone[2][i][j] = 'O';
            zone[3][i][j] = 'O';
        }
    }
    //첫번째로 폭탄 터질때와 두번째로 폭탄 터질떄의 상태
    for(int l = 0; l < 2; l++)
    {
        for(int i = 1; i <= R; i++)
        {
            for(int j = 1; j <= C; j++)
            {
                for(int k = 0; k < 5; k++)
                {
                    int nextx, nexty;
                    nextx = j + arrX[k];
                    nexty = i + arrY[k];
                    //주위에 폭탄이 하나라도 있는 경우
                    if(zone[l][nexty][nextx] == 'O')
                    {
                        //다음 상태에 빈공간으로 만듬
                        zone[l + 1][i][j] = '.';
                        break;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            if(N == 1)
            {
                printf("%c", zone[0][i][j]);
            }
            //두번째 폭탄이 터지는 경우
            else if((N & 3) == 1)
            {
                printf("%c", zone[2][i][j]);
            }
            //폭탄이 꽉 채워진 경우
            else if((N & 1) == 0)
            {
                printf("%c", zone[3][i][j]);
            }
            //첫번째 폭탄이 터지는 경우
            else
            {
                printf("%c", zone[1][i][j]);    
            }
        }
        printf("\n");
    }
}