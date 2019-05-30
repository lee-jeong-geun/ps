#include <cstdio>
#include <iostream>
using namespace std;
int N, M, C, result, B[105];

/*
주어진 조건에 맞게 구현하면 된다.
*/

int main()
{
    scanf("%d %d %d", &N, &M, &C);
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &B[i]);
    }
    for(int i = 0; i < N; i++)
    {
        int Sum = C;
        for(int j = 0; j < M; j++)
        {
            int num;
            scanf("%d", &num);
            Sum += num * B[j];
        }
        if(Sum > 0)
        {
            result++;
        }
    }
    printf("%d", result);
}