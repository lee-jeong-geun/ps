#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, W, H, zone[20][15], result = 987654321;
int arrA[4] = {0, 1, 0, -1};
int arrB[4] = {-1, 0, 1, 0};

/*
주어진 조건에 맞게 시뮬레이션을 구현 하면 된다.
구슬을 최대 4번 쏠 수 있고 각각의 열에 중복으로 쏠 수 있기 때문에 경우의 수는
12 ^ 4가 나오게 된다.
구슬을 쐈을때 연쇄반응은 DFS로 구현을 하였고 공중에 떠있는 벽돌을 내리는 것은 투포인터를 이용하였다.
구슬을 쏠 위치를 탐색 할 때 해당 열의 맨아래 즉 H - 1행이 0이라면 벽돌이 없다는 뜻이므로 다음 열로 넘어간다.
*/

//DFS
int func2(int x, int y)
{
    int count = 0, blockCount = 1;
    count = zone[y][x];
    //벽돌을 지움
    zone[y][x] = 0;
    for(int i = 0; i < 4; i++)
    {
        int tx, ty;
        tx = x + arrA[i];
        ty = y + arrB[i];
        for(int j = 0; j < count - 1; j++)
        {
            //맵 안에 있고 벽돌이 존재 한다면
            if(tx >= 0 && tx < W && ty >= 0 && ty < H && zone[ty][tx] != 0)
            {
                blockCount += func2(tx, ty);
            }
            tx = tx + arrA[i];
            ty = ty + arrB[i];
        }
    }
    return blockCount;
}

//벽돌 내림
void drop()
{
    for(int i = 0; i < W; i++)
    {
        //l은 아래 r은 위에
        //l은 항상 0을 가르킴
        //r은 항상 벽돌을 가르킴
        int l, r;
        l = H - 1;
        r = H - 2;
        while(l >= r && r >= 0)
        {
            //r을 벽돌을 가르킬때까지 옮김
            if(zone[r][i] == 0 || l == r)
            {
                r--;
                continue;
            }
            //l을 0을 가르킬때까지 옮김
            if(zone[l][i] != 0)
            {
                l--;
                continue;
            }
            //스왑
            swap(zone[r][i], zone[l][i]);
        }
    }
}

void func(int depth, int block)
{
    if(depth == N)
    {
        result = min(result, block);
        return;
    }
    //tzone은 이전 맵 저장
    int tzone[20][15], tcount = 0;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            tzone[i][j] = zone[i][j];
        }
    }
    for(int k = 0; k < W; k++)
    {
        //벽돌이 없는 열일 경우
        if(zone[H - 1][k] == 0)
        {
            continue;
        }
        for(int i = 0; i < H; i++)
        {
            //해당 열의 맨 위에 벽돌만 깸
            if(zone[i][k] != 0)
            {
                tcount = func2(k, i);
                drop();
                break;
            }
        }
        func(depth + 1, block - tcount);
        //맵을 바꾸기 전으로 돌림
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {
                zone[i][j] = tzone[i][j];
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        int block = 0;
        result = 987654321;
        scanf("%d %d %d", &N, &W, &H);
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {
                scanf("%d", &zone[i][j]);
                if(zone[i][j] != 0)
                {
                    block++;
                }
            }
        }
        func(0, block);
        if(result == 987654321)
        {
            result = 0;
        }
        printf("#%d %d\n", testcase, result);
    }
}