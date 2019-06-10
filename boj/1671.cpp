#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Edge
{
    int v, capa, rev;
    Edge(int v, int capa, int rev) : v(v), capa(capa), rev(rev) {}
};
typedef struct _data
{
    int a, b, c;
}Data;
vector<vector<Edge>> vec;
Data arr[55];
int N, level[105], work[105], result;

/*
상어들을 최대한 매칭 시켜야 한다.
이때 최대한 우선순위가 높은 상어들은 우선순위가 높은 상어들끼리 매칭 시켜야 
매칭을 많이 할 수 있다. 따라서 상어들의 조건들을 내림 차순 정렬을 하여
높은 상어는 높은 상어들에게 매칭을 시키면 된다.
*/

void addEdge(int start, int end, int capa)
{
    vec[start].emplace_back(end, capa, vec[end].size());
    vec[end].emplace_back(start, 0, vec[start].size() - 1);
}

bool comp(Data &t, Data &u)
{
    if(t.a == u.a)
    {
        if(t.b == u.b)
        {
            return t.c > u.c;
        }
        return t.b > u.b;
    }
    return t.a > u.a;
}

int BFS()
{
    memset(level, -1, sizeof level);
    queue<int> q;
    q.push(0);
    level[0] = 0;
    while(!q.empty())
    {
        int temp = q.front();
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
    return level[N + N + 1] != -1;
}

int DFS(int node, int f)
{
    if(node == N * 2 + 1)
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
            if(minFlow != 0)
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
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].c);
    }
    sort(arr + 1, arr + N + 1, comp);
    vec.resize(N * 2 + 5);
    for(int i = 1; i <= N; i++)
    {
        //소스와 상어를 매칭
        addEdge(0, i, 2);
        //싱크와 상어를 매칭
        addEdge(N + i, N * 2 + 1, 1);
        for(int j = i + 1; j <= N; j++)
        {
            //i번째 상어가 j번째 상어를 먹을 수 있는 경우
            if(arr[i].a >= arr[j].a && arr[i].b >= arr[j].b && arr[i].c >= arr[j].c)
            {
                addEdge(i, N + j, 1);
            }
        }
    }
    int minFlow;
    while(BFS())
    {
        memset(work, 0, sizeof work);
        while(1)
        {
            minFlow = DFS(0, 987654321);
            if(minFlow == 0)
                break;
            result += minFlow;
        }
    }
    printf("%d", N - result);
}