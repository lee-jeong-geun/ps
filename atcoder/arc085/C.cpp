#include <cstdio>
#include <iostream>
using namespace std;
int N, M, Count = 1;

/*
주어진 조건에 맞게 구현하면 된다.
*/

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        Count *= 2;
    }
    printf("%d", Count * 1900 * M + Count * 100 * (N - M));
}