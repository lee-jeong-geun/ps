#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, B, H[25], result;

/*
전체 탐색하면서 B보다 클때 B와의 차이가 최소인 경우를 찾으면 된다.
*/

void func(int depth, int hap)
{
    if(depth == N)
    {
        if(hap >= B)
        {
            result = min(result, hap - B);
        }
        return;
    }
    func(depth + 1, hap);
    func(depth + 1, hap + H[depth]);
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        result = 987654321;
        scanf("%d %d", &N, &B);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &H[i]);
        }
        func(0, 0);
        printf("#%d %d\n", testcase, result);
    }
}