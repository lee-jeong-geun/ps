#include <cstdio>
#include <iostream>
using namespace std;
int N, M, box[105];

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        int I, J, K;
        scanf("%d %d %d", &I, &J, &K);
        for(int j = I; j <= J; j++)
        {
            box[j] = K;
        }
    }
    for(int i = 1; i <= N; i++)
    {
        printf("%d ", box[i]);
    }
}