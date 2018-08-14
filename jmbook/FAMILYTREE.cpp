//sparse table

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int>vec[100005];
int N, Q, parent[100005][17], depth[100005];

void func(int node, int dep)
{
    depth[node] = dep;
    for(int i = 0; i < vec[node].size(); i++)
    {
        int next;
        next = vec[node][i];
        parent[next][0] = node;
        for(int j = 1; j < 17; j++)
        {
            parent[next][j] = parent[parent[next][j - 1]][j - 1];
        }
        func(next, dep + 1);
    }
}

int searchLCA(int a, int b)
{
    int count = 0;
    if(depth[a] > depth[b])
    {
        swap(a, b);
    }
    for(int i = 16; i >= 0; i--)
    {
        if(depth[b] - depth[a] >= (1 << i))
        {
            count += (1 << i);
            b = parent[b][i];
        }
    }
    for(int i = 16; i >= 0; i--)
    {
        if(parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
            count += (1 << i) * 2;
        }
    }
    if(a != b)
    {
        count += 2;
    }
    return count;
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        memset(parent, 0, sizeof parent);
        scanf("%d %d", &N, &Q);
        for(int i = 0; i < N; i++)
        {
            vec[i].clear();
        }
        for(int i = 1; i < N; i++)
        {
            int p;
            scanf("%d", &p);
            vec[p].push_back(i);
        }
        func(0, 0);
        for(int i = 0; i < Q; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", searchLCA(a, b));
        }
    }
}


//segment Tree


#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int>vec[100005], arr;
int N, Q, segTree[800005], depth[100005], idx,  NodetoNum[100005], NumtoNode[100005], First[100005];

void func(int node, int dep)
{
    NodetoNum[node] = idx;
    NumtoNode[idx] = node;
    First[node] = arr.size();
    depth[node] = dep;
    idx++;
    arr.push_back(NodetoNum[node]);
    for(int i = 0; i < vec[node].size(); i++)
    {
        func(vec[node][i], dep + 1);
        arr.push_back(NodetoNum[node]);
    }
}

int init(int left, int right, int node)
{
    if(left == right)
    {
        return segTree[node] = arr[left];
    }
    int mid;
    mid = (left + right) / 2;
    return segTree[node] = min(init(left, mid, node * 2), init(mid + 1, right, node * 2 + 1));
}

int query(int start, int end, int left, int right, int node)
{
    if(end < left || start > right)
    {
        return 987654321;
    }
    if(start <= left && right <= end)
    {
        return segTree[node];
    }
    int mid;
    mid = (left + right) / 2;
    return min(query(start, end, left, mid, node * 2), query(start, end, mid + 1, right, node * 2 + 1));
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        scanf("%d %d", &N, &Q);
        for(int i = 0; i < N; i++)
        {
            vec[i].clear();
        }
        arr.clear();
        idx = 0;
        for(int i = 1; i < N; i++)
        {
            int p;
            scanf("%d", &p);
            vec[p].push_back(i);
        }
        func(0, 0);
        init(0, arr.size() - 1, 1);
        for(int i = 0; i < Q; i++)
        {
            int a, b, lca;
            scanf("%d %d", &a, &b);
            if(First[a] > First[b])
            {
                swap(a, b);
            }
            lca = NumtoNode[query(First[a], First[b], 0, arr.size() - 1, 1)];
            printf("%d\n", depth[a] + depth[b] - depth[lca] * 2);
        }
    }
}