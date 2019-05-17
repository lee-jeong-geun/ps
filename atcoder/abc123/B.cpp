#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[5], result = 987654321, chk[5];

/*
n이 작아서 완전탐색을 이용하여 최소값을 구하면 된다.
*/

void func(int depth, int hap)
{
    if(depth == 5)
    {
        result = min(result, hap);
        return;
    }
    for(int i = 0; i < 5; i++)
    {
        if(chk[i] == 0)
        {
            int temp = 0;
            chk[i] = 1;
            //더한값이 10의 배수가 아닌 경우
            if(depth != 4 && (hap + arr[i]) % 10 != 0)
            {
                temp = 10 - (hap + arr[i]) % 10;
            }
            func(depth + 1, hap + arr[i] + temp);
            chk[i] = 0;
        }
    }
}

int main()
{
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    func(0, 0);
    printf("%d", result);
}