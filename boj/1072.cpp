#include <cstdio>
#include <iostream>
using namespace std;
int result;
long long X, Y, Z;

int main()
{
    while(scanf("%ld %ld", &X, &Y) != -1)
    {
        int mid, l = 1, r = 1000000000;
        result = 0;
        Z = (Y * 100) / X;
        mid = Z;
        while(l <= r)
        {
            mid = (l + r) / 2;
            if((Y + mid) * 100 / (X + mid) != Z)
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if(result == 0)
        {
            result = -1;
        }
        printf("%d\n", result);
    }
}