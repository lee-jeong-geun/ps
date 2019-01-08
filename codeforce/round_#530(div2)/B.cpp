#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n, result = 1234567890, Max;

/*
규칙을 잘 보면 최대한 정사각형들을 최대한 밀집되게 해놓을때 세그먼트를 가장 작게 쓴다.
즉 n개의 정사각형을 1 * n, 2 * n + (나머지 존재시 1), 3 * n + (나머지 존재시 1), ....
이렇게 확인하면 된다. n의 범위는 최대 10억이므로 단순 반복문으로 탐색 하는게 아닌
소수 구하듯이 sqrt(n)까지만 탐색하면 된다.
*/

int main()
{
    scanf("%d", &n);
    int Sqrt;
    Sqrt = sqrt(n);
    for(int i = 1; i <= Sqrt; i++)
    {
        int temp;
        temp = i + n / i;
        //나머지 존재시 + 1
        if(n % i != 0)
        {
            temp++;
        }
        result = min(result, temp);
    }
    printf("%d", result);
}