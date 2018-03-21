#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x;
    int y;
}Data;
Data Point[75005];
int n, newarr[75005], newY, segtree[300005];
long long result;

/*
섬의 쌍은 어떤 섬으로 부터 동쪽과 남쪽에 떨어져있는 어떤 섬과의 쌍이다. 하지만 이렇게 일일이 구한다면
시간 복잡도가 O(N^2)으로 시간 제한을 넘어가게 된다.
따라서 모든 쌍을 일일이 구하는 것보다 탐색하면서 값을 저장하는 방식을 써야한다.
어떤 섬과 쌍을 이루는 섬은 어떤 섬보다 북쪽에 있으면서 서쪽에 있어야 한다. 북쪽에 있으면서 
서쪽에 있는 섬들의 수를 저장하면 된다. 이 섬들을 저장할 방법은 막연하게 저장하기는 힘들기 때문에
구간을 나눠서 저장하면 된다. 이때 세그먼트 트리를 사용하게 되는데 구간을 나눠야 할게 x축과 y축 2개라서
구간을 나누기가 힘들다. y축 가지고 구간을 나누고 x축을 증가하는 방식(스위핑)으로 탐색한다면 
세그먼트 트리에 값 하나만 넣어서 구간을 나눌수 있다. 이때 값은 -10억 ~ 10억 까지라서 값을 그대로 
넣는다면 세그먼트 트리의 리프노드가 총 20억개가 되므로 메모리 제한에 걸리게 된다.
들어올수있는 섬의 개수는 최대 75000개 이므로 y축의 구간을 75000으로 압축 시키면 된다.
각 섬의 북쪽이면서 서쪽인 섬들의 개수를 세그먼트 트리를 이용해서 빠른 시간에 구하면 된다.
*/

void swap(Data &a, Data &b)
{
    Data temp;
    temp = a;
    a = b;
    b = temp;
}

bool comp(Data t, Data u, int flag)
{
    //y축 정렬
    if(flag == 0)
    {
        return t.y < u.y;
    }
    //x축 정렬
    if(t.x == u.x)
    {
        return t.y > u.y;
    }
    return t.x < u.x;
}

//퀵 소트
void sort(Data *arr, int left, int right, int flag)
{
    Data pivot;
    int leftidx, rightidx;
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
            swap(arr[leftidx], arr[rightidx]);
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

//세그먼트 트리 구간 탐색
int query(int s, int e, int left, int right, int node)
{
    //구간을 포함
    if(s <= left)
    {
        return segtree[node];
    }
    //구간 미포함
    if(s > right || e < left)
    {
        return 0;
    }
    int mid;
    mid = (left + right) / 2;
    return query(s, e, left, mid, node * 2) + query(s, e, mid + 1, right, node * 2 + 1);
}

//세그먼트 트리 구간 갱신
int update(int s, int left, int right, int node)
{
    //구간 미포함
    if(s > right || s < left)
    {
        return segtree[node];
    }
    //리프 노드일경우
    if(left == right)
    {
        return segtree[node] += 1;
    }
    int mid;
    mid = (left + right) / 2;
    return segtree[node] = update(s, left, mid, node * 2) + update(s, mid + 1, right, node * 2 + 1);
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        for(int i = 0; i < 300001; i++)
        {
            segtree[i] = 0;
        }
        result = 0;
        newY = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &Point[i].x, &Point[i].y);
        }
        //y축 정렬
        sort(Point, 0, n - 1, 0);
        //y좌표 압축
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && Point[i].y != Point[i - 1].y)
            {
                newY++;
            }
            newarr[i] = newY;
        }
        //좌표 압축 갱신
        for(int i = 0; i < n; i++)
        {
            Point[i].y = newarr[i];
        }
        //x축 정렬
        sort(Point, 0, n - 1, 1);
        for(int i = 0; i < n; i++)
        {
            //스위핑
            result += query(Point[i].y, 100000, 0, 100000, 1);
            update(Point[i].y, 0, 100000, 1);
        }
        printf("%lld\n", result);
    }
}