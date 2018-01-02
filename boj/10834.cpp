#include <cstdio>
#include <iostream>
using namespace std;
int M, result = 1, flag;

/*
각각의 바퀴의 회전수는 회전 비에 맞춰 계산 해주면 된다.
회전 방향은 규칙을 찾아보면 XOR연산이라는 결과가 나온다.
0 0 => 0
1 0 => 1
0 1 => 1
1 1 => 0
*/

int main()
{
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        int wheel1, wheel2, turn;
        scanf("%d %d %d", &wheel1, &wheel2, &turn);
        result = result / wheel1 * wheel2;
        flag ^= turn;
    }
    printf("%d %d", flag, result);
}