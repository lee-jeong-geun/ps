#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, S, Number[100005], result = 987654321, Sum;

/*
투 포인터를 이용하면 된다.
left, right를 잡고 합이 S 이상이면 left를 늘려주고 S 미만이면 right를 늘려 주면 된다.
*/

int main()
{
    scanf("%d %d", &N, &S);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &Number[i]);
    }
    int l, r;
    l = 0;
    r = 1;
    Sum = Number[r];
    while(l < r && r <= N)
    {
        if(Sum >= S)
        {
            result = min(result, r - l);
            l++;
            Sum -= Number[l];
        }
        else
        {
            r++;
            Sum += Number[r];
        }
    }
    if(result == 987654321)
    {
        result = 0;
    }
    printf("%d", result);
}