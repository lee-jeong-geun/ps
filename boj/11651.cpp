#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, y;
}Data;
Data Point[100005];
int N;

/*
N이 100000개나 되므로 O(NlogN) 정렬을 사용할수 없다.
O(NlogN)인 퀵정렬을 이용해서 y좌표를 오름차순으로 y좌표가 같으면 x좌표를 오름차순으로 정렬하면
된다.
*/

//정렬 조건
bool comp(Data t, Data u)
{
    //y가 같으면
    if(t.y == u.y)
    {
        return t.x < u.x;
    }
    return t.y < u.y;
}

//퀵 정렬
void sort(Data *arr, int left, int right)
{
    Data pivot;
    int leftidx, rightidx;
    leftidx = left;
    rightidx = right;
    pivot = arr[(left + right) / 2];
    while(leftidx <= rightidx)
    {
        while(comp(arr[leftidx], pivot))
        {
            leftidx++;
        }
        while(comp(pivot, arr[rightidx]))
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

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &Point[i].x, &Point[i].y);
    }
    sort(Point, 0, N - 1);
    for(int i = 0; i < N; i++)
    {
        printf("%d %d\n", Point[i].x, Point[i].y);
    }
}