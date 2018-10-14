#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef struct _data
{
    int x, y, C, P;
}Data;
Data ap[15];
int M, A, Human[5][105], chk[5][15], hPointX[5], hPointY[5], result;
int arrA[5] = {0, 0, 1, 0, -1};
int arrB[5] = {0, -1, 0, 1, 0};

/*
주어진 조건에 맞게 구현 하면 된다.
각각의 사람이 이동을 하면서 어떤 BC에 속했는지 일일이 확인을 하였다.
그리고 속한 것들중에서 전체를 탐색하여 최대값을 구하였다.
*/

//최대값 탐색 함수
int func(int depth, int idx)
{
    int Max = 0;
    if(depth == 2)
    {
        return 0;
    }
    Max = func(depth + 1, idx);
    for(int i = 0; i < A; i++)
    {
        if(chk[depth][i] == 1)
        {
            if(idx != i)
            {
                Max = max(Max, func(depth + 1, i) + ap[i].P);
            }
        }
    }
    return Max;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        result = 0;
        scanf("%d %d", &M, &A);
        for(int i = 0; i < 2; i++)
        {
            for(int j = 1; j <= M; j++)
            {
                scanf("%d", &Human[i][j]);
            }
        }
        for(int i = 0; i < A; i++)
        {
            scanf("%d %d %d %d", &ap[i].x, &ap[i].y, &ap[i].C, &ap[i].P);
        }
        hPointX[0] = 1;
        hPointY[0] = 1;
        hPointX[1] = 10;
        hPointY[1] = 10;
        //시뮬레이션
        for(int Time = 0; Time <= M; Time++)
        {
            memset(chk, 0, sizeof chk);
            for(int i = 0; i < 2; i++)
            {
                hPointX[i] += arrA[Human[i][Time]];
                hPointY[i] += arrB[Human[i][Time]];
                for(int j = 0; j < A; j++)
                {
                    //속해있으면 체크
                    if(abs(hPointX[i] - ap[j].x) + abs(hPointY[i] - ap[j].y) <= ap[j].C)
                    {
                        chk[i][j] = 1;
                    }
                }
            }
            result += func(0, -1);
        }
        printf("#%d %d\n", testcase, result);
    }
}