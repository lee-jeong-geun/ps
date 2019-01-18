#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, K, chk[200005], result, dcount;

/*
종류가 K보다 크면 제일 작은 개수부터 종류가 K가 될때 까지 없애면 된다.
*/

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        //종류 카운트
        if(chk[num] == 0)
        {
            dcount++;
        }
        chk[num]++;
    }
    sort(chk + 1, chk + N + 1);
    for(int i = 1; i <= N; i++)
    {
        if(chk[i] == 0)
        {
            continue;
        }
        if(dcount <= K)
        {
            break;
        }
        dcount--;
        result += chk[i];
    }
    printf("%d", result);
}