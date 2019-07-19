#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct Edge
{
    int v, capa, cost, rev;
    Edge(int v, int capa, int cost, int rev) : v(v), capa(capa), cost(cost), rev(rev) {}
};
vector<vector<Edge>> vec;
//preNode는 최소 경로로 이동할 때 현재 노드로 들어오는 이전 노드를 저장
//preEdge는 최소 경로로 이동할 때 현재 노드와 이전노드의 간선
int N, M, dist[1005], preNode[1005], preEdge[1005], inQ[1005];
int resultFlow, resultCost;

/*
MCMF예제라서 MCMF를 이용하면 된다.
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
    q.push(0);
    dist[0] = 0;
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
            if(dist[next] > nextCost && nextCapa > 0)
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
    return dist[N + M + 1] < 987654321;
}

int main()
{
    scanf("%d %d", &N, &M);
    vec.resize(N + M + 5);
    for(int i = 1; i <= N; i++)
    {
        int num;
        scanf("%d", &num);
        addEdge(0, i, 1, 0);
        for(int j = 0; j < num; j++)
        {
            int v, c;
            scanf("%d %d", &v, &c);
            addEdge(i, N + v, 1, c);
        }
    }
    for(int i = 1; i <= M; i++)
    {
        addEdge(N + i, N + M + 1, 1, 0);
    }
    while(SPFA())
    {
        int minFlow = 987654321;
        for(int i = N + M + 1; i != 0; i = preNode[i])
        {
            int node, idx;
            node = preNode[i];
            idx = preEdge[i];
            minFlow = min(minFlow, vec[node][idx].capa);
        }
        for(int i = N + M + 1; i != 0; i = preNode[i])
        {
            int node, idx;
            node = preNode[i];
            idx = preEdge[i];
            vec[node][idx].capa -= minFlow;
            vec[i][vec[node][idx].rev].capa += minFlow;
            resultCost += minFlow * vec[node][idx].cost;
        }
        resultFlow += minFlow;
    }
    printf("%d\n%d", resultFlow, resultCost);
}