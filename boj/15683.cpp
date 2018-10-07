#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int x;
    int y;
    int type;
}Data;
Data cam[15];
int N, M, zone[15][15], chk[15][15], cidx, result = 987654321, camArr[15], wcount, chkcount;
int arrA[4] = {0, 1, 0, -1};
int arrB[4] = {-1, 0, 1, 0};

/*
주어진 조건에 맞게 구현 하면 된다.
각각의 카메라를 회전 시키는 경우의 수는 최대 4 ^ 8이 된다. 4방향으로 회전 시키고 카메라는 최대 8개 이기
때문이다. 
*/

void func(int depth)
{
    //기저 사례
    if(depth == cidx)
    {
        //방문 했는지 여부 true, false를 chkcount로 대체
        //true false로 할 경우 매번 초기화 해야함
        chkcount++;
        //방문 한 곳 카운트
        int count = 0;
        for(int i = 0; i < cidx; i++)
        {
            //각각의 카메라 탐색 해야 할 방향 저장
            int op[5], oidx = 0;
            op[oidx++] = camArr[i];
            if(cam[i].type == 2 || cam[i].type == 4 || cam[i].type == 5)
            {
                op[oidx++] = (camArr[i] + 2) % 4;
            }
            if(cam[i].type == 3 || cam[i].type == 4 || cam[i].type == 5)
            {
                op[oidx++] = (camArr[i] + 1) % 4;
            }
            if(cam[i].type == 5)
            {
                op[oidx++] = (camArr[i] + 3) % 4;
            }
            //시뮬레이션
            for(int j = 0; j < oidx; j++)
            {
                int tx, ty;
                tx = cam[i].x;
                ty = cam[i].y;
                while(tx >= 0 && tx < M && ty >= 0 && ty < N && zone[ty][tx] != 6)
                {
                    if(chk[ty][tx] != chkcount)
                    {
                        count++;
                        chk[ty][tx] = chkcount;
                    }
                    tx = tx + arrA[op[j]];
                    ty = ty + arrB[op[j]];
                }
            }
        }
        result = min(result, N * M - count - wcount);
        return;
    }
    //5번 카메라는 회전 x
    if(cam[depth].type == 5)
    {
        camArr[depth] = 0;
        func(depth + 1);
    }
    //2번 카메라는 2번 회전
    else if(cam[depth].type == 2)
    {
        camArr[depth] = 0;
        func(depth + 1);
        camArr[depth] = 1;
        func(depth + 1);
    }
    //나머지는 4번 회전
    else
    {
        for(int i = 0; i < 4; i++)
        {
            camArr[depth] = i;
            func(depth + 1);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%d", &zone[i][j]);
            //카메라 배열에 저장
            if(zone[i][j] >= 1 && zone[i][j] < 6)
            {
                cam[cidx].x = j;
                cam[cidx].y = i;
                cam[cidx++].type = zone[i][j];
            }
            //벽 카운트
            if(zone[i][j] == 6)
            {
                wcount++;
            }
        }
    }
    func(0);
    printf("%d", result);
}