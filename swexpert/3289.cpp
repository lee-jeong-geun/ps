#include <cstdio>
#include <iostream>
using namespace std;
int n, m, parent[1000005];

/*
union-find 자료구조를 이용하는 간단한 문제이다.
*/

int find(int node)
{
    if(node == parent[node])
    {
        return node;
    }
    return parent[node] = find(parent[node]);
}

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
        scanf("%d %d", &n, &m);
        for(int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
        printf("#%d ", testcase);
        for(int i = 0; i < m; i++)
        {
            int f, a, b;
            scanf("%d %d %d", &f, &a, &b);
            if(f == 0)
            {
                uni(a, b);
            }
            else
            {
                if(find(a) == find(b))
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
            }
        }
        printf("\n");
    }
}