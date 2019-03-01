#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, K, top = -1;
char Str[500005], stack[500005];

/*
수를 입력 받고 맨처음 수부터 스택에 넣어가면서 다음 수들이 스택의 top에 있는 수보다
크면 작은수가 안나올때까지 pop연산을 하는데 이때 pop연산은 최대 K번 까지이다.
그리고 K개를 반드시 지워야 하므로 K개를 안지웠다면 K개를 지운다.
*/

int main()
{
    scanf("%d %d %s", &N, &K, Str);
    for(int i = 0; i < N; i++)
    {
        while(K != 0 && top != -1 && stack[top] < Str[i])
        {
            top--;
            K--;
        }
        stack[++top] = Str[i];
    }
    top -= K;
    stack[top + 1] = 0;
    printf("%s", stack);
}