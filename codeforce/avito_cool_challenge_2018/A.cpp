#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int v, result = 1;

/*
n보다 작고 n의 약수가 아닌 양수들로 n을 최대한 작게 만들어야 한다.
간단하게 n - 1은 n의 약수가 아니고 n보다 작기 때문에 n에서 n - 1을 빠면 된다.
단 n이 2일때 n - 1인 1은 2의 약수 이기 때문에 2보다 더 작게 만들 수 없다.
*/

int main()
{
    scanf("%d", &v);
    if(v == 2)
    {
        result = 2;
    }
    printf("%d", result);
}