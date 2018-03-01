#include <cstdio>
#include <iostream>
using namespace std;
int N, Count[10005];

/*
N이 10000000개나 주어져서 O(NlogN) 정렬을 사용할수 없다.
각각의 숫자가 1~10000이라는 조건을 이용해서 카운팅 소트를 하면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int n;
        scanf("%d", &n);
        Count[n]++;
    }
    for(int i = 0; i < 10001; i++)
    {
        while(Count[i] != 0)
        {
            printf("%d\n", i);
            Count[i]--;
        }
    }
}