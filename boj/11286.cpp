#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, cur;
long long Heap[200005];

void init()
{
    for(int i = 0; i < 200005; i++)
    {
        Heap[i] = 9876543210;
    }
}

void swap(long long &a, long long &b)
{
    long long temp;
    temp = a;
    a = b;
    b = temp;
}

void push(int num)
{
    int curtemp;
    cur++;
    Heap[cur] = num;
    curtemp = cur;
    while(curtemp != 1)
    {
        if(abs(Heap[curtemp]) < abs(Heap[curtemp / 2]))
        {
            swap(Heap[curtemp], Heap[curtemp / 2]);
        }
        else if(abs(Heap[curtemp]) == abs(Heap[curtemp / 2]))
        {
            if(Heap[curtemp] < Heap[curtemp / 2])
            {
                swap(Heap[curtemp], Heap[curtemp / 2]);
            }
        }
        curtemp /= 2;
    }
}

long long pop()
{
    long long Min;
    int curtemp = 1, data;
    if(cur == 0)
    {
        return 0;
    }
    data = Heap[curtemp];
    Heap[1] = Heap[cur--];
    Heap[cur + 1] = 9876543210;
    while(1)
    {
        if(curtemp > cur)
        {
            break;
        }
        Min = min(abs(Heap[curtemp * 2]), abs(Heap[curtemp * 2 + 1]));
        if(Min > abs(Heap[curtemp]))
        {
            break;
        }
        if(abs(Heap[curtemp * 2]) == abs(Heap[curtemp * 2 + 1]))
        {
            if(Heap[curtemp * 2] < Heap[curtemp * 2 + 1])
            {
                swap(Heap[curtemp], Heap[curtemp * 2]);
                curtemp *= 2;
            }
            else
            {
                swap(Heap[curtemp], Heap[curtemp * 2 + 1]);
                curtemp = curtemp * 2 + 1;
            }
        }
        else
        {
            if(abs(Heap[curtemp * 2]) == Min)
            {
                swap(Heap[curtemp], Heap[curtemp * 2]);
                curtemp *= 2;
            }
            else
            {
                swap(Heap[curtemp], Heap[curtemp * 2 + 1]);
                curtemp = curtemp * 2 + 1;
            }
        }
    }
    return data;
}

int main()
{
    init();
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int a;
        scanf("%d", &a);
        if(a == 0)
        {
            printf("%ld\n", pop());
        }
        else
        {
            push(a);
        }
    }
}