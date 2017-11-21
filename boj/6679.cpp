#include <cstdio>
#include <iostream>
using namespace std;

int ten(int a)
{
    int hap = 0;
    while(a != 0)
    {
        hap += a % 10;
        a /= 10;
    }
    return hap;
}

int twelve(int a)
{
    int hap = 0;
    while(a != 0)
    {
        hap += a % 12;
        a /= 12;
    }
    return hap;
}

int sixteen(int a)
{
    int hap = 0;
    while(a != 0)
    {
        hap += a % 16;
        a /= 16;
    }
    return hap;
}

int main()
{
    for(int i = 1000; i < 10000; i++)
    {
        if(ten(i) == twelve(i) && twelve(i) == sixteen(i))
        {
            printf("%d\n", i);
        }
    }
}