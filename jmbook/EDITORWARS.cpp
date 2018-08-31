#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, parent[10005], Dis[10005], Count[10005], flag, flagidx, result;

int find(int node)
{
    if(parent[node] == node)
    {
        return node;
    }
    return parent[node] = find(parent[node]);
}

int uni(int node1, int node2)
{
    int pnode1, pnode2;
    if(node1 == -1 || node2 == -1)
    {
        return max(node1, node2);
    }
    pnode1 = find(node1);
    pnode2 = find(node2);
    if(pnode1 == pnode2)
    {
        return pnode1;
    }
    parent[pnode2] = pnode1;
    Count[pnode1] += Count[pnode2];
    return pnode1;
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int i = 0; i < C; i++)
    {
        scanf("%d %d", &N, &M);
        result = 0;
        flag = 0;
        for(int i = 0; i < N; i++)
        {
            parent[i] = i;
            Count[i] = 1;
            Dis[i] = -1;
        }
        for(int i = 0; i < M; i++)
        {
            char op[5];
            int a, b;
            scanf("%s %d %d", op, &a, &b);
            if(flag == 1)
            {
                continue;
            }
            if(op[0] == 'A')
            {
                int Disnode;
                if(Dis[find(a)] == find(b))
                {
                    flag = 1;
                    flagidx = i;
                }
                Disnode = uni(Dis[find(a)], Dis[find(b)]);
                uni(find(a), find(b));
                Dis[find(a)] = Disnode;
                Dis[Disnode] = find(a);
            }
            else
            {
                if(find(a) == find(b))
                {
                    flag = 1;
                    flagidx = i;
                }
                uni(find(a), Dis[find(b)]);
                uni(find(b), Dis[find(a)]);
                Dis[find(a)] = find(b);
                Dis[find(b)] = find(a);
            }
        }
        for(int i = 0; i < N; i++)
        {
            if(parent[i] == i)
            {
                if(Dis[find(i)] == -1)
                {
                    result += Count[find(i)];
                }
                else
                {
                    result += max(Count[find(i)], Count[Dis[find(i)]]);
                    Count[find(i)] = 0;
                    Count[Dis[find(i)]] = 0;
                }
            }
        }
        if(flag == 1)
        {
            printf("CONTRADICTION AT %d\n", flagidx + 1);
        }
        else
        {
            printf("MAX PARTY SIZE IS %d\n", result);
        }
    }
}