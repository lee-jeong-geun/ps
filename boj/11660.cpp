#include <cstdio>
#include <iostream>
using namespace std;
int N, M, zone[1030][1030], Sum[1030][1030];

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            scanf("%d", &zone[i][j]);
        }
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            Sum[i][j] = Sum[i - 1][j] + Sum[i][j - 1] + zone[i][j] - Sum[i - 1][j - 1];
        }
    }
    for(int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        printf("%d\n", Sum[y2][x2] - Sum[y2][x1 - 1] - Sum[y1 - 1][x2] + Sum[y1 - 1][x1 - 1]);
    }
    
}