#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii> vec[20005];
int V, E, K, dist[20005];

void BFS()
{
    priority_queue<pii> pq;
    pq.push({0, K});
    dist[K] = 0;
    while(!pq.empty())
    {
        pii temp;
        temp = pq.top();
        pq.pop();
        if(dist[temp.second] < -temp.first)
        {
            continue;
        }
        for(int i = 0; i < vec[temp.second].size(); i++)
        {
            pii next;
            next.second = vec[temp.second][i].second;
            next.first = -temp.first + vec[temp.second][i].first;
            if(dist[next.second] > next.first)
            {
                dist[next.second] = next.first;
                next.first *= - 1;
                pq.push(next);
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &V, &E, &K);
    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        vec[u].push_back({w, v});
    }
    memset(dist, 0x3f, sizeof dist);
    BFS();
    for(int i = 1; i <= V; i++)
    {
        if(dist[i] > 1000000000)
        {
            printf("INF\n");
        }
        else
        {
            printf("%d\n", dist[i]);
        }
    }
}