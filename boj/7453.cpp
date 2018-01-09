#include <cstdio>
#include <iostream>
using namespace std;
int A[4005], B[4005], C[4005], D[4005], n, arr1[16000005], arr2[16000005], idx1, idx2;
long long result;

/*
A , B , C, D배열에서 모든 조합을 찾는 경우의 수는 N ^ 4이다.
N은 최대 4000이므로 4000 ^ 4는 무조건 시간 초과이다.
따라서 A배열과 B배열의 각 원소를 조합한 결과를 arr1배열에 저장하고
C배열과 D배열의 결과를 arr2배열에 저장한다.
arr1배열의 원소와 arr2배열의 원소를 더해서 0이 되는게 정답이므로
arr1배열과 arr2배열을 정렬후 arr1각 원소들에 대해서 이분탐색을 이용하여 arr2에 0이 되는 원소를 탐색한다.
오름차순으로 정렬 하였기 때문에 arr1의 원소와 arr2의 원소를 더한값이 0이상이면 right를 줄여준다.
right쪽으로 가봤자 더한값이 0이상이기 때문이다.
미드값 양옆의 원소가 0이될수 있는 경우가 있다.
이분탐색은 한쪽으로만 가기 때문에 반대 쪽으로 가는 경우는 while문으로 처리해 주었다.
또 arr1배열의 어떤 원소가 이전 원소와 동일할경우 0이되는 결과는 같으므로 다시 계산을 하지않고
이전 값을 바로 더해 주었다.
*/

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

//퀵 소트
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
            swap(arr[leftidx], arr[rightidx]);
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
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            //arr1배열과 arr2배열을 만듬
            arr1[idx1++] = A[i] + B[j];
            arr2[idx2++] = C[i] + D[j];
        }
    }
    sort(arr1, 0, n * n - 1);
    sort(arr2, 0, n * n - 1);
    //tcount는 이전 원소의 결과값을 저장
    long long tcount = 0;
    for(int i = 0; i < n * n; i++)
    {
        //이전 원소와 같을경우 다시 계산 하는것 방지
        if(i != 0 && arr1[i] == arr1[i - 1])
        {
            result += tcount;
            continue;
        }
        tcount = 0;
        int l, r;
        l = 0;
        r = n * n - 1;
        while(l <= r)
        {
            int mid;
            mid = (l + r) / 2;
            //합이 0이상일경우 right를 줄여 줌
            if(arr1[i] + arr2[mid] >= 0)
            {
                if(arr1[i] + arr2[mid] == 0)
                {
                    result++;
                    tcount++;
                    int tidx = 1;
                    //위에서 말한 이분탐색 반대 루트에 합이 0인 원소가 존재하는 경우
                    while(arr1[i] + arr2[mid + tidx] == 0 && mid + tidx <= r)
                    {
                        result++;
                        tcount++;
                        tidx++;
                    }
                }
                r = mid - 1;
            }
            //0보다 작을경우 left를 늘려 줌
            else
            {
                l = mid + 1;
            }
        }
    }
    printf("%lld", result);
}