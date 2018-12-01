#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef struct _data
{
    int x;
    int y;
}Data;
vector<Data> vec[10005];
int N, M, zone[105][105], chk[105][105], result = 1;
int arrX[4] = {0, 1, 0, -1};
int arrY[4] = {-1, 0, 1, 0};

/*
시작 위치에서 BFS를 돌리면서 불을 켤 수 있는 것들을 다 키고 움직일 곳이 없다면
다시 처음 위치에서부터 BFS를 돌리는 방식을 이용한다.
이전에 BFS를 돌렸을때와 현재 BFS를 돌리고 난 후의 차이가 없다면 종료한다.
*/

//좌표를 인덱스로 바꿈
int change(int x, int y)
{
    return (y - 1) * N + x;
}

int BFS()
{
    int count = 1;
    queue<Data> q;
    q.push({1, 1});
    chk[1][1] = 1;
    while(!q.empty())
    {
        int node;
        Data temp;
        temp = q.front();
        q.pop();
        node = change(temp.x, temp.y);
        for(int i = 0; i < vec[node].size(); i++)
        {
            //불을 켤 수 있으면 킴
            if(zone[vec[node][i].y][vec[node][i].x] == 0)
            {
                zone[vec[node][i].y][vec[node][i].x] = 1;
                result++;
            }
        }
        for(int i = 0; i < 4; i++)
        {
            Data next;
            next.x = temp.x + arrX[i];
            next.y = temp.y + arrY[i];
            //다음 위치로 이동
            if(next.x >= 1 && next.x <= N && next.y >= 1 && next.y <= N)
            {
                if(zone[next.y][next.x] == 1 && chk[next.y][next.x] == 0)
                {
                    count++;
                    chk[next.y][next.x] = 1;
                    q.push(next);
                }
            }
        }
    }
    return count;
}

void func()
{
    zone[1][1] = 1;
    int qSize = 1, tqSize = 0; 
    while(qSize != tqSize)
    {
        tqSize = qSize;
        qSize = BFS();
        memset(chk, 0, sizeof chk);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        int sx, sy, ex, ey;
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        vec[change(sx, sy)].push_back({ex, ey});
    }
    func();
    printf("%d", result);
}