#include <cstdio>
#include <iostream>
using namespace std;
int n, Stack[200005], Top;
char S[200005];

/*
홀수 인덱스의 문자가 바로 다음 인덱스의 문자와 다르게 해야 한다.
이때 문자를 지울 경우 지운 인덱스의 다음 인덱스들 모두 1씩 감소 해서 그걸 감안 하고 인덱스를 처리해야 한다.
스택에 정상 문자들을 계속 저장하면서 조건에 맞지 않는 문자들을 계속 삭제 시켜주면 된다.
*/

int main()
{
    int count = 0;
    scanf("%d %s", &n, S);
    for(int i = 0; i < n; i++)
    {
        //홀수 인덱스 문자와 그다음 인덱스 문자가 같거나 스택의 Top이 홀수이고 현재 인덱스의 문자가 같은 경우
        //잘못된 조건임
        if((i + 1 - count) % 2 == 1 && S[i] == S[i + 1] || Top % 2 == 1 && S[Stack[Top]] == S[i])
        {
            count++;
            continue;
        }
        Stack[++Top] = i;
    }
    //정상 문자가 홀수인 경우
    if(Top % 2 == 1)
    {
        Top--;
    }
    printf("%d\n", n - Top);
    for(int i = 1; i <= Top; i++)
    {
        printf("%c", S[Stack[i]]);
    }
}