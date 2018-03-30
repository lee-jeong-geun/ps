#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, y;
}Data;
typedef struct _data2
{
    int start, end;
    long long weight;
}Data2;
Data Point[1005];
Data2 edge[500005];
int N, eidx, parent[1005];
double E;
long long result;

/*
가장 짧은 간선들로만 연결해야 하기 때문에 union-find를 사용했다.
모든 간선들을 구한 후 간선의 길이로 오름차순 정렬 후 union-find를 이용하면 된다.
*/

int abs(int a)
{
    return a > 0 ? a : a * -1;
}

bool comp(Data2 t, Data2 u)
{
    return t.weight < u.weight;
}

//퀵 정렬
void sort(int left, int right)
{
    int leftidx, rightidx;
    leftidx = left;
    rightidx = right;
    Data2 pivot;
    pivot = edge[(left + right) / 2];
    while(leftidx <= rightidx)
    {
        while(comp(edge[leftidx], pivot))
        {
            leftidx++;
        }
        while(comp(pivot, edge[rightidx]))
        {
            rightidx--;
        }
        if(leftidx <= rightidx)
        {
            Data2 temp;
            temp = edge[leftidx];
            edge[leftidx] = edge[rightidx];
            edge[rightidx] = temp;
            leftidx++;
            rightidx--;
        }
    }
    if(left < rightidx)
    {
        sort(left, rightidx);
    }
    if(leftidx < right)
    {
        sort(leftidx, right);
    }
}

void init()
{
    result = 0;
    eidx = 0;
    for(int i = 0; i < 1003; i++)
    {
        parent[i] = i;
    }
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
    int p1, p2;
    p1 = find(node1);
    p2 = find(node2);
    if(p1 != p2)
    {
        parent[p2] = p1;
    }
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 1; testcase <= C; testcase++)
    {
        init();
        scanf("%d", &N);
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &Point[i].x);
        }
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &Point[i].y);
        }
        scanf("%lf", &E);
        //모든 간선을 구함
        for(int i = 1; i <= N; i++)
        {
            for(int j = i + 1; j <= N; j++)
            {
                edge[eidx].start = i;
                edge[eidx].end = j;
                long long xx, yy;
                xx = abs(Point[i].x - Point[j].x);
                yy = abs(Point[i].y - Point[j].y);
                xx *= xx;
                yy *= yy;
                edge[eidx++].weight = xx + yy;
            }
        }
        //간선의 길이로 정렬
        sort(0, eidx - 1);
        for(int i = 0; i < eidx; i++)
        {
            //다른 집합이면 합치고 간선의 길이를 더함
            if(find(edge[i].start) != find(edge[i].end))
            {
                uni(edge[i].start, edge[i].end);
                result += edge[i].weight;
            }
        }
        printf("#%d %.0lf\n", testcase, E * result);
    }
}