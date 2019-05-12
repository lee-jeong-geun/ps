#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int A, B;

/*
A + B, A * 2 - 1, B * 2 - 1중에서 큰걸 출력하면 된다.
*/

int main()
{
    scanf("%d %d", &A, &B);
    printf("%d", max(A * 2 - 1, max(B * 2 - 1, A + B)));
}