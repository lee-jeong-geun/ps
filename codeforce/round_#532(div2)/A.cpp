#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, k, Num[105], result, Sum[5];

/*
n개 전체를 돌면서 현재 고른 idx에서 앞뒤로 k개 차이나는 인덱스를 계속 삭제 시킨다음
남은 1의 개수와 -1의 개수의 차이의 최대값을 찾으면 된다.
*/

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Num[i]);
        //전체 개수
        Sum[Num[i] + 1]++;
    }
    for(int i = 0; i < n; i++)
    {
        int temp[5] = {0};
        //앞으로 k번씩 뜀
        for(int j = i; j < n; j += k)
        {
            temp[Num[j] + 1]++;
        }
        //뒤로 k번씩 뜀
        for(int j = i - k; j >= 0; j -= k)
        {
            temp[Num[j] + 1]++;
        }
        result = max(result, abs(Sum[2] - temp[2] - (Sum[0] - temp[0])));
    }
    printf("%d", result);
}