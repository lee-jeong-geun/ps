#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int start;
    int end;
    int weight;
}Data;
Data edge[100005];
int V, E, parent[10005];
long long result;

void sort(Data *arr, int left, int right)
{
    int leftidx, rightidx, pivot;
    leftidx = left;
    rightidx = right;
    pivot = arr[(left + right) / 2].weight;
    while(leftidx <= rightidx)
    {
        while(arr[leftidx].weight < pivot)
        {
            leftidx++;
        }
        while(pivot < arr[rightidx].weight)
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

int find(int node)
{
    if(parent[node] == node)
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
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &edge[i].start, &edge[i].end, &edge[i].weight);
    }
    for(int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }
    sort(edge, 0, E - 1);
    for(int i = 0; i < E; i++)
    {
        if(find(edge[i].start) != find(edge[i].end))
        {
            result += edge[i].weight;
            uni(edge[i].start, edge[i].end);
        }
    }
    printf("%ld", result);
}