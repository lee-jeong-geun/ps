#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Edge
{
    int v, cap, rev;
    Edge(int v, int cap, int rev) : v(v), cap(cap), rev(rev) {}
};
vector<vector<Edge>> vec;
int N, M, level[405], work[405], result;

/*
소를 소스에 연결 시키고 축사를 싱크에 연결 시킨후 소들을 축사에 연결 시킨다.
연결 시킬 때 capacity를 1로 잡고 최대 유량을 구하면 매칭 가능한 최대 쌍의 개수를 구할 수 있다.
*/

void addEdge(int start, int end, int cap)
{
    vec[start].emplace_back(end, cap, vec[end].size());
    vec[end].emplace_back(start, 0, vec[start].size() - 1);
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
            int next, nextCap;
            next = vec[temp][i].v;
            nextCap = vec[temp][i].cap;
            if(level[next] == -1 && nextCap > 0)
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
    int minFlow = 0;
    for(int &i = work[node]; i < vec[node].size(); i++)
    {
        int next, nextCap;
        next = vec[node][i].v;
        nextCap = vec[node][i].cap;
        if(level[next] == level[node] + 1 && nextCap > 0)
        {
            minFlow = DFS(next, min(f, nextCap));
            if(minFlow != 0)
            {
                vec[node][i].cap -= minFlow;
                vec[next][vec[node][i].rev].cap += minFlow;
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
        int s, num;
        scanf("%d", &s);
        //소스에 소들을 연결
        addEdge(0, i, 1);
        for(int j = 0; j < s; j++)
        {
            scanf("%d", &num);
            //소와 축사 연결
            addEdge(i, N + num, 1);
        }
    }
    for(int i = 1; i <= M; i++)
    {
        //축사를 싱크에 연결
        addEdge(N + i, N + M + 1, 1);
    }
    int minFlow = 0;
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