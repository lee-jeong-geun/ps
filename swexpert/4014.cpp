#include <cstdio>
#include <iostream>
using namespace std;
int N, X, zone[25][25], chk[25][25], chkcount, result;
int arrA[4] = {0, 1, 0, -1};
int arrB[4] = {-1, 0, 1, 0};

/*
단순 구현 문제이다.
모든 가로줄, 세로줄에 활주로를 설치 할 수 있는지 탐색을 하면된다.
단 경사가 1차이 날 경우 경사로를 둘 수 있는데 잘 구현 하면 된다.
*/

void init()
{
    chkcount = 0;
    result = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            chk[i][j] = 0;
        }
    }
}

//맵 벗어났는지 확인
bool range(int a, int b)
{
    if(a >= 0 && a < N && b >= 0 && b < N)
    {
        return 1;
    }
    return 0;
}

//경사로 두는 함수
bool func(int x, int y, int flag, int dir)
{
    int count = 0, rflag = 0;
    //내리막길
    if(flag == 0)
    {
        int nextx, nexty;
        nextx = x + arrA[dir];
        nexty = y + arrB[dir];
        while(range(nextx, nexty) == 1)
        {
            //앞으로 나아가면서 경사로 시작 부분이랑 1차이나는지 확인
            if(zone[y][x] == zone[nexty][nextx] + 1)
            {
                count++;
                chk[nexty][nextx] = chkcount;
                //경사로 개수랑 맞으면 종료
                if(count == X)
                {
                    rflag = 1;
                    break;
                }
            }
            else
            {
                return 0;
            }
            nextx += arrA[dir];
            nexty += arrB[dir];
        }
    }
    //오르막길
    else
    {
        int nextx, nexty;
        nextx = x + arrA[dir];
        nexty = y + arrB[dir];
        while(range(nextx, nexty) == 1)
        {
            if(zone[y][x] == zone[nexty][nextx] && chk[nexty][nextx] != chkcount)
            {
                count++;
                chk[nexty][nextx] = chkcount;
                if(count == X - 1)
                {
                    rflag = 1;
                    chk[y][x] = chkcount;
                    break;
                }
            }
            else
            {
                return 0;
            }
            nextx += arrA[dir];
            nexty += arrB[dir];
        }
    }
    return rflag;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        init();
        scanf("%d %d", &N, &X);
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                scanf("%d", &zone[i][j]);
            }
        }
        for(int i = 0; i < N; i++)
        {
            chkcount++;
            int tx, ty;
            tx = 0;
            ty = i;
            while(1)
            {
                //해당 줄 끝까지 이동했을 경우
                if(tx == N - 1)
                {
                    result++;
                    break;
                }
                //같으면 다음칸 이동
                if(zone[ty][tx] == zone[ty][tx + 1])
                {
                    tx++;
                }
                //내리막길 확인
                else if(zone[ty][tx] == zone[ty][tx + 1] + 1)
                {
                    //경사로 못 놓을 경우 종료
                    if(func(tx, ty, 0, 1) == 0)
                    {
                        break;
                    }
                    tx++;
                }
                //오르막길 확인
                else if(zone[ty][tx] == zone[ty][tx + 1] - 1)
                {
                    if(func(tx, ty, 1, 3) == 0)
                    {
                        break;
                    }
                    tx++;
                }
                else
                {
                    break;
                }
            }
        }
        for(int i = 0; i < N; i++)
        {
            chkcount++;
            int tx, ty;
            tx = i;
            ty = 0;
            while(1)
            {
                if(ty == N - 1)
                {
                    result++;
                    break;
                }
                if(zone[ty][tx] == zone[ty + 1][tx])
                {
                    ty++;
                }
                else if(zone[ty][tx] == zone[ty + 1][tx] + 1)
                {
                    if(func(tx, ty, 0, 2) == 0)
                    {
                        break;
                    }
                    ty++;
                }
                else if(zone[ty][tx] == zone[ty + 1][tx] - 1)
                {
                    if(func(tx, ty, 1, 0) == 0)
                    {
                        break;
                    }
                    ty++;
                }
                else
                {
                    break;
                }
            }
        }
        printf("#%d %d\n", testcase, result);
    }
}