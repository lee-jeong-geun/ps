#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> vec[100005];
int n, m, result[100005];

//Prefix Sum
/*
트리를 구성 후 갈굼 정도를 배열에 저장 한다.
그리고 맨위의 노드부터 자식노드로 내려오면서 갈굼 정도를 누적 시키면 된다.
*/

//Segment Tree Lazy Propagation
/*
트리를 DFS탐색 하면서 펼치고 세그먼트 트리를 이용하여 구간 업데이트를 하면 된다.
*/

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        int parent;
        scanf("%d", &parent);
        if(parent == -1)
        {
            continue;
        }
        vec[parent].push_back(i);
    }
    for(int i = 0; i < m; i++)
    {
        int num, w;
        scanf("%d %d", &num, &w);
        //갈굼 저장
        result[num] += w;
    }
    for(int i = 2; i <= n; i++)
    {
        //각 노드의 자식들에게 갈굼 전파
        for(int j = 0; j < vec[i].size(); j++)
        {
            result[vec[i][j]] += result[i];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", result[i]);
    }
}

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> vec[100005];
int n, m, Idx = -1, startNode[100005], endNode[100005], segTree[400005], lazy[400005];

//트리 펼치기
void func(int node)
{
    startNode[node] = ++Idx;
    for(int i = 0; i < vec[node].size(); i++)
    {
        func(vec[node][i]);
    }
    endNode[node] = Idx;
}

void update_lazy(int left, int right, int node)
{
    if(!lazy[node])
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
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        int parent;
        scanf("%d", &parent);
        if(parent == -1)
        {
            continue;
        }
        vec[parent].push_back(i);
    }
    func(1);
    for(int i = 0; i < m; i++)
    {
        int num, w;
        scanf("%d %d", &num, &w);
        update(startNode[num], endNode[num], w, 0, n - 1, 1);
    }
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", query(startNode[i], startNode[i], 0, n - 1, 1));
    }
}