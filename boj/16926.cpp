#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, R, zone[4][305][305], toggle;

/*
배열을 회전 시키는 구현을 하면 된다.
배열 2개를 이용해서 계속 토글하는 방식으로 하였다.
*/

void rotate()
{
    //테두리 개수
    for(int k = 0; k < min(N, M) / 2; k++)
    {
        //왼쪽 상->하
        for(int i = k; i < N - k - 1; i++)
        {
            zone[toggle ^ 1][i + 1][k] = zone[toggle][i][k];
        }
        //아래쪽 왼->오
        for(int i = k; i < M - k - 1; i++)
        {
            zone[toggle ^ 1][N - k - 1][i + 1] = zone[toggle][N - k - 1][i];
        }
        //오른쪽 하->상
        for(int i = N - k - 1; i >= k + 1; i--)
        {
            zone[toggle ^ 1][i - 1][M - k - 1] = zone[toggle][i][M - k - 1];
        }
        //위쪽 오->왼
        for(int i = M - k - 1; i >= k + 1; i--)
        {
            zone[toggle ^ 1][k][i - 1] = zone[toggle][k][i];
        }
    }
    toggle ^= 1;
}

int main()
{
    scanf("%d %d %d", &N, &M, &R);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%d", &zone[0][i][j]);
        }
    }
    for(int i = 0; i < R; i++)
    {
        rotate();
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            printf("%d ", zone[toggle][i][j]);
        }
        printf("\n");
    }
}