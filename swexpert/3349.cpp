#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int W, H, N, result, sx, sy;

/*
대각선 경로를 이용 할 수 있는 경우는 좌표 평면 상으로 다음위치가 현재 위치를 기준으로 
1, 3 사분면에 있을 때다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        result = 0;
        scanf("%d %d %d", &W, &H, &N);
        for(int i = 0; i < N; i++)
        {
            int nx, ny, tx, ty;
            scanf("%d %d", &nx, &ny);
            if(i == 0)
            {
                sx = nx;
                sy = ny;
            }
            tx = nx;
            ty = ny;
            //2, 3 사분면을 1, 4 사분면으로 옮김
            if(sx >= nx && sy >= ny || sx >= nx && sy <= ny)
            {
                swap(sx, tx);
                swap(sy, ty);
            }
            //대각선 처리
            if(sx <= tx && sy <= ty)
            {
                result += max(tx - sx, ty - sy);
            }
            else
            {
                result += sy - ty + tx - sx;
            }
            sx = nx;
            sy = ny;
        }
        printf("#%d %d\n", testcase, result);
    }
}