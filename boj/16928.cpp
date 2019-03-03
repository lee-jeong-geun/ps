#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef struct _data
{
    int x;
    int count;
}Data;
int N, M, zone[105], chk[105];

/*
BFS를 이용하여 주어진 조건에 맞게 구현하면 된다.
*/

int BFS()
{
    queue<Data>q;
    q.push({1, 0});
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        //도착 지점
        if(temp.x == 100)
        {
            return temp.count;
        }
        //주사위는 1 ~ 6
        for(int i = 1; i <= 6; i++)
        {
            Data next;
            next.x = temp.x + i;
            next.count = temp.count + 1;
            if(next.x >= 1 && next.x <= 100 && chk[next.x] == 0)
            {
                chk[next.x] = 1;
                //뱀 or 사다리 or 일반
                next.x = zone[next.x];
                q.push(next);
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= 100; i++)
    {
        zone[i] = i;
    }
    for(int i = 0; i < N; i++)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        zone[start] = end;
    }
    for(int i = 0; i < M; i++)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        zone[start] = end;
    }
    printf("%d", BFS());
}