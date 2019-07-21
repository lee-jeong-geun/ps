#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct Edge
{
    int v, capa, cost, rev;
    Edge(int v, int capa, int cost, int rev) : v(v), capa(capa), cost(cost), rev(rev) {}
};
vector<vector<Edge>> vec;
int V, E, dist[2005], preNode[2005], preEdge[2005], inQ[2005], result;

/*
한개의 정점에는 반드시 한번 밖에 가지 못하므로 각 정점 마다 더미 노드를 한개씩 만들어서
연결 시켜준다. 이때 유량을 1로 잡는다면 해당 정점으로 유량이 1흐르므로 한번만 방문 가능하다.
그리고 각각의 배를 유량 1로 잡는다면 총 2대이므로 첫 정점과 끝 정점은 유량을 2로 잡아준다.
*/

void addEdge(int start, int end, int capa, int cost)
{
    vec[start].emplace_back(end, capa, cost, vec[end].size());
    vec[end].emplace_back(start, 0, -cost, vec[start].size() - 1);
}

int SPFA()
{
    memset(dist, 0x3f, sizeof dist);
    memset(preNode, 0, sizeof preNode);
    memset(preEdge, 0, sizeof preEdge);
    memset(inQ, 0, sizeof inQ);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty())
    {
        int temp;
        temp = q.front();
        q.pop();
        inQ[temp] = 0;
        for(int i = 0; i < vec[temp].size(); i++)
        {
            int next, nextCapa, nextCost;
            next = vec[temp][i].v;
            nextCapa = vec[temp][i].capa;
            nextCost = dist[temp] + vec[temp][i].cost;
            if(nextCapa > 0 && dist[next] > nextCost)
            {
                dist[next] = nextCost;
                preNode[next] = temp;
                preEdge[next] = i;
                if(inQ[next] == 0)
                {
                    inQ[next] = 1;
                    q.push(next);
                }
            }
        }
    }
    return dist[V] < 987654321;
}

int main()
{
    while(scanf("%d %d", &V, &E) != -1)
    {
        result = 0;
        vec.clear();
        vec.resize(V * 2 + 5);
        //더미노드 연결
        for(int i = 1; i <= V; i++)
        {
            //첫정점과 끝정점은 2로 잡음
            if(i == 1 || i == V)
                addEdge(i, i + V, 2, 0);
            else
                addEdge(i, i + V, 1, 0);
        }
        for(int i = 0; i < E; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            addEdge(a + V, b, 1, c);
        }
        while(SPFA())
        {
            int minFlow = 987654321;
            for(int i = V + V; i != 1; i = preNode[i])
            {
                int node, idx;
                node = preNode[i];
                idx = preEdge[i];
                minFlow = min(minFlow, vec[node][idx].capa);
            }
            for(int i = V + V; i != 1; i = preNode[i])
            {
                int node, idx;
                node = preNode[i];
                idx = preEdge[i];
                vec[node][idx].capa -= minFlow;
                vec[i][vec[node][idx].rev].capa += minFlow;
                result += minFlow * vec[node][idx].cost;
            }
        }
        printf("%d\n", result);
    }
}