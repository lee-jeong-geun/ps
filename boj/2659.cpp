#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int Num[5], Clock;

/*
주어진 조건에 맞게 구현 하면 된다.
*/

int minClock(int num)
{
    int temp;
    temp = num;
    for(int i = 0; i < 3; i++)
    {
        temp = temp % 1000 * 10 + temp / 1000;
        num = min(num, temp);
    }
    return num;
}

int main()
{
    for(int i = 0; i < 4; i++)
    {
        scanf("%d", &Num[i]);
    }
    Clock = Num[0] * 1000 + Num[1] * 100 + Num[2] * 10 + Num[3];
    Clock = minClock(Clock);
    int count = 0;
    for(int i = 1111; i <= Clock; i++)
    {
        int temp = 0;
        temp = minClock(i);
        if(temp == i)
        {
            count++;
        }
    }
    printf("%d", count);
}