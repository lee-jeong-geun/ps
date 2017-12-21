#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n, r, zone[55][55], chk[55][55][5], resultx, resulty, sx, sy;
int arrA[4] = {0, 1, 0, -1};
int arrB[4] = {-1, 0, 1, 0};

void init()
{
    memset(zone, 0, sizeof zone);
    memset(chk, 0, sizeof chk);
}
//맵 벗어났는지 확인
bool range(int x, int y)
{
    if(x >= 1 && x <= n && y >= 1 && y <= n)
    {
        return 1;
    }
    return 0;
}

// 시뮬레이션 함수
void func()
{
    int tx, ty, dir;
    tx = sx;
    ty = sy;
    for(int i = 0; i < 4; i++)
    {
        //첫 스타트 방향 잡아주기
        if(range(tx + arrA[i], ty + arrB[i]) == 1)
        {
            dir = i;
        }
    }
    while(1)
    {
        tx += arrA[dir];
        ty += arrB[dir];
        //맵 밖이면 종료
        if(range(tx, ty) == 0)
        {
            resultx = tx;
            resulty = ty;
            return;
        }
        //이미 왔던곳이면 종료
        if(chk[ty][tx][dir] == 1)
        {
            resultx = 0;
            resulty = 0;
            return;
        }
        chk[ty][tx][dir] = 1;
        //방향 90도 회전
        if(zone[ty][tx] == 1)
        {
            dir = (dir + 1) % 4;
        }
    }
    
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        init();
        scanf("%d %d", &n, &r);
        for(int i = 0; i < r; i++)
        {
            int y, x;
            scanf("%d %d", &y, &x);
            zone[y][x] = 1;
        }
        scanf("%d %d", &sy, &sx);
        func();
        printf("%d %d\n", resulty, resultx);
    }
}