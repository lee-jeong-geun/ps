#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int start, end, weight;
}Data;
Data edge[1000005];
int N, M, parent[100005], result, joincount;

/*
한개의 마을을 두개의 마을로 분리 해야하는데 각각의 마을들의 집들은 서로 통할수 있어야한다.
그리고 서로 통하게 해주는 길들의 유지비를 최소로 하는것은 곧 간선들의 합을 최소로 한다는 것이므로
MST알고리즘의 크루스칼을 이용하면 된다. 
간선들을 오름차순으로 정렬후 간선들의 양 노드가 연결이 되어있지 않다면 union 시켜주면 된다.
근데 두 마을로 분리를 시켜야 하므로 양 노드를 union할때마다 카운트를 해준다.
그 카운트가 전체 노드의 -2개가 되면 두 마을로 분리가 되었다는 뜻이다.
따라서 카운트가 전체 노드의 -2가 된다면 종료를 하고 출력 하면 된다.
*/

//퀵정렬
void sort(Data *arr, int left, int right)
{
    int leftidx, rightidx;
    leftidx = left;
    rightidx = right;
    Data pivot;
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

//각 집들을 하나의 마을로 연결
void uni(int node1, int node2)
{
    int p1, p2;
    p1 = find(node1);
    p2 = find(node2);
    if(p1 != p2)
    {
        //두마을로 분리 되었는지 확인하는 변수
        joincount++;
        parent[p2] = p1;
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    //각각의 집들의 조상을 자기 자신으로 초기화
    for(int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &edge[i].start, &edge[i].end, &edge[i].weight);
    }
    sort(edge, 0, M - 1);
    for(int i = 0; i < M; i++)
    {
        //두마을로 분리 되었다는 뜻
        if(joincount == N - 2)
        {
            break;
        }
        //서로 다른 마을이면 union 시킴
        if(find(edge[i].start) != find(edge[i].end))
        {
            uni(find(edge[i].start), find(edge[i].end));
            result += edge[i].weight;
        }
    }
    printf("%d", result);
}