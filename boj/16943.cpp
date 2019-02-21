#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int A, B, Num[15], result, Length;

/*
A의 순열중 B이하면서 가장 큰 수를 찾으면 된다.
*/

void func(int depth, int C)
{
    if(depth == Length)
    {
        if(C <= B)
        {
            result = max(result, C);
        }
        return;
    }
    for(int i = 0; i < 10; i++)
    {
        //맨처음이 0인 경우는 제외
        if(C == 0 && i == 0)
        {
            continue;
        }
        if(Num[i] > 0)
        {
            Num[i]--;
            func(depth + 1, C * 10 + i);
            Num[i]++;
        }
    }
}

int main()
{
    scanf("%d %d", &A, &B);
    while(A)
    {
        Num[A % 10]++;
        A /= 10;
        Length++;
    }
    func(0, 0);
    if(result == 0)
    {
        result = -1;
    }
    printf("%d", result);
}