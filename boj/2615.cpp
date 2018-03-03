#include <cstdio>
#include <iostream>
using namespace std;
int zone[25][25], chk[25][25][7], result, rx, ry;
int arrA[4] = {1, 1, -1, 0};
int arrB[4] = {0, 1, 1, 1};

/*
누가 이겼는지, 비겼는지 확인을 하는 문제이다.
오목 확인을 할때 현재 바둑알의 오른쪽, 오른쪽 아래 대각선, 아래쪽, 왼쪽 아래 대각선만 보면 된다.
그 이유는 바둑판을 탐색할때 맨 윗줄 왼쪽부터 탐색을 시작했기 때문에 현재 바둑알의 윗줄과 왼쪽은 탐색이
완료된 상태이다. 
*/

//바둑알 연속 확인 함수
void func(int x, int y, int count, int color, int dir)
{
    int flag = 0;
    //다음 바둑알 위치
    int nextx, nexty;
    nextx = x + arrA[dir];
    nexty = y + arrB[dir];
    //이미 한번 갔던곳을 또 확인 하는건 무의미
    if(chk[nexty][nextx][dir] == 1)
    {
        return;
    }
    //다음 위치가 현재 바둑알이랑 같은 색일 경우
    if(zone[nexty][nextx] == color)
    {
        flag = 1;
        chk[nexty][nextx][dir] = 1;
        if(nextx >= 1 && nextx <= 19 && nexty >= 1 && nexty <= 19)
        {
            func(nextx, nexty, count + 1, color, dir);
        }
    }
    //다음 위치가 더이상 같지 않고 카운트가 5이면 5줄 연속임
    if(flag == 0 && count == 5)
    {
        result = color;
        rx = x;
        ry = y;
        if(dir != 2)
        {
            rx = rx - arrA[dir] * 4;
            ry = ry - arrB[dir] * 4;
        }
    }
}

int main()
{
    for(int i = 1; i <= 19; i++)
    {
        for(int j = 1; j <= 19; j++)
        {
            scanf("%d", &zone[i][j]);
        }
    }
    for(int i = 1; i <= 19; i++)
    {
        for(int j = 1; j <= 19; j++)
        {
            //빈곳이 아닐 경우
            if(zone[i][j] != 0)
            {
                //4방향으로 탐색
                for(int k = 0; k < 4; k++)
                {
                    func(j, i, 1, zone[i][j], k);
                }
            }
        }
    }
    if(result == 0)
    {
        printf("0");
        return 0;
    }
    printf("%d\n%d %d", result, ry, rx);
}