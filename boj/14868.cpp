#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef struct _data
{
    int x, y, count, color;
}Data;
int N, K, zone[2005][2005], parent[100005], result, rk[100005];
int arrA[4] = {0, 0, 1, -1};
int arrB[4] = {1, -1, 0, 0};

/*
이 문제는 서로 다른 문명이 모두 하나로 합쳐 질때의 시간을 구하는 것이다.
각 문명은 상하좌우로 이동할수 있고 모든 문명이 하나로 합치는 것은 BFS를 이용한 flood fiil 알고리즘으로
구할 수 있다. 각 문명은 union-find를 이용해서 쉽게 합칠 수 있다. 
*/

//각 문명의 조상을 구하는 함수
int find(int node)
{
    if(node == parent[node])
    {
        return node;
    }
    return parent[node] = find(parent[node]);
}

//각 문명을 하나의 집합으로 합치는 함수
void uni(int node1, int node2)
{
    node1 = find(node1);
    node2 = find(node2);
    //두 집합의 높이중 항상 node1 높이가 크도록 맞춤
    if(rk[node1] < rk[node2])
    {
        int temp;
        temp = node1;
        node1 = node2;
        node2 = temp;
    }
    if(node1 != node2)
    {
        result++;
        parent[node2] = node1;
        //두 집합의 높이가 같으면 높이를 1 증가 시킴
        if(rk[node1] == rk[node2])
        {
            rk[node1]++;
        }
    }
}

queue<Data>q;

int BFS()
{
    //처음 시작 할 때 부터 문명이 하나로 될 경우
    if(result == K - 1)
    {
        return 0;
    }
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            Data next;
            next.x = temp.x + arrA[i];
            next.y = temp.y + arrB[i];
            next.count = temp.count + 1;
            next.color = parent[temp.color];
            //맵 밖을 벗어날 경우
            if(next.x < 1 || next.x > N || next.y < 1 || next.y > N)
            {
                continue;
            }
            //인접한 문명이 다른 경우
            if(next.color != find(zone[next.y][next.x]))
            { 
                //미개 지역이 아닌경우
                if(zone[next.y][next.x] != 0)
                {
                    uni(next.color, find(zone[next.y][next.x]));
                    if(result == K - 1)
                    {
                        return next.count;
                    }
                }
                //한칸 이동 했을때 인접한 문명이 있는지 확인
                for(int j = 0; j < 4; j++)
                {
                    Data nnext;
                    nnext.x = next.x + arrA[j];
                    nnext.y = next.y + arrB[j];
                    nnext.color = parent[next.color];
                    //맵 밖을 벗어날 경우
                    if(nnext.x < 1 || nnext.x > N || nnext.y < 1 || nnext.y > N)
                    {
                        continue;
                    }
                    //인접한 문명이 다른 경우
                    if(nnext.color != find(zone[nnext.y][nnext.x]))
                    {
                        //미개 지역이 아닌 경우
                        if(zone[nnext.y][nnext.x] != 0)
                        {
                            uni(nnext.color, find(zone[nnext.y][nnext.x]));
                            if(result == K - 1)
                            {
                                return next.count;
                            }
                            zone[nnext.y][nnext.x] = nnext.color;
                        }
                    }
                }
                zone[next.y][next.x] = next.color;
                q.push(next);
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &K);
    //각 문명의 조상을 자기 자신으로 초기화
    for(int i = 0; i <= K; i++)
    {
        parent[i] = i;
    }
    for(int i = 0; i < K; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        //처음 시작 할 때 각 문명에 바로 인접한 문명을 합침
        for(int j = 0; j < 4; j++)
        {
            int nextx, nexty;
            nextx = x + arrA[j];
            nexty = y + arrB[j];
            if(nextx < 1 || nextx > N || nexty < 1 || nexty > N)
            {
                continue;
            }
            if(zone[nexty][nextx] != 0)
            {
                uni(i + 1, zone[nexty][nextx]);
            }
        }
        zone[y][x] = i + 1;
        q.push({x, y, 0, i + 1});
    }
    printf("%d", BFS());
}