#include <cstdio>
#include <iostream>
using namespace std;
int X, A;

/*
X가 A보다 작으면 0 아니면 10을 출력하면 된다.
*/

int main()
{
    scanf("%d %d", &X, &A);
    if(X < A)
    {
        printf("0");
    }
    else
    {
        printf("10");
    }
}