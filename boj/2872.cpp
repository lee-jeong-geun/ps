#include <bits/stdc++.h>
using namespace std;
int N, arr[300005], result;

/*
N부터 2까지 자기보다 1작은 수가 앞의 인덱스에 존재 하는지 확인하면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        arr[num] = i;
    }
    for(int i = N; i >= 2; i--)
    {
        if(arr[i] < arr[i - 1])
            break;
        result++;
    }
    printf("%d", N - result - 1);
}