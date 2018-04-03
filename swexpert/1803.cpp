#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef struct _data
{
    int node;
    long long weight;
}Data;
vector<Data> vec[100005];
int N, M, S, E;
long long dist[100005];

/*
전형적인 다익스트라 문제이다.
다익스트라 알고리즘을 구현 하면 된다.
단 int형 범위를 초과하니 long long을 써야한다.
*/

void init()
{
    for(int i = 0; i < 100003; i++)
    {
        dist[i] = (long long)9999987654321;
        vec[i].clear();
    }
}

//다익스트라
void BFS()
{
    queue<Data>q;
    q.push({S, 0});
    dist[S] = 0;
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        for(int i = 0; i < vec[temp.node].size(); i++)
        {
            Data next;
            next.node = vec[temp.node][i].node;
            next.weight = dist[temp.node] + vec[temp.node][i].weight;
            //최소값을 갱신시 큐에 푸쉬
            if(dist[next.node] > next.weight)
            {
                dist[next.node] = next.weight;
                q.push(next);
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        init();
        scanf("%d %d %d %d", &N, &M, &S, &E);
        for(int i = 0; i < M; i++)
        {
            int s, e, w;
            scanf("%d %d %d", &s, &e, &w);
            vec[s].push_back({e, w});
            vec[e].push_back({s, w});
        }
        BFS();
        printf("#%d %lld\n", testcase, dist[E]);
    }
}