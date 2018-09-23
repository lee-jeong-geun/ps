#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, garo[505], sero[505], result, Max;

/*
행, 열 모두 확인하면 된다.
*/

//각 숫자 9 개수 확인
int nineCount(int num)
{
    int count = 0;
    while(num != 0)
    {
        if(num % 10 == 9)
        {
            count++;
        }
        num /= 10;
    }
    return count;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int num, temp;
            scanf("%d", &num);
            temp = nineCount(num);
            garo[j] += temp;
            sero[i] += temp;
            result += temp;
        }
    }
    for(int i = 0; i < n; i++)
    {
        Max = max(Max, sero[i]);
    }
    for(int i = 0; i < m; i++)
    {
        Max = max(Max, garo[i]);
    }
    printf("%d", result - Max);
}