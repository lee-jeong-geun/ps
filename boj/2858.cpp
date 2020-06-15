#include <bits/stdc++.h>
using namespace std;
int R, B;

/*
수의 범위가 얼마 되지 않아서 완전탐색 돌리면 된다.
*/

int main()
{
    scanf("%d %d", &R, &B);
    for(int i = 5000; i >= 1; i--)
    {
        int temp;
        temp = (R + 4) / 2 - i;
        if(temp * i == R + B)
        {
            printf("%d %d", i, temp);
            break;
        }
    }
}