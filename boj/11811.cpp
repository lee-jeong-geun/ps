#include <cstdio>
#include <iostream>
using namespace std;
int N;

/*
행렬이 주어지고 원래의 배열을 구하는 문제다. 이 행렬은 어떤 배열의 구성 원소를 
각각 구성 원소 끼리 &연산한 결과이다.
어떤 수 x와 어떤 수 y를 &연산한 결과를 z라 할때 z는 x에도 포함이 되고 y에도 포함이 된다.
따라서 어떤 수 x를 구할때는 &연산한 결과를 계속 더해 주면(|연산) 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int result = 0;
        for(int j = 0; j < N; j++)
        {
            int num;
            scanf("%d", &num);
            result = result | num;
        }
        printf("%d ", result);
    }
}