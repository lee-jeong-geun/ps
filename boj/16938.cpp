#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, L, R, X, Num[20], result;

/*
모든 경우의 수를 확인 하면서 고른 개수가 2개이상, L <= 난이도 합 <= R , 최대 최소 차이가 X이상
인 경우들을 확인하면 된다.
*/

void func(int depth, int hap, int Min, int Max, int count)
{
    if(depth == N)
    {
        if(count >= 2 && hap >= L && hap <= R && Max - Min >= X)
        {
            result++;
        }
        return;
    }
    //안고르는 경우
    func(depth + 1, hap, Min, Max, count);
    //고르는 경우
    func(depth + 1, hap + Num[depth], min(Min, Num[depth]), max(Max, Num[depth]), count + 1);
}

int main()
{
    scanf("%d %d %d %d", &N, &L, &R, &X);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Num[i]);
    }
    func(0, 0, 987654321, 0, 0);
    printf("%d", result);
}