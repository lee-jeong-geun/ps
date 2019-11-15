#include <bits/stdc++.h>
using namespace std;
int result;

/*
a와 b의 거리를 문제의 조건에 맞게 최대한 멀리 위치 시킬 때 거리가 몇인지 구하면 된다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        int n, x, a, b, count = 0;
        scanf("%d %d %d %d", &n, &x, &a, &b);
        //편하게 하기 위해 a를 작은것, b를 큰것으로 둠
        if(a > b)
            swap(a, b);
        result = abs(a - b);
        //a를 최대한 1로 가게 움직임
        while(count < x && a > 1)
        {
            a--;
            count++;
        }
        //b를 최대한 n으로 가게 움직임
        while(count < x && b < n)
        {
            b++;
            count++;
        }
        result = max(result, abs(a - b));
        printf("%d\n", result);
    }
}