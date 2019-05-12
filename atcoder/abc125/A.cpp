#include <cstdio>
#include <iostream>
using namespace std;
int A, B, T;

/*
T초동안 비스킷을 몇개 만드는지 구하면 된다.
*/

int main()
{
    scanf("%d %d %d", &A, &B, &T);
    printf("%d", T / A * B);
}