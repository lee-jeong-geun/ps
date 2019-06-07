#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[500005], result;

/*
작은 고리들을 해제 해서 연결하는게 가장 이득이다. 그 이유는 고리를 남김없이 연결하는것에 쓴다면
남는것 보다 한개를 더 연결 시킬수 있기 때문이다. 따라서 정렬 후 작은것부터 해제 해서 연결 시킨다.
이때 작은것을 해제 해서 연결 시킬때 고리를 전부 못쓰고 남을 수 있으므로 고리가 한개 더 남아 있는것으로
처리 해주어야 한다.
*/

int main()
{
    int num;
    scanf("%d", &N);
    num = N;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    for(int i = 0; i < N; i++)
    {
        if(num == 1)
            break;
        result += min(arr[i], num - 1);
        if(arr[i] <= num - 1)
            num--;
        num -= min(arr[i], num - 1);
    }
    printf("%d", result);
}