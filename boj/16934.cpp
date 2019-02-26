#include <cstdio>
#include <iostream>
using namespace std;
int N, M, R, zone[5][105][105], toggle;

/*
조건에 맞게 구현 하면 된다.
구현을 쉽게 할 수 있게 2차원 배열을 토글 하면서 연산 결과를 저장 하였다.
*/

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void upDownChange()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            zone[toggle ^ 1][i][j] = zone[toggle][N - i - 1][j];
        }
    }
}

void leftRightChange()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            zone[toggle ^ 1][i][j] = zone[toggle][i][M - j - 1];
        }
    }
}

void rightRotate()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            zone[toggle ^ 1][j][N - i - 1] = zone[toggle][i][j];
        }
    }
    swap(N, M);
}

void leftRotate()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            zone[toggle ^ 1][M - j - 1][i] = zone[toggle][i][j];
        }
    }
    swap(N, M);
}

void fiveChange()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(i < N / 2)
            {
                if(j < M / 2)
                {
                    zone[toggle ^ 1][i][j + M / 2] = zone[toggle][i][j];
                }
                else
                {
                    zone[toggle ^ 1][i + N / 2][j] = zone[toggle][i][j];
                }
            }
            else
            {
                if(j < M / 2)
                {
                    zone[toggle ^ 1][i - N / 2][j] = zone[toggle][i][j];
                }
                else
                {
                    zone[toggle ^ 1][i][j - M / 2] = zone[toggle][i][j];
                }
            }
        }
    }
}

void sixChange()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(i < N / 2)
            {
                if(j < M / 2)
                {
                    zone[toggle ^ 1][i + N / 2][j] = zone[toggle][i][j];
                }
                else
                {
                    zone[toggle ^ 1][i][j - M / 2] = zone[toggle][i][j];
                }
            }
            else
            {
                if(j < M / 2)
                {
                    zone[toggle ^ 1][i][j + M / 2] = zone[toggle][i][j];
                }
                else
                {
                    zone[toggle ^ 1][i - N / 2][j] = zone[toggle][i][j];
                }
            }
        }
    }
}

void print()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            printf("%d ", zone[toggle][i][j]);
        }
        printf("\n");
    }
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
        int op;
        scanf("%d", &op);
        switch (op)
        {
            case 1 : upDownChange(); break;
            case 2 : leftRightChange(); break;
            case 3 : rightRotate(); break;
            case 4 : leftRotate(); break;
            case 5 : fiveChange(); break;
            case 6 : sixChange(); break;
        }
        toggle ^= 1;
    }
    print();
}