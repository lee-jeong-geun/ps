#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Dice[10005][10], result;

/*
주어진 조건에 맞게 구현하면 된다.
*/

int func(int t, int d)
{
    for(int i = 6; i >= 1; i--)
    {
        if(i != t && i != d)
        {
            return i;
        }
    }
}

int main()
{
    scanf("%d", &N);
    int D[10];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            scanf("%d", &D[j]);
        }
        //반대편 주사위가 어떤건지 저장
        Dice[i][D[0]] = D[5];
        Dice[i][D[5]] = D[0];
        Dice[i][D[1]] = D[3];
        Dice[i][D[3]] = D[1];
        Dice[i][D[2]] = D[4];
        Dice[i][D[4]] = D[2];
    }
    //초기에 6면 모두 확인
    for(int i = 1; i <= 6; i++)
    {
        int Top, Down, count = 0;
        Down = Dice[0][i];
        Top = i;
        count += func(Top, Down);
        //나머지 주사위들 확인
        for(int j = 1; j < N; j++)
        {
            Down = Top;
            Top = Dice[j][Down];
            count += func(Top, Down);
        }
        result = max(result, count);
    }
    printf("%d", result);
}