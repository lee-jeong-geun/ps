#include <bits/stdc++.h>
using namespace std;
int a, b, result;

/*
a를 b로 만드는 가장 작은 방법은 최대한 5를 이용하는 방법이다.
a와 b의 차이를 5로 나눈 나머지에 대해서만 확인하면 된다.
1, 2, 3, 4가 있는데 1, 2는 1번이고 3, 4는 2번이다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        scanf("%d %d", &a, &b);
        result = 0;
        a = abs(a - b);
        result = a / 5;
        a %= 5;
        if(a == 1 || a == 2)
            result++;
        else if(a == 3 || a == 4)
            result += 2;
        printf("%d\n", result);
    }
}