#include <cstdio>
#include <iostream>
using namespace std;
int N, from, result[35];

/*
주어진 조건에 맞게 구현 하면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        while(result[from] != 0)
        {
            from = (from + 1) % N;
        }
        result[from] = num;
        from = (from + num) % N;
    }
    printf("%d\n", N);
    for(int i = 0; i < N; i++)
    {
        printf("%d ", result[i]);
    }
}