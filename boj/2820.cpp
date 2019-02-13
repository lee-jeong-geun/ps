#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> vec[500005];
int N, M, idx, pay[500005], startNode[500005], endNode[500005], segTree[2000005], lazy[2000005];

/*
트리 구조는 선형이 아니기 때문에 트리를 선형으로 바꿔야 하는 작업이 필요하다.
그러기 위해서는 트리를 DFS를 통해 넘버링 해줘야 한다.
루트부터 타고 내려오면서 해당 노드의 시작점과 끝점을 저장 해야 하는데 시작점은 해당 노드이고
끝점은 해당 노드의 자식 노드중 가장 번호가 큰 노드이다. 넘버링이 끝났으면 구간을 한번에 업데이트하는
lazy propagation을 이용하면 된다.
*/

//트리 펼치기
void func(int node)
{
    //해당 노드의 시작점
    startNode[node] = ++idx;
    for(int i = 0; i < vec[node].size(); i++)
    {
        func(vec[node][i]);
    }
    //해당 노드의 자식중 가장 큰 번호
    endNode[node] = idx;
}

//lazy
void update_lazy(int left, int right, int node)
{
    if(lazy[node] == 0)
    {
        return;
    }
    segTree[node] += lazy[node];
    if(left != right)
    {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int start, int end, int cost, int left, int right, int node)
{
    update_lazy(left, right, node);
    if(start > right || end < left)
    {
        return;
    }
    if(start <= left && right <= end)
    {
        lazy[node] += cost;
        update_lazy(left, right, node);
        return;
    }
    int mid;
    mid = (left + right) / 2;
    update(start, end, cost, left, mid, node * 2);
    update(start, end, cost, mid + 1, right, node * 2 + 1);
    segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

int query(int start, int end, int left, int right, int node)
{
    update_lazy(left, right, node);
    if(start > right || end < left)
    {
        return 0;
    }
    if(start <= left && right <= end)
    {
        return segTree[node];
    }
    int mid;
    mid = (left + right) / 2;
    return query(start, end, left, mid, node * 2) + query(start, end, mid + 1, right, node * 2 + 1);
}

int main()
{
    scanf("%d %d %d", &N, &M, &pay[1]);
    for(int i = 2; i <= N; i++)
    {
        int parent;
        scanf("%d %d", &pay[i], &parent);
        vec[parent].push_back(i);
    }
    func(1);
    //세그먼트 트리 초기화
    for(int i = 1; i <= N; i++)
    {
        update(startNode[i], startNode[i], pay[i], 1, N, 1);
    }
    for(int i = 0; i < M; i++)
    {
        char type;
        int a, x;
        scanf(" %c %d", &type, &a);
        if(type == 'p')
        {
            scanf("%d", &x);
            update(startNode[a] + 1, endNode[a], x, 1, N, 1);
        }
        else
        {
            printf("%d\n", query(startNode[a], startNode[a], 1, N, 1));
        }
    }
}