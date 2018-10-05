#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, Q[1005], result;

/*
문제 설명이 이상하다.
오름차순으로 정렬후 k가 n일때부터 내려가면서 탐색한다.
k번 이상 인용된 논문이 k편 이상일 경우 정답이다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Q[i]);
    }
    sort(Q, Q + n);
    for(int i = n; i >= 0; i--)
    {
        int count = 0;
        for(int j = n - 1; j >= 0; j--)
        {
            if(Q[j] >= i)
            {
                count++;
            }
        }
        if(count >= i)
        {
            result = i;
            break;
        }
    }
    printf("%d", result);
}