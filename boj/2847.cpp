#include <cstdio>
#include <iostream>
using namespace std;
int N, score[105], result;

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &score[i]);
    }
    for(int i = N - 2; i >= 0; i--)
    {
        if(score[i] >= score[i + 1])
        {
            result += score[i] - score[i + 1] + 1;
            score[i] = score[i + 1] - 1;
        }
    }
    printf("%d", result);
}