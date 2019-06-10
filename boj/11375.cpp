#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct Edge
{
    int v, capa, rev;
    Edge(int v, int capa, int rev) : v(v), capa(capa), rev(rev) {}
};
vector<vector<Edge>> vec;
int level[2005], work[2005], N, M, result;

/*
단순하게 이분매칭으로 풀수 있다.
*/

void addEdge(int start, int end, int capa)
{
    vec[start].emplace_back(end, capa, vec[end].size());
    vec[end].emplace_back(start, capa, vec[start].size() - 1);
}

int BFS()
{
    memset(level, -1, sizeof level);
    queue<int> q;
    q.push(0);
    level[0] = 0;
    while(!q.empty())
    {
        int temp;
        temp = q.front();
        q.pop();
        for(int i = 0; i < vec[temp].size(); i++)
        {
            int next, nextCapa;
            next = vec[temp][i].v;
            nextCapa = vec[temp][i].capa;
            if(level[next] == -1 && nextCapa > 0)
            {
                level[next] = level[temp] + 1;
                q.push(next);
            }
        }
    }
    return level[N + M + 1] != -1;
}

int DFS(int node, int f)
{
    if(node == N + M + 1)
        return f;
    int minFlow;
    for(int &i = work[node]; i < vec[node].size(); i++)
    {
        int next, nextCapa;
        next = vec[node][i].v;
        nextCapa = vec[node][i].capa;
        if(level[next] == level[node] + 1 && nextCapa > 0)
        {
            minFlow = DFS(next, min(f, nextCapa));
            if(minFlow > 0)
            {
                vec[node][i].capa -= minFlow;
                vec[next][vec[node][i].rev].capa += minFlow;
                return minFlow;
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d", &N, &M);
    vec.resize(N + M + 5);
    for(int i = 1; i <= N; i++)
    {
        int num, w;
        scanf("%d", &num);
        addEdge(0, i, 1);
        for(int j = 0; j < num; j++)
        {
            scanf("%d", &w);
            addEdge(i, N + w, 1);
        }
    }
    for(int i = 1; i <= M; i++)
    {
        addEdge(N + i, N + M + 1, 1);
    }
    int minFlow;
    while(BFS())
    {
        memset(work, 0, sizeof work);
        minFlow = 0;
        while(1)
        {
            minFlow = DFS(0, 987654321);
            if(minFlow == 0)
                break;
            result += minFlow;
        }
    }
    printf("%d", result);
}