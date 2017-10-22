#include <cstdio>
#include <iostream>
using namespace std;
int science[4], history[2];

void sort(int *arr, int left, int right)
{
    int leftidx, rightidx, pivot;
    leftidx = left;
    rightidx = right;
    pivot = arr[(left + right) / 2];
    while(leftidx <= rightidx)
    {
        while(arr[leftidx] < pivot)
        {
            leftidx++;
        }
        while(pivot < arr[rightidx])
        {
            rightidx--;
        }
        if(leftidx <= rightidx)
        {
            int temp;
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
    for(int i = 0; i < 4; i++)
    {
        scanf("%d", &science[i]);
    }
    for(int i = 0; i < 2; i++)
    {
        scanf("%d", &history[i]);
    }
    sort(science, 0, 3);
    sort(history, 0, 1);
    printf("%d", science[1] + science[2] + science[3] + history[1]);
}