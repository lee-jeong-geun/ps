#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, K, Num[1000005], result, hap;

/*
각각의 좌표마다 앞뒤 K칸씩 확인 하는 방법은 시간이 오래 걸리므로
앞뒤 K칸씩 총 2K + 1칸짜리 박스를 만들어서 오른쪽으로 이동시키면서 이동 시킬 때마다 맨 왼쪽의 좌표에 있는 얼음을
빼주고 맨오른쪽의 얼음을 더하는 방식을 이용하면 된다.
*/

int main()
{
    scanf("%d %d", &N, &K);
    int Maxx = 0;
    for(int i = 0; i < N; i++)
    {
        int x, cold;
        scanf("%d %d", &cold, &x);
        Num[x] = cold;
        result += cold;
        Maxx = max(Maxx, x);
    }
    //2K + 1이 전체 크기보다 큰 경우
    if(2 * K >= Maxx - 1)
    {
        printf("%d", result);
        return 0;
    }
    int l, r;
    //맨 왼쪽, 맨 오른쪽
    l = 0;
    r = 2 * K;
    for(int i = 0; i <= 2 * K; i++)
    {
        hap += Num[i];
    }
    result = hap;
    while(r < Maxx)
    {
        //맨왼쪽을 빼주고 맨오른쪽을 더해줌
        hap = hap - Num[l] + Num[r + 1];
        l++;
        r++;
        result = max(result, hap);
    }
    printf("%d", result);
}