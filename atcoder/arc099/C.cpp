#include <cstdio>
#include <iostream>
using namespace std;
int N, K, idx;

/*
전부 연속된 K구간의 최소값으로 바꾸는 문제이다.
이 연산을 계속하다보면 어떻게든 모든 수를 1로 바꿔야 된다.
따라서 모든 수를 1로 바꾸는 최소 연산 횟수로 볼 수 있다.
규칙을 잘 보면 K - 1개씩 1로 바꿀수 있다. 1의 위치에 상관없이
K - 1개씩 바꿀수 있으므로 1을 제외한 수들을 K - 1의 구간이 몇개 나오는지 확인하고
나머지가 존재하는지도 확인하면 된다.
*/

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
    }
    int div, temp;
    div = (N - 1) / (K - 1);
    temp = (N - 1) % (K - 1);
    if(temp != 0)
    {
        temp = 1;
    }
    printf("%d", div + temp);
}