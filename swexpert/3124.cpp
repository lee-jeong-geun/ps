#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int start, end, weight;
}Data;
Data Edge[200005];
int V, E, parent[100005];
long long result;

/*
최소 스패닝 트리를 구하면 된다.
크루스칼 알고리즘을 이용하였다.
Union-Find 자료구조를 이용하여 서로 다른 집합일 경우 합쳐주면서 합칠때 가중치를 더해주면 된다.
*/

void init()
{
    for(int i = 0; i < 100003; i++)
    {
        parent[i] = i;
    }
    result = 0;
}

//오름 차순 정렬
bool comp(Data t, Data u)
{
    return t.weight < u.weight;
}

//조상 찾기
int find(int node)
{
    if(node == parent[node])
    {
        return node;
    }
    return parent[node] = find(parent[node]);
}

//두 집합 합치기
void uni(int a, int b)
{
    int pa, pb;
    pa = find(a);
    pb = find(b);
    if(pa != pb)
    {
        parent[pb] = pa;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        init();
        scanf("%d %d", &V, &E);
        for(int i = 0; i < E; i++)
        {
            scanf("%d %d %d", &Edge[i].start, &Edge[i].end, &Edge[i].weight);
        }
        sort(Edge, Edge + E, comp);
        for(int i = 0; i < E; i++)
        {
            if(find(Edge[i].start) != find(Edge[i].end))
            {
                uni(find(Edge[i].start), find(Edge[i].end));
                result += Edge[i].weight;
            }
        }
        printf("#%d %lld\n", testcase, result);
    }
}