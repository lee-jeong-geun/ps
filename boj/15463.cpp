#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int arr[5];
}Data;
Data Point[5];
int result;

/*
각각의 좌표들을 파악해서 겹치는 구간들을 제외 시키면 된다.
*/

int func(int idx, int start, int end)
{
    //겹치는 구간 확인
    return max(0, min(Point[idx].arr[end], Point[2].arr[end]) - max(Point[idx].arr[start], Point[2].arr[start]));
}

int main()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            scanf("%d", &Point[i].arr[j]);
        }
        if(i < 2)
        {
            result += (Point[i].arr[2] - Point[i].arr[0]) * (Point[i].arr[3] - Point[i].arr[1]);
        }
    }
    result -= func(0, 0, 2) * func(0, 1, 3);
    result -= func(1, 0, 2) * func(1, 1, 3);
    printf("%d", result);
}