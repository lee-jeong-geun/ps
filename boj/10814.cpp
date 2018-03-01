#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int idx;
    int age;
    char name[105];
}Data;
Data Stu[100005];
int N;

/*
N이 100000개나 되므로 O(N^2) 정렬은 사용하지 못하고 O(NlogN) 정렬을 사용 해야한다.
나이순으로 정렬하고 나이가 같으면 가입한 순으로 정렬하면 된다.
*/

//정렬 조건
bool comp(Data t, Data u)
{
    if(t.age == u.age)
    {
        return t.idx < u.idx;
    }
    return t.age < u.age;
}


//퀵정렬
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
        scanf("%d %s", &Stu[i].age, Stu[i].name);
        //가입 순서 저장
        Stu[i].idx = i;
    }
    sort(Stu, 0, N - 1);
    for(int i = 0; i < N; i++)
    {
        printf("%d %s\n", Stu[i].age, Stu[i].name);
    }
}