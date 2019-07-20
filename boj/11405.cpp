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
int N, M, dist[205], inQ[205], preNode[205], preEdge[205], result;

/*
소스와 사람들을 연결할 때 유량은 각 사람들의 필요한 책 개수이고 서점과 싱크를 연결할 때 유량은
서점에서 파는 책의 개수이다. 그리고 사람과 서점을 연결할 땐 유량을 둘중 작은거로 연결 시키면 된다.
*/

void addEdge(int start, int end, int capa, int cost)
{
    vec[start].emplace_back(end, capa, cost, vec[end].size());
    vec[end].emplace_back(start, 0, -cost, vec[start].size() - 1);
}

int SPFA()
{
    memset(dist, 0x3f, sizeof dist);
    memset(inQ, 0, sizeof inQ);
    memset(preNode, 0, sizeof preNode);
    memset(preEdge, 0, sizeof preEdge);
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
        addEdge(0, i, num, 0);
    }
    for(int i = 1; i <= M; i++)
    {
        int num;
        scanf("%d", &num);
        addEdge(N + i, N + M + 1, num, 0);
    }
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int num;
            scanf("%d", &num);
            addEdge(j, N + i, min(vec[0][j - 1].capa, vec[N + i][0].capa), num);
        }
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
            result += minFlow * vec[node][idx].cost;
        }
    }
    printf("%d", result);
}