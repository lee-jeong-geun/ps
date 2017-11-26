#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Heap[200005], Cur, result;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void push(int num)
{
    Heap[++Cur] = num;
    int point = Cur;
    while(point != 1)
    {
        if(Heap[point] > Heap[point / 2])
        {
            break;
        }
        swap(Heap[point], Heap[point / 2]);
        point /= 2;
    }
}

int pop()
{
    int data, point;
    data = Heap[1];
    point = 1;
    Heap[1] = Heap[Cur];
    Heap[Cur--] = 987654321;
    while(point < Cur)
    {
        int tpoint = point * 2;
        if(Heap[tpoint] > Heap[tpoint + 1])
        {
            tpoint++;
        }
        if(Heap[point] < Heap[tpoint])
        {
            break;
        }
        swap(Heap[point], Heap[tpoint]);
        point = tpoint;
    }
    return data;
}

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N * 2 + 1; i++)
    {
        Heap[i] = 987654321;
    }
    for(int i = 0; i < N; i++)
    {
        int a;
        scanf("%d", &a);
        push(a);
    }
    while(Cur > 1)
    {
        int hap = 0;
        hap = pop() + pop();
        result += hap;
        push(hap);
    }
    printf("%d", result);
}