#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int start;
    int end;
}Data;
Data Line[1000005];
int N, result;

bool comp(Data t, Data u)
{
    if(t.start == u.start)
    {
        return t.end < u.end;
    }
    return t.start < u.start;
}

void sort(Data *arr, int left, int right)
{
    int leftidx, rightidx;
    Data pivot;
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
        scanf("%d %d", &Line[i].start, &Line[i].end);
    }
    sort(Line, 0, N - 1);
    int l, r;
    l = Line[0].start;
    r = Line[0].end;
    result = r - l;
    for(int i = 1; i < N; i++)
    {
        if(Line[i].start <= r && r <= Line[i].end)
        {
            result += Line[i].end - r;
            r = Line[i].end;
        }
        else if(Line[i].start > r)
        {
            l = Line[i].start;
            r = Line[i].end;
            result += r - l;
        }
    }
    printf("%d", result);
}