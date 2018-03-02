#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int start, end, weight;
}Data;
Data Com[100005];
int N, M, parent[1005], result;

/*
컴퓨터와 컴퓨터를 연결 하는 간선들을 최소로 연결 해야 하므로
MST의 크루스칼 알고리즘을 이용한다.
크루스칼 알고리즘에 이용되는 자료구조는 union-find이다.
서로 연결이 안된 컴퓨터일 경우 union시키면서 간선 비용을 카운트 한다.
서로 연결이 되어 있는지 확인하는건 find를 이용하면 된다.
*/

//퀵정렬을 이용하여 간선들 오름차순 정렬
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

//각 컴퓨터의 조상 확인
int find(int node)
{
    if(node == parent[node])
    {
        return node;
    }
    return parent[node] = find(parent[node]);
}

//각 컴퓨터를 연결 시킴
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
    scanf("%d %d", &N, &M);
    //parent배열을 각각 자신으로 초기화
    for(int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &Com[i].start, &Com[i].end, &Com[i].weight);
    }
    //간선 정렬
    sort(Com, 0, M - 1);
    for(int i = 0; i < M; i++)
    {
        int start, end;
        start = find(Com[i].start);
        end = find(Com[i].end);
        //다른 집합이면 합치면서 간선 카운트
        if(start != end)
        {
            result += Com[i].weight;
            uni(start, end);
        }
    }
    printf("%d", result);
}