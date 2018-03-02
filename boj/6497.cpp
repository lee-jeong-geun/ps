#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int start, end, weight;
}Data;
Data edge[200005];
int m, n, linehap, result, parent[200005];

/*
모든 길마다 켜져 있는 가로등중 일부만 켜서 최대로 절약 해야 한다.
가로등을 끈다면 연결되어있는 두집은 왕래를 하지 못한다. 하지만 다른 집들을 통해서
두 집을 이동할수 있다면 두 집은 연결 되어있는 것이다. 최소의 비용으로 모든 집들을
연결 시켜야 하는데 MST를 이용하면 된다.
가로등 유지비용을 오름차순으로 정렬후 각 가로등에 연결되어있는 집들이 서로 연결되어있지
않다면 union시키면 된다.
이렇게 전부 연결시키고 가로등 전체가 켜져있을때의 비용에서 최소로만 킨 가로등 유지비를 빼면된다.
*/

//퀵정렬
void sort(Data *arr, int left, int right)
{
    int leftidx, rightidx;
    Data pivot;
    leftidx = left;
    rightidx = right;
    pivot = arr[(left + right) / 2];
    while(leftidx <= rightidx)
    {
        while(arr[leftidx].weight < pivot.weight)
        {
            leftidx++;
        }
        while(pivot.weight < arr[rightidx].weight)
        {
            rightidx--;
        }
        if(leftidx <= rightidx)
        {
            Data temp;
            temp = arr[leftidx];
            arr[leftidx] = arr[rightidx];
            arr[rightidx] = temp;
            leftidx++;
            rightidx--;
        }
    }
    if(left < rightidx)
    {
        sort(arr, left, rightidx);
    }
    if(leftidx < right)
    {
        sort(arr, leftidx, right);
    }
}

//각 집들의 조상 확인
int find(int node)
{
    if(node == parent[node])
    {
        return node;
    }
    return parent[node] = find(parent[node]);
}

//각 집들을 하나로 연결
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
    while(1)
    {
        linehap = 0;
        result = 0;
        scanf("%d %d", &m, &n);
        //각각의 집들의 조상을 자기 자신으로 초기화
        for(int i = 0; i <= m; i++)
        {
            parent[i] = i;
        }
        if(m == 0 && n == 0)
        {
            break;
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &edge[i].start, &edge[i].end, &edge[i].weight);
            //가로등 전체를 켰을때 비용을 구함
            linehap += edge[i].weight;
        }
        sort(edge, 0, n - 1);
        for(int i = 0; i < n; i++)
        {
            //서로 연결이 되어있지 않은 집이라면 연결
            if(find(edge[i].start) != find(edge[i].end))
            {
                uni(edge[i].start, edge[i].end);
                result += edge[i].weight;
            }
        }
        printf("%d\n", linehap - result);
    }
}