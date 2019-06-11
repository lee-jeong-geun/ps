#include <bits/stdc++.h>
using namespace std;
int h, w, startx, starty, chk[505][505];
char zone[505][505];
int arrX[4] = {0, 0, 1, -1};
int arrY[4] = {1, -1, 0, 0};

/*
+가 될만한 위치를 찾아서 가운데 지점에서 상하좌우로 퍼지면서 *들을 체크해준다.
체크가 끝나면 모든 맵을 돌면서 체크가 안되어있고 *인 지점이 있으면 NO 그게 아니라면 YES이다.
+가 될만한 위치는 맨 가운데 *를 기준으로 상하좌우에 *가 있으면 가운데 지점이다.
*/

int main()
{
    scanf("%d %d", &h, &w);
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            scanf(" %c", &zone[i][j]);
        }
    }
    //+의 가운데 *찾음
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            if(zone[i][j] == '*')
            {
                int count = 0;
                for(int k = 0; k < 4; k++)
                {
                    if(zone[i + arrY[k]][j + arrX[k]] == '*')
                        count++;
                }
                if(count == 4)
                {
                    startx = j;
                    starty = i;
                    break;
                }
            }
        }
        if(startx > 0 && starty > 0)
            break;
    }
    //*가 하나도 없으면 NO
    if(startx == 0 && starty == 0)
    {
        printf("NO");
        return 0;
    }
    chk[starty][startx] = 1;
    for(int i = 0; i < 4; i++)
    {
        int tx, ty;
        tx = startx;
        ty = starty;
        while(zone[ty][tx] != 0 && zone[ty][tx] != '.')
        {
            chk[ty][tx] = 1;
            tx += arrX[i];
            ty += arrY[i];
        }
    }
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            if(zone[i][j] == '*' && chk[i][j] == 0)
            {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
}