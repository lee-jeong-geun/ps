#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int A, B, C, X, Y, result;

/*
반반치킨이 양념 + 후라이드 산것보다 더 이득이라면 반반치킨으로 우선 채우고 나머지는
가격이 작은 것으로 채우면 된다.
*/

int main()
{
    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
    //반반치킨이 더 손해인 경우
    if(A + B < C * 2)
    {
        result = X * A + Y * B;
    }
    else
    {
        int temp;
        result = min(X, Y) * C * 2;
        //양념치킨이 양이 더 많은 경우
        if(X > Y)
        {
            temp = (X - Y) * A;
        }
        else
        {
            temp = (Y - X) * B;
        }
        //단일 치킨으로 채운것이랑 반반치킨으로 채운것중 더 싼것
        result += min(temp, (max(X, Y) - min(X, Y)) * C * 2);
    }
    printf("%d", result);
}