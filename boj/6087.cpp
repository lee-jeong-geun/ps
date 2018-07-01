#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int x;
    int y;
    int dir;
    int count;
}Data;
int W, H, sx, sy, result = 987654321, chk[105][105];
char zone[105][105];
int arrA[4] = {0, 1, 0, -1};
int arrB[4] = {-1, 0, 1, 0};

/*
현재 위치에서 할수 있는 것은 직진, 좌회전, 우회전이 있다.
좌회전, 우회전을 할때 카운트를 1늘려주고 체크 배열에 저장을 한다.
체크 배열에는 최소값을 저장한다.
*/

//맵 안에 있는지 확인
bool range(int a, int b)
{
    if(a >= 0 && a < W && b >= 0 && b < H)
    {
        return 1;
    }
    return 0;
}

void BFS()
{
    queue<Data> q;
    //첫 스타트 지점에서 4방향으로 탐색
    for(int i = 0; i < 4; i++)
    {
        //맵 안에 들어와있고 장애물이 아닐 경우 탐색
        if(range(sx + arrA[i], sy + arrB[i]) == 1 && zone[sy + arrB[i]][sx + arrA[i]] != '*')
        {
            q.push({sx + arrA[i], sy + arrB[i], i, 0});
        }
    }
    chk[sy][sx] = -1;
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        if(zone[temp.y][temp.x] == 'C')
        {
            result = min(result, temp.count);
            continue;
        }
        for(int i = 0; i < 4; i++)
        {
            //후진은 볼 필요 없음
            if((temp.dir + 2) % 4 == i)
            {
                continue;
            }
            Data next;
            next.x = temp.x + arrA[i];
            next.y = temp.y + arrB[i];
            next.dir = i;
            next.count = temp.count;
            //직진이 아닐경우
            if(temp.dir != i)
            {
                next.count++;
            }
            //다음 위치보다 카운트가 작아야함
            if(range(next.x, next.y) == 1 && next.y < H && zone[next.y][next.x] != '*' && chk[next.y][next.x] >= next.count)
            {
                chk[next.y][next.x] = next.count;
                q.push(next);
            }
        }
    }
}

int main()
{
    scanf("%d %d", &W, &H);
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            scanf(" %c", &zone[i][j]);
            if(zone[i][j] == 'C')
            {
                sx = j;
                sy = i;
            }
        }
    }
    memset(chk, 0x3f, sizeof chk);
    BFS();
    printf("%d", result);
}