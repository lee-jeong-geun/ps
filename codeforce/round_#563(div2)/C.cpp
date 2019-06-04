#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, chk[100005], Count;

/*
잘 보면 최대값은 소수의 개수가 된다.
따라서 에라토스테네스의 체를 이용하여 배수들을 전부 처리하면서 값을 넣으면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
    {
        if(chk[i] == 0)
        {
            Count++;
            chk[i] = Count;
            for(int j = i + i; j <= n; j += i)
            {
                chk[j] = Count;
            }
        }
    }
    for(int i = 2; i <= n; i++)
    {
        printf("%d ", chk[i]);
    }
}