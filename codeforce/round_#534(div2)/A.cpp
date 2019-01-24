#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int k;

/*
1부터 9사이의 숫자들중 최소 종류로 n을 수들의 합으로 나타내는 것이다.
최소 종류라서 1들의 합으로 n을 나타내었다.
*/

int main()
{
    scanf("%d", &k);
    printf("%d\n", k);
    for(int i = 0; i < k; i++)
    {
        printf("%d ", 1);
    }
}