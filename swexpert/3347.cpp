#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M, chk[1005], Idx[1005], Max, result;

/*
주어진 조건에 맞게 구현을 하면 된다.
탐색을 O(1)만에 하기 위해 개최 비용을 나타내는 배열을 만들어서 배열에 인덱스를 저장하였다.
저장을 할 떄는 인덱스가 제일 작은게 들어가도록 하였다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        memset(Idx, 0x3f, sizeof Idx);
        memset(chk, 0, sizeof chk);
        Max = 0;
        scanf("%d %d", &N, &M);
        for(int i = 0; i < N; i++)
        {
            int A;
            scanf("%d", &A);
            if(Idx[A] > i)
            {
                Idx[A] = i;
            }
        }
        int Minidx;
        Minidx = Idx[0];
        for(int i = 1; i <= 1000; i++)
        {
            if(Idx[i] < Minidx)
            {
                Minidx = Idx[i];
            }
            else
            {
                Idx[i] = Minidx;
            }
        }
        for(int i = 0; i < M; i++)
        {
            int B;
            scanf("%d", &B);
            chk[Idx[B]]++;
            if(Max < chk[Idx[B]])
            {
                Max = chk[Idx[B]];
                result = Idx[B];
            }
        }
        printf("#%d %d\n", testcase, result + 1);
    }
}