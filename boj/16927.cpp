#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, R, zone[4][305][305], toggle;

/*
배열을 회전 시키는데 회전 횟수가 최대 10억이므로 10억번 회전 시키는건 불가능 하다.
잘보면 한 테두리 안에서 테두리의 둘레 만큼 회전하면 다시 원점으로 돌아온다.
이 원리를 이용하여 각각의 테두리에서 둘레를 구한 후 R % 둘레만큼 회전시키면 된다.
*/

//회전
void rotate(int k)
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
    //테두리 개수
    for(int i = 0; i < min(N, M) / 2; i++)
    {
        toggle = 0;
        //둘레를 나눈 나머지 만큼만 회전
        for(int j = 0; j < R % ((N - i * 2) * 2 + (M - i * 2) * 2 - 4); j++)
        {
            rotate(i);
        }
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