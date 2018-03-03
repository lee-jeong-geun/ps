#include <cstdio>
#include <iostream>
using namespace std;
char A[100005], B[100005];

/*
&연산, |연산, ^연산, ~연산을 해주면 된다.
단 비트가 100000개 이므로 int나, long long에 담지를 못하므로 char형 배열로 받아줘야 한다.
*/

int main()
{
    scanf("%s %s", A, B);
    for(int i = 0; i < 100000; i++)
    {
        printf("%d", (A[i] - '0') & (B[i] - '0'));
    }
    printf("\n");
    for(int i = 0; i < 100000; i++)
    {
        printf("%d", (A[i] - '0') | (B[i] - '0'));
    }
    printf("\n");
    for(int i = 0; i < 100000; i++)
    {
        printf("%d", (A[i] - '0') ^ (B[i] - '0'));
    }
    printf("\n");
    for(int i = 0; i < 100000; i++)
    {
        printf("%d", !(A[i] - '0'));
    }
    printf("\n");
    for(int i = 0; i < 100000; i++)
    {
        printf("%d", !(B[i] - '0'));
    }
    printf("\n");
}