#include <cstdio>
#include <iostream>
using namespace std;
int N, A[500005], TA[500005];
long long result;

/*
N이 500000이라서 버블소트를 사용 할 수 없다.
각각의 수의 스왑 횟수는 정렬전 인덱스와 정렬후 인덱스의 차이다.
머지 소트를 이용하여 각각의 수들을 분할 하고 정렬 하는 과정에서 인덱스의 차이를 계속
더해주면 된다.
*/

void merge(int left, int right)
{
    int leftidx, rightidx, tidx = 0, mid, temp;
    mid = (left + right) / 2;
    leftidx = left;
    rightidx = mid + 1;
    while(leftidx <= mid && rightidx <= right)
    {
        if(A[leftidx] < A[rightidx])
        {
            //정렬 후 인덱스와 정렬 전 인덱스 차이
            temp = tidx + left - leftidx;
            TA[tidx++] = A[leftidx++];
        }
        else
        {
            temp = tidx + left - rightidx;
            TA[tidx++] = A[rightidx++];
        }
        if(temp > 0)
        {
            result += temp;
        }
    }
    while(leftidx <= mid)
    {
        temp = tidx + left - leftidx;
        if(temp > 0)
        {
            result += temp;
        }
        TA[tidx++] = A[leftidx++];
    }
    while(rightidx <= right)
    {
        temp = tidx + left - rightidx;
        if(temp > 0)
        {
            result += temp;
        }
        TA[tidx++] = A[rightidx++];
    }
    for(int i = 0; i < tidx; i++)
    {
        A[i + left] = TA[i];
    }
}

void sort(int left, int right)
{
    if(left == right)
    {
        return;
    }
    int mid;
    mid = (left + right) / 2;
    sort(left, mid);
    sort(mid + 1, right);
    merge(left, right);
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    sort(0, N - 1);
    printf("%ld\n", result);
}