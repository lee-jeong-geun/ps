#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Maxheap[100005], Minheap[100005], Maxcur, Mincur, result;

/*
수를 받을때마다 정렬을 한다면 시간복잡도가 N^2logN 이 된다.
N은 100000이라서 시간초과가 나게 된다.
매번 정렬을 하지말고 중간값과 힙2개를 이용하면 된다
중간값을 맨처음 수로 초기화 해주고
중간값보다 크면 Min힙에 저장 작다면 Max힙에 저장한다
이렇게 하는 이유는 중간값은 수가 1개씩 들어오기때문에 0칸 또는 1칸씩 움직인다.
그걸 이용해서 중간값의 왼쪽 수보다 오른쪽 수가 더 많아진다면 중간값을 오른쪽으로 이동시킨다
힙을 이용하였기 때문에 중간값의 바로 오른쪽수를 쉽게 찾을수 있다. 중간값의 오른쪽은 중간값 보다
큰수들 중에서 가장 작기 때문에 Min힙을 이용하였고 왼쪽은 중간값보다 작은수들 중에서 가장 크기 때문에
Max힙을 이용하였다.
*/

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Maxpush(int data)
{
    Maxheap[++Maxcur] = data;
    int point = Maxcur;
    while(point != 1)
    {
        if(Maxheap[point] < Maxheap[point / 2])
        {
            break;
        }
        swap(Maxheap[point], Maxheap[point / 2]);
        point /= 2;
    }
}

int Maxpop()
{
    int tdata;
    tdata = Maxheap[1];
    Maxheap[1] = Maxheap[Maxcur--];
    int point = 1;
    while(point * 2 <= Maxcur)
    {
        int tpoint;
        tpoint = point * 2;
        if(Maxheap[tpoint] < Maxheap[tpoint + 1])
        {
            tpoint++;
        }
        if(Maxheap[point] > Maxheap[tpoint])
        {
            break;
        }
        swap(Maxheap[point], Maxheap[tpoint]);
        point = tpoint;
    }
    return tdata;
}

void Minpush(int data)
{
    Minheap[++Mincur] = data;
    int point = Mincur;
    while(point != 1)
    {
        if(Minheap[point] > Minheap[point / 2])
        {
            break;
        }
        swap(Minheap[point], Minheap[point / 2]);
        point /= 2;
    }
}

int Minpop()
{
    int tdata;
    tdata = Minheap[1];
    Minheap[1] = Minheap[Mincur--];
    int point = 1;
    while(point * 2 <= Mincur)
    {
        int tpoint;
        tpoint = point * 2;
        if(Minheap[tpoint] > Minheap[tpoint + 1])
        {
            tpoint++;
        }
        if(Minheap[point] < Minheap[tpoint])
        {
            break;
        }
        swap(Minheap[point], Minheap[tpoint]);
        point = tpoint;
    }
    return tdata;
}

int main()
{
    for(int i = 0; i <= 100000; i++)
    {
        Minheap[i] = 987654321;
        Maxheap[i] = -987654321;
    }
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        if(i == 0)
        {
            //중간값 초기화
            result = num;
        }
        else
        {
            //중간값 보다 클경우 Min힙 푸쉬
            if(result <= num)
            {
                Minpush(num);
            }
            //중간값 보다 작을경우 Max힙 푸쉬
            else
            {
                Maxpush(num);
            }
            //오른쪽이 왼쪽보다 더 많아서 중간이 바뀌어야될 경우
            if(Maxcur + 2 == Mincur)
            {
                Maxpush(result);
                result = Minpop();
            }
            //왼쪽이 오른쪽 보다 더 많아서 중간이 바뀌어야될 경우
            //+1인 이유는 외친 개수가 짝수개라면 중간에 있는 수중 작은수를 말하라고 했기 때문
            else if(Maxcur == Mincur + 1)
            {
                Minpush(result);
                result = Maxpop();
            }
        }
        printf("%d\n", result);
    }
}