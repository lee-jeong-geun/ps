#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef struct _data
{
    int node;
    int weight;
}Data;
vector<Data> vec[10005];
int V, E, M, Mx, S, Sy, Mac[10005], Sbuk[10005], mDist[10005], sDist[10005];
long long result = 9876543210;

/*
가장 간단하게 다익스트라를 이용하여 각각의 맥도날드와 스타벅스에서 집까지의 최단 거리를 구하는 시간 복잡도는
우선순위큐를 썼다고 했을때 (M + S) * (V log E)정도가 나오게 된다. M + S가 최대 9999이므로
9999 * 10000 * log 300000 정도인데 무조건 시간 초과가 나오게 된다.
따라서 M + S를 최대한으로 줄여야 하는데 그 방법은 맥도날드와 스타벅스에 임의의 노드를 붙이는 것이다.
임의의 노드 ----> 각각의 맥도 날드 ----> 모든 정점
이런 식으로 탐색을 하기 떄문에 임의의 노드에서 다익스트라 한번으로 모든 정점을 탐색 할 수 있게된다.
따라서 맥도날드와 스타벅스에 맥도날드 더미노드, 스타벅스 더미노드를 붙이고 두개의 더미 노드에서 다익스트라를 돌린 후
각각의 집에 최단 거리들을 확인 하면 된다.
나는 SPFA를 구현 하였다.
*/

//SPFA
void BFS(int node, int flag)
{
    queue<Data>q;
    q.push({node, 0});
    mDist[node] = 0;
    sDist[node] = 0;
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        for(int i = 0; i < vec[temp.node].size(); i++)
        {
            Data next;
            next.node = vec[temp.node][i].node;
            next.weight = temp.weight + vec[temp.node][i].weight;
            //맥도날드 최단 거리 확인
            if(flag == 0 && mDist[next.node] > next.weight)
            {
                mDist[next.node] = next.weight;
                q.push(next);
            }
            //스타벅스 최단 거리 확인
            else if(flag == 1 && sDist[next.node] > next.weight)
            {
                sDist[next.node] = next.weight;
                q.push(next);
            }
        }
    }
}

int main()
{
    for(int i = 0; i <= 10000; i++)
    {
        mDist[i] = 1234567890;
        sDist[i] = 1234567890;
    }
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        vec[u].push_back({v, w});
        vec[v].push_back({u, w});
    }
    scanf("%d %d", &M, &Mx);
    for(int i = 0; i < M; i++)
    {
        int node;
        scanf("%d", &node);
        Mac[node] = 1;
        //더미노드에 추가
        vec[10001].push_back({node, 0});
    }
    scanf("%d %d", &S, &Sy);
    for(int i = 0; i < S; i++)
    {
        int node;
        scanf("%d", &node);
        Sbuk[node] = 1;
        //더미 노드에 추가
        vec[10002].push_back({node, 0});
    }
    BFS(10001, 0);
    BFS(10002, 1);
    for(int i = 0; i < 10001; i++)
    {
        //최단 거리 확인
        if(Mac[i] == 0 && Sbuk[i] == 0 && mDist[i] <= Mx && sDist[i] <= Sy)
        {
            result = min(result, (long long)mDist[i] + sDist[i]);
        }
    }
    if(result == 9876543210)
    {
        result = -1;
    }
    printf("%ld", result);
}