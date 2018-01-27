#include <cstdio>
#include <iostream>
using namespace std;
int N, Stack[7][300005], Top[15], P, result;

/*
6개 스택을 이용해서 n번줄의 프렛이 들어오면 n번째 스택의 Top과 비교해서
프렛이 Top에있는 것보다 작으면 Top을 프렛보다 작은게 나올때까지 pop을 해준다.
프렛이 Top에 있는 것보다 크면 스택에 push해준다.
*/

int main()
{
    scanf("%d %d", &N, &P);
    for(int i = 0; i < N; i++)
    {
        int line, p;
        scanf("%d %d", &line, &p);
        //프렛이 n번째 스택의 Top보다 작으면 프렛보다 작은게 나올때 까지 pop
        while(Stack[line][Top[line]] > p)
        {
            Top[line]--;
            result++;
        }
        //프렛이 n번째 스택의 Top보다 크면 push
        if(Stack[line][Top[line]] < p)
        {
            Top[line]++;
            Stack[line][Top[line]] = p;
            result++;
        }
    }
    printf("%d", result);
}