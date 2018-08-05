#include <cstdio>
#include <iostream>
using namespace std;
int MaxHeap[200005], Maxidx;

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
    MaxHeap[1] = MaxHeap[Maxidx--];
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

int main()
{
    
}