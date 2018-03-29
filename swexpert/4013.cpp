#include <cstdio>
#include <iostream>
using namespace std;
int K, mag[5][15], result;

/*
단순 시뮬레이션 문제다.
자석 돌아가는걸 잘 구현 하면 된다.
*/

//자석 돌리는 함수
void func(int num, int flag)
{
    int turn[5] = {0};
    turn[num] = flag;
    //돌린 자석의 왼쪽 자석들을 탐색
    for(int i = num - 1; i >= 0; i--)
    {
        //극성이 반대일 경우
        if(mag[i][2] != mag[i + 1][6])
        {
            turn[i] = 0 - turn[i + 1];
        }
        else
        {
            break;
        }
    }
    //돌린 자석의 오른쪽 자석들을 탐색
    for(int i = num + 1; i < 4; i++)
    {
        //극성이 반대일 경우
        if(mag[i][6] != mag[i - 1][2])
        {
            turn[i] = 0 - turn[i - 1];
        }
        else
        {
            break;
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if(turn[i] == 0)
        {
            continue;
        }
        int change;
        change = (8 - turn[i]) % 8;
        int temp[15];
        //자석 시프트
        for(int j = 0; j < 8; j++)
        {
            temp[j] = mag[i][(j + change) % 8];
        }
        for(int j = 0; j < 8; j++)
        {
            mag[i][j] = temp[j];
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        result = 0;
        scanf("%d", &K);
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                scanf("%d", &mag[i][j]);
            }
        }
        for(int i = 0; i < K; i++)
        {
            int num, t;
            scanf("%d %d", &num, &t);
            num--;
            func(num, t);
        }
        for(int i = 0; i < 4; i++)
        {
            //점수 계산
            if(mag[i][0] == 1)
            {
                result += (1 << i);
            }
        }
        printf("#%d %d\n", testcase, result);
    }
}