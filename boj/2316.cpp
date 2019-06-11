#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct Edge
{
    int v, capa, rev;
    Edge(int v, int capa, int rev) : v(v), capa(capa), rev(rev) {}
};
vector<vector<Edge>> vec;
int N, P, level[855], work[855], result;

/*
한개의 도시에서는 반드시 한번만 통과 가능하다. 여러 간선들의 도착지가 어떤 도시일 경우 
기존의 유량에서는 간선이 다르면 흐를수 있는 유량도 다르기 떄문에 어떤 도시에서 들어오는 유량과
나가는 유량이 1을 넘어버릴수 있다. 따라서 반드시 1개의 유량만을 흐를수 있게 하기 위해
각 도시에 유량 1을 가진 더미 노드들을 추가한다. 각 도시들에 여러 유량이 흘러도 나가는 유량은
더미 노드 덕분에 1개만이 가능하다.
*/

void addEdge(int start, int end, int capa)
{
    vec[start].emplace_back(end, capa, vec[end].size());
    vec[end].emplace_back(start, 0, vec[start].size() - 1);
}

int BFS()
{
    memset(level, -1, sizeof level);
    queue<int> q;
    q.push(1);
    level[1] = 0;
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
    return level[2] != -1;
}

int DFS(int node, int f)
{
    if(node == 2)
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
    scanf("%d %d", &N, &P);
    vec.resize(N + 5 + 450);
    //각각의 도시들에 더미 노드 추가
    for(int i = 3; i <= N; i++)
    {
        addEdge(i, i + 450, 1);
    }
    //시작 지점도 더미노드 추가
    //이유는 양방향이고 시작 지점도 입력으로 들어오기 때문
    //시작 지점은 유량이 무한이므로 큰값으로 유량을 넣음
    addEdge(1, 451, 987654321);
    //끝점도 마찬가지
    addEdge(2, 452, 987654321);
    for(int i = 0; i < P; i++)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        //더미 노드와 다른 도시와 연결
        addEdge(start + 450, end, 1);
        //양방향이라서 반대쪽도 연결
        addEdge(end + 450, start, 1);
    }    
    int minFlow;
    while(BFS())
    {
        memset(work, 0, sizeof work);
        while(1)
        {
            minFlow = DFS(1, 987654321);
            if(minFlow == 0)
                break;
            result += minFlow;
        }
    }
    printf("%d", result);
}