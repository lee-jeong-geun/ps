#include <cstdio>
#include <iostream>
using namespace std;
int MaxHeap[200005], MinHeap[200005], Maxidx, Minidx, N, A, B, arr[200005], result, Mid;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Maxpush(int num)
{
    MaxHeap[++Maxidx] = num;
    int point;
    point = Maxidx;
    while(point != 1)
    {
        if(MaxHeap[point] < MaxHeap[point / 2])
        {
            break;
        }
        swap(MaxHeap[point], MaxHeap[point / 2]);
        point /= 2;
    }
}

int Maxpop()
{
    int temp;
    temp = MaxHeap[1];
    MaxHeap[1] = MaxHeap[Maxidx];
    Maxidx--;
    int point;
    point = 1;
    while(point * 2 <= Maxidx)
    {
        int tpoint;
        tpoint = point * 2;
        if(MaxHeap[tpoint] < MaxHeap[tpoint + 1])
        {
            tpoint++;
        }
        if(MaxHeap[point] > MaxHeap[tpoint])
        {
            break;
        }
        swap(MaxHeap[point], MaxHeap[tpoint]);
        point = tpoint;
    }
    return temp;
}

void Minpush(int num)
{
    MinHeap[++Minidx] = num;
    int point;
    point = Minidx;
    while(point != 1)
    {
        if(MinHeap[point] > MinHeap[point / 2])
        {
            break;
        }
        swap(MinHeap[point], MinHeap[point / 2]);
        point /= 2;
    }
}

int Minpop()
{
    int temp;
    temp = MinHeap[1];
    MinHeap[1] = MinHeap[Minidx];
    Minidx--;
    int point;
    point = 1;
    while(point * 2 <= Minidx)
    {
        int tpoint;
        tpoint = point * 2;
        if(MinHeap[tpoint] > MinHeap[tpoint + 1])
        {
            tpoint++;
        }
        if(MinHeap[point] < MinHeap[tpoint])
        {
            break;
        }
        swap(MinHeap[point], MinHeap[tpoint]);
        point = tpoint;
    }
    return temp;
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        Maxidx = 0;
        Minidx = 0;
        Mid = -1;
        scanf("%d %d %d", &N, &A, &B);
        arr[0] = 1983;
        for(int i = 1; i < N; i++)
        {
            arr[i] = ((long long)arr[i - 1] * A + B) % 20090711;
        }
        Mid = arr[0];
        result = Mid;
        for(int i = 1; i < N; i++)
        {
            if(Mid <= arr[i])
            {
                Minpush(arr[i]);
            }
            else
            {
                Maxpush(arr[i]);
            }
            if(Maxidx > Minidx)
            {
                Minpush(Mid);
                Mid = Maxpop();
            }
            else if(Maxidx + 1 < Minidx)
            {
                Maxpush(Mid);
                Mid = Minpop();
            }
            result = (result + Mid) % 20090711;
        }
        printf("%d\n", result);
    }
}