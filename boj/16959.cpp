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
    int key;
    int type;
}Data;
int N, zone[15][15], chk[15][15][105][5], sx, sy;
int arrX[3][8] = {{0, 1, 0, -1}, {1, 1, -1, -1}, {1, 2, 2, 1, -1, -2, -2, -1}};
int arrY[3][8] = {{-1, 0, 1, 0}, {-1, 1, 1, -1}, {-2, -1, 1, 2, 2, 1, -1, -2}};
int op[5] = {4, 4, 8};
queue<Data> q;

/*
x, y, 지금까지 밟아온 발판, 종류로 visit 배열을 잡고 BFS를 돌리면 된다.
*/

//이동 체크 함수
int move(Data &next)
{
    int ret = 0;
    //맵 내부 존재
    if(next.x >= 0 && next.x < N && next.y >= 0 && next.y < N)
    {
        ret = 1;
        //다음 발판이 현재 발판 보다 1큰 경우
        if(zone[next.y][next.x] == next.key + 1)
        {
            ret = 0;
            next.key++;
        }
        //한번도 방문 하지 않은 경우
        if(chk[next.y][next.x][next.key][next.type] == 0)
        {
            chk[next.y][next.x][next.key][next.type] = 1;
            q.push(next);
        }
    }
    return ret;
}

int BFS()
{
    for(int i = 0; i < 3; i++)
    {
        q.push({sx, sy, 0, 1, i});
        chk[sy][sx][1][i] = 0;
    }
    while(!q.empty())
    {
        Data temp, next;
        temp = q.front();
        q.pop();
        if(temp.key == N * N)
        {
            return temp.count;
        }
        //말 종류 체인지
        for(int i = 0; i < 2; i++)
        {
            next.x = temp.x;
            next.y = temp.y;
            next.count = temp.count + 1;
            next.key = temp.key;
            next.type = (temp.type + 1 + i) % 3;
            move(next);
        }
        //말 이동
        for(int i = 0; i < op[temp.type]; i++)
        {
            int flag = 1, count = 1;
            while(flag)
            {
                next.x = temp.x + arrX[temp.type][i] * count;
                next.y = temp.y + arrY[temp.type][i] * count;
                next.count = temp.count + 1;
                next.key = temp.key;
                next.type = temp.type;
                flag = move(next);
                //나이트인 경우
                if(temp.type == 2)
                {
                    count--;
                    flag = 0;
                }
                count++;
            }
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
            if(zone[i][j] == 1)
            {
                sx = j;
                sy = i;
            }
        }
    }
    printf("%d", BFS());
}