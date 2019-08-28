#include <bits/stdc++.h>
using namespace std;
int n, chk[5];

/*
범위를 좁혀나가는 방식으로 접근하면 된다.
우선 로봇은 4방향으로 이동가능 하다. 로봇이 움직일수 있는 범위는 -100000 ~ 100000이다.
4방향 모두 이동가능한 로봇은 x, y 둘다 -100000 ~ 100000 까지 이동가능하고
위로 이동 불가능한 로봇은 x는 -100000 ~ 100000이고 y는 현재 좌표부터 -100000이다.
좌우로 이동 불가능한 로봇은 x는 현재 좌표, y는 -100000 ~ 100000이다.
4방향 모두 이동 불가능한 로봇은 현재 좌표 그대로이다. 이방식을 이용하여
x, y의 이동 가능한 지점들을 축소해가면 된다.
*/

int main()
{
    int q;
    scanf("%d", &q);
    for(int tc = 0; tc < q; tc++)
    {
        scanf("%d", &n);
        //min은 이동 가능 범위중 제일 작은 좌표
        //max는 이동 가능 범위중 제일 큰 좌표
        int rMinX, rMinY, rMaxX, rMaxY;
        rMinX = rMinY = -100000;
        rMaxX = rMaxY = 100000;
        for(int i = 0; i < n; i++)
        {
            int x, y, minX, minY, maxX, maxY;
            minX = minY = -100000;
            maxX = maxY = 100000;
            scanf("%d %d", &x, &y);
            for(int j = 0; j < 4; j++)
            {
                scanf("%d", &chk[j]);
            }
            //왼쪽 이동 불가능
            if(chk[0] == 0)
                minX = x;
            //위로 이동 불가능
            if(chk[1] == 0)
                maxY = y;
            if(chk[2] == 0)
                maxX = x;
            if(chk[3] == 0)
                minY = y;
            //이동 가능 범위중 제일 작은 좌표는 둘중 큰 좌표
            rMinX = max(rMinX, minX);
            rMinY = max(rMinY, minY);
            //이동 가능 범위중 제일 큰 좌표는 둘중 작은 좌표
            rMaxX = min(rMaxX, maxX);
            rMaxY = min(rMaxY, maxY);
        }
        //역전이 된다면 한점으로 못 모임
        if(rMinX > rMaxX || rMinY > rMaxY)
        {
            printf("0\n");
            continue;
        }
        printf("1 %d %d\n", rMinX, rMinY);
    }
}