#include <cstdio>
#include <iostream>
using namespace std;
int A[200005], B[200005], An, Bn, Count, l, r;

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
    scanf("%d %d", &An, &Bn);
    for(int i = 0; i < An; i++)
    {
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < Bn; i++)
    {
        scanf("%d", &B[i]);
    }
    sort(A, 0, An - 1);
    sort(B, 0, Bn - 1);
    for(int i = 0; i < An; i++)
    {
        l = 0;
        r = Bn - 1;
        while(l <= r)
        {
            int mid;
            mid = (l + r) / 2;
            if(A[i] == B[mid])
            {
                Count++;
                break;
            }
            else if(A[i] < B[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    printf("%d", An - Count + Bn - Count);
}