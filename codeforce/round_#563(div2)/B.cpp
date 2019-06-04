#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[100005], flag[5];

/*
ai + aj가 홀수가 되는 것들을 스왑해서 오름차순으로 만들어야 한다.
잘 보면 홀수가 1개이상 존재 하고 짝수가 1개이상 존재 하면 모든 수들을 스왑 가능해서
오름차순으로 만들수 있다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        flag[arr[i] % 2]++;
    }
    //홀짝 존재하는 경우
    if(flag[0] > 0 && flag[1] > 0)
    {
        sort(arr, arr + n);
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}