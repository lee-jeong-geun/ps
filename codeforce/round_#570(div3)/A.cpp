#include <bits/stdc++.h>
using namespace std;
int a, Sum;

/*
주어진 수 다음 수들중 각각의 자리수를 모두 더했을 때 4로 나누어 떨어지는 수를 찾으면 된다.
*/

int main()
{
    scanf("%d", &a);
    for(int i = a; i <= 10000; i++)
    {
        int temp = i;
        Sum = 0;
        while(temp != 0)
        {
            Sum += temp % 10;
            temp /= 10;
        }
        if(Sum % 4 == 0)
        {
            printf("%d", i);
            return 0;
        }
    }
}