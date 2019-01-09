//Binary Search, BFS

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
typedef struct _data
{
    double x;
    double y;
}Data;
Data point[105];
int N, chk[105];
double result;

int func(double dis)
{
    memset(chk, 0, sizeof chk);
    int count = 1;
    queue<int> q;
    q.push(0);
    chk[0] = 1;
    while(!q.empty())
    {
        int temp;
        temp = q.front();
        q.pop();
        for(int i = 0; i < N; i++)
        {
            double x, y, Sqrt;
            if(chk[i] == 0)
            {
                x = point[temp].x - point[i].x;
                y = point[temp].y - point[i].y;
                Sqrt = sqrt(x * x + y * y);
                if(Sqrt <= dis)
                {
                    chk[i] = 1;
                    q.push(i);
                    count++;
                }
            }
        }
    }
    if(count == N)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        result = 987654321;
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%lf %lf", &point[i].x, &point[i].y);
        }
        double l, r;
        l = 0;
        r = 1000;
        while(l <= r)
        {
            double mid;
            mid = (l + r) / 2;
            if(func(mid) == 1)
            {
                r = mid - 0.00001;
                result = min(result, mid);
            }
            else
            {
                l = mid + 0.00001;
            }
        }
        printf("%0.2lf\n", result);
    }
}



//MST

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct _data
{
    double x;
    double y;
}Data;
typedef struct _data2
{
    int start;
    int end;
    double weight;
}Data2;
Data point[105];
Data2 edge[10005];
int N, idx, parent[105];
double result;

bool comp(Data2 t, Data2 u)
{
    return t.weight < u.weight;
}

int find(int node)
{
    if(node == parent[node])
    {
        return node;
    }
    return parent[node] = find(parent[node]);
}

void uni(int node1, int node2)
{
    int pnode1, pnode2;
    pnode1 = find(node1);
    pnode2 = find(node2);
    if(pnode1 != pnode2)
    {
        parent[pnode2] = pnode1;
    }
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        result = 0;
        idx = 0;
        scanf("%d", &N);
        for(int i = 1; i <= N; i++)
        {
            parent[i] = i;
        }
        for(int i = 1; i <= N; i++)
        {
            scanf("%lf %lf", &point[i].x, &point[i].y);
        }
        for(int i = 1; i <= N; i++)
        {
            double x, y;
            for(int j = i + 1; j <= N; j++)
            {
                edge[idx].start = i;
                edge[idx].end = j;
                x = point[i].x - point[j].x;
                y = point[i].y - point[j].y;
                edge[idx++].weight = sqrt(x * x + y * y);
            }
        }
        sort(edge, edge + idx, comp);
        for(int i = 0; i < idx; i++)
        {
            if(find(edge[i].start) != find(edge[i].end))
            {
                uni(edge[i].start, edge[i].end);
                result = max(result, edge[i].weight);
            }
        }
        printf("%0.2lf\n", result);
    }
}
