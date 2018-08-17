#include <cstdio>
#include <iostream>
using namespace std;
int N, newScore, P, score[55], result = 1;

/*
문제의 요구에 맞게 구현을 하면 된다.
*/

int main()
{
    scanf("%d %d %d", &N, &newScore, &P);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &score[i]);
    }
    for(int i = 0; i < N; i++)
    {
        //기존 점수 보다 크면 종료
        if(newScore > score[i])
        {
            break;
        }
        //P까지 갈 경우 종료
        if(i >= P - 1)
        {
            result = -1;
            break;
        }
        if(newScore < score[i])
        {
            result++;
        }
    }
    printf("%d", result);
}