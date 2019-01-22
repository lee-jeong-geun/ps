#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, Num[1005], result = 987654321, t;

/*
최소 비용과 t값을 찾으면 되는데 n이 1000이고 나올수 있는 최대 t도 100밖에 안되므로
완전탐색을 이용하여 해결 하면 된다.
*/

int abs(int num)
{
    return num > 0 ? num : -num;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Num[i]);
    }
    for(int i = 1; i <= 100; i++)
    {
        int hap = 0;
        //최소 비용 찾기
        for(int j = 0; j < n; j++)
        {
            if(abs(i - Num[j]) > 1)
            {
                hap += abs(i - Num[j]) - 1;
            }
        }
        if(result > hap)
        {
            result = hap;
            t = i;
        }
    }
    printf("%d %d", t, result);
}