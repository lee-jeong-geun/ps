#include <cstdio>
#include <iostream>
using namespace std;
int A;

int main()
{
    scanf("%d", &A);
    if(A == 1)
    {
        printf("1 1\n");
        printf("1");
        return 0;
    }
    printf("%d %d\n", A * 2 - 2, 2);
    printf("1 2");
}