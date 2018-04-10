#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int N, choo[15], result, chk[15], Max;

/*
이 문제는 기본적인 완전탐색으로는 시간 초과가 난다.
전체의 가지수도 많고 테스트케이스 문제라서 전체 테스트케이스를 돌리면 1초를 넘어간다.
따라서 가지치기를 해야하는데 가지치기 방식은 순열을 만들다가 왼쪽 저울에 전체 무게의 절반 이상을 놔뒀으면
오른쪽 저울에 남은 추를 다 둬도 왼쪽이 항상 무겁다. 따라서 현재 남은 추로 만들수 있는 가지 수를 리턴하면 된다.
*/

void func(int depth, int left, int right)
{
    //왼쪽이 절반 이상일 경우
    if(left > Max / 2)
    {
        int temp, gop = 1;
        temp = N - depth;
        //2의 N제곱
        for(int i = 0; i < temp; i++)
        {
            gop *= 2;
        }
        //N!
        for(int i = temp; i >= 1; i--)
        {
            gop *= i;
        }
        result += gop;
        return;
    }
    //기저 사례
    if(depth == N)
    {
        result++;
        return;
    }
    for(int i = 0; i < N; i++)
    {
        if(chk[i] == 0)
        {
            chk[i] = 1;
            //왼쪽에 둠
            func(depth + 1, left + choo[i], right);
            chk[i] = 0;
            //오른쪽에 둠
            if(left >= right + choo[i])
            {
                chk[i] = 1;
                func(depth + 1, left, right + choo[i]);
                chk[i] = 0;
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        Max = 0;
        result = 0;
        memset(chk, 0, sizeof chk);
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &choo[i]);
            //전체 무게 측정
            Max += choo[i];
        }
        func(0, 0, 0);
        printf("#%d %d\n", testcase, result);
    }
}