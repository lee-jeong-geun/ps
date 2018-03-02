#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int idx;
    int p[4], start, end, weight;
}Data;
Data Point[100005], edge[300005];
int N, eidx, parent[100005], result;

/*
모든 행성을 터널로 연결할 때 최소 비용을 구하는 것이다.
두 행성을 터널로 연결할 때 드는 비용은 두 행성의 x차이, y차이, z차이중 최소값이다.
모든 행성의 x좌표를 가지고 정렬후 인접한 행성과의 차이를 edge배열에 담는다.
인접한 행성과의 차이만 담는 이유는 최소 비용을 구해야 하기 때문이다.
오름차순으로 정렬을 했을때 어떤 행성과의 차이가 최소가 되는 행성은 인접한 행성이기 때문이다.
y, z좌표도 이런 식으로 다 구하고 마지막에 edge배열을 오름 차순으로 정렬 후 
크루스칼 알고리즘을 사용해서 최소 비용을 구하면 된다.
*/

//절대값 구하는 함수
int abs(int num)
{
    return num > 0 ? num : num * -1;
}

bool comp(Data t, Data u, int flag)
{
    //flag == 0 x좌표
    //flag == 1 y좌표
    //flag == 2 z좌표 정렬
    if(flag < 3)
    {
        return t.p[flag] < u.p[flag];
    }
    //edge 정렬
    return t.weight < u.weight;
}

//퀵 정렬
void sort(Data *arr, int left, int right, int flag)
{
    int leftidx, rightidx;
    Data pivot;
    leftidx = left;
    rightidx = right;
    pivot = arr[(left + right) / 2];
    while(leftidx <= rightidx)
    {
        while(comp(arr[leftidx], pivot, flag))
        {
            leftidx++;
        }
        while(comp(pivot, arr[rightidx], flag))
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
        sort(arr, left, rightidx, flag);
    }
    if(leftidx < right)
    {
        sort(arr, leftidx, right, flag);
    }
}

//각 행성의 조상을 찾는 함수
int find(int node)
{
    if(node == parent[node])
    {
        return node;
    }
    return parent[node] = find(parent[node]);
}

//두 행성을 같은 집합으로 합치는 함수
void uni(int node1, int node2)
{
    int p1, p2;
    p1 = parent[node1];
    p2 = parent[node2];
    if(p1 != p2)
    {
        parent[p2] = p1;
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &Point[i].p[0], &Point[i].p[1], &Point[i].p[2]);
        //정렬후 행성을 구분하기 위한 변수
        Point[i].idx = i;
        parent[i] = i;
    }
    for(int i = 0; i < 3; i++)
    {
        //각각의 좌표 정렬
        sort(Point, 0, N - 1, i);
        for(int j = 0; j < N - 1; j++)
        {
            //간선을 만듬
            edge[eidx].start = Point[j].idx;
            edge[eidx].end = Point[j + 1].idx;
            //두 행성의 차이를 구함
            edge[eidx++].weight = abs(Point[j].p[i] - Point[j + 1].p[i]);
        }
    }
    //비용 정렬
    sort(edge, 0, eidx - 1, 3);
    for(int i = 0; i < eidx; i++)
    {
        int node1, node2;
        node1 = find(edge[i].start);
        node2 = find(edge[i].end);
        if(node1 != node2)
        {
            uni(node1, node2);
            result += edge[i].weight;
        }
    }
    printf("%d", result);
}