#include <bits/stdc++.h>
using namespace std;
set<int> resultR, resultC;
int R, C;
char zone[15][15];
int arrR[4] = {-1, 0, 1, 0};
int arrC[4] = {0, 1, 0, -1};

/*
각 섬 별로 4방향 잘 확인해서 구현 하면 된다.
*/

int main()
{
    scanf("%d %d", &R, &C);
    for(int i = 0; i <= R + 1; i++)
    {
        for(int j = 0; j <= C + 1; j++)
        {
            zone[i][j] = '.';
        }
    }
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            scanf(" %c", &zone[i][j]);
        }
    }
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            int count = 0;
            if(zone[i][j] == '.')
                continue;
            for(int k = 0; k < 4; k++)
            {
                if(zone[i + arrR[k]][j + arrC[k]] == '.')
                    count++;
            }
            if(count >= 3)
                zone[i][j] = '*';
        }
    }
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            if(zone[i][j] == 'X')
            {
                resultR.insert(i);
                resultC.insert(j);
            }
        }
    }
    for(int i = *resultR.begin(); i <= *resultR.rbegin(); i++)
    {
        for(int j = *resultC.begin(); j <= *resultC.rbegin(); j++)
        {
            if(zone[i][j] == '*')
                zone[i][j] = '.';
            printf("%c", zone[i][j]);
        }
        printf("\n");
    }
}