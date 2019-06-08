#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
struct Edge
{
    int v, cap, rev;
    Edge(int v, int cap, int rev) : v(v), cap(cap), rev(rev) {}
};
vector<vector<Edge>> vec;
int N, level[130], work[130], result;

/*
디닉 알고리즘을 이용하여 최대 유량을 구하면 된다.
양방향 그래프이기 때문에 간선의 역방향에도 capacity를 0이 아닌 주어진값 그대로 넣어야 한다.
또 중복된 간선들이 입력으로 들어오기 때문에 중복된 간선이 들어올 경우 기존의 capacity에 더해주면 된다.
*/

//간선 연결
int addEdge(int start, int end, int cap)
{
    vec[start].emplace_back(end, cap, vec[end].size());
    vec[end].emplace_back(start, cap, vec[start].size() - 1);
}

//각 노드들의 레벨을 구하는 BFS
int BFS()
{
    memset(level, -1, sizeof level);
    queue<int> q;
    q.push('A');
    //0부터 시작
    level['A'] = 0;
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
            //한번도 가지 않았고 흐를수 있는 용량이 남은 경우
            if(level[next] == -1 && nextCap > 0)
            {
                level[next] = level[temp] + 1;
                q.push(next);
            }
        }
    }
    //싱크를 밟으면 1리턴
    return level['Z'] != -1;
}

int DFS(int node, int f)
{
    if(node == 'Z')
        return f;
    int minFlow;
    //work배열의 기능은 DFS를 종료하고 다시 돌때 중복 탐색 방지 용도
    for(int &i = work[node]; i < vec[node].size(); i++)
    {
        int next, nextCap;
        next = vec[node][i].v;
        nextCap = vec[node][i].cap;
        //다음 노드의 레벨이 현재보다 1높고 흐를수 있는 용량이 남은 경우
        if(level[next] == level[node] + 1 && nextCap > 0)
        {
            minFlow = DFS(next, min(f, nextCap));
            //싱크 간 경우 바로 리턴
            if(minFlow != 0)
            {
                //남은 유량 감소
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
    scanf("%d", &N);
    vec.resize(130);
    for(int i = 0; i < N; i++)
    {
        char start, end;
        int cap;
        scanf(" %c %c %d", &start, &end, &cap);
        addEdge(start, end, cap);
    }
    while(BFS())
    {
        int minFlow;
        memset(work, 0, sizeof work);
        while(1)
        {
            minFlow = DFS('A', 987654321);
            //싱크를 한번도 못간 경우
            if(minFlow == 0)
                break;
            result += minFlow;
        }
    }
    printf("%d", result);
}