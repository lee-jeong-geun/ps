#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, y;
}Data;
Data Point[25];
int N;
long long result;

/*
문제를 보면 두개씩 조합하면 되는것 같지만 벡터와 관련된 문제라서
굳이 두개씩 조합하는 것보다 절반은 (0, 0)을 향하게 하고 절반은 (0, 0)에서 자기 좌표에 향하게 해도
벡터의 합을 구할수 있다.
*/

long long min(long long a, long long b)
{
    return a > b ? b : a;
}

void func(int depth, int x, int y, int lcount, int rcount)
{
    //기저 사례
    if(depth == N)
    {
        long long hap;
        hap = (long long)x * x + (long long)y * y;
        result = min(result, hap);
        return;
    }
    //절반은 (0, 0)에서 자기 좌표로 향하게
    if(lcount + 1 <= N / 2)
    {
        func(depth + 1, Point[depth].x + x, Point[depth].y + y, lcount + 1, rcount);
    }
    //절반은 (0, 0)을 향하게
    if(rcount + 1 <= N / 2)
    {
        func(depth + 1, x - Point[depth].x, y - Point[depth].y, lcount, rcount + 1);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        result = (long long)99999876543210;
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%d %d", &Point[i].x, &Point[i].y);
        }
        func(0, 0, 0, 0, 0);
        printf("#%d %lld\n", testcase, result);
    }
}