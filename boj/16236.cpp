#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef struct _data
{
    int x;
    int y;
    int count;
}Data;
int N, zone[25][25], sx,sy, result, chk[25][25], fSize = 2;
int arrX[4] = {0, 1, 0, -1};
int arrY[4] = {-1, 0, 1, 0};

/*
상어를 먹을 물고기가 없을때 까지 bfs를 돌리면 된다.
각각의 bfs가 끝나고 조건을 만족하는 물고기를 탐색 후 해당 물고기 자리로 시작 지점을 옮기면 된다.
조건을 만족하는 물고기가 하나도 없을 경우 종료 하면 된다.
*/

void func()
{
    queue<Data>q;
    zone[sy][sx] = 0;
    //조건에 만족하는 물고기 위치 저장 하는 배열
    Data farr[405];
    int feedCount = 0, fidx= 0;
    //조건에 만족하는 물고기 하나도 없을 때 까지
    while(1)
    {
        //방문 체크 배열 초기화
        memset(chk, 0, sizeof chk);
        q.push({sx, sy, 0});
        chk[sy][sx] = 1;
        fidx = 0;
        //bfs
        while(!q.empty())
        {
            Data temp;
            temp = q.front();
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                Data next;
                next.x = temp.x + arrX[i];
                next.y = temp.y + arrY[i];
                next.count = temp.count + 1;
                //맵 안쪽인지 확인
                if(next.x >= 0 && next.x < N && next.y >= 0 && next.y < N)
                {
                    //한번도 방문 안했고 현재 크기 이하인 경우
                    if(chk[next.y][next.x] == 0 && fSize >= zone[next.y][next.x])
                    {
                        //0이 아니고 현재 크기보다 작은 경우
                        if(zone[next.y][next.x] != 0 && fSize > zone[next.y][next.x])
                        {
                            farr[fidx++] = next;
                        }
                        chk[next.y][next.x] = 1;
                        q.push(next);
                    }
                }
            }
        }
        //하나도 없으면 종료
        if(fidx == 0)
        {
            return;
        }
        Data Min;
        Min.count = 987654321;
        //조건에 만족하는 물고기 탐색
        for(int i = 0; i < fidx; i++)
        {
            if(Min.count > farr[i].count)
            {
                Min = farr[i];
            }
            else if(Min.count == farr[i].count && Min.y > farr[i].y)
            {
                Min = farr[i];
            }
            else if(Min.count == farr[i].count && Min.y == farr[i].y && Min.x > farr[i].x)
            {
                Min = farr[i];
            }
        }
        feedCount++;
        result += Min.count;
        zone[Min.y][Min.x] = 0;
        //시작 위치 변경
        sx = Min.x;
        sy = Min.y;
        //물고기를 현재 크기 만큼 먹은 경우
        if(feedCount == fSize)
        {
            feedCount = 0;
            fSize++;
        }
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &zone[i][j]);
            if(zone[i][j] == 9)
            {
                sx = j;
                sy = i;
            }
        }
    }
    func();
    printf("%d", result);
}