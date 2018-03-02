#include <cstdio>
#include <iostream>
using namespace std;
char Str[55];
int alph[35];

/*
현재 문자열의 순서를 적절히 바꿔서 팰린드롬을 만들면 된다.
순서를 적절히 바꾼다는 말은 기존 문자열을 다 뜯어 고쳐도 된다는 말이고
출력을 할때 사전순으로 가장 앞선 것을 출력해야 하므로
문자열을 입력 받고 카운팅 정렬을 하면된다.
단 팰린드롬 특성상 홀수 문자가 2개이상 존재하면 안된다.
*/

int main()
{
    scanf("%s", Str);
    //문자 카운트
    for(int i = 0; Str[i] != 0; i++)
    {
        alph[Str[i] - 'A']++;
    }
    int count = 0, idx;
    for(int i = 0; i < 26; i++)
    {
        //홀수 문자열 확인
        if(alph[i] % 2 == 1)
        {
            count++;
            idx = i;
        }
    }
    //2개이상 존재시 실패
    if(count > 1)
    {
        printf("I'm Sorry Hansoo");
        return 0;
    }
    //절반을 먼저 출력
    for(int i = 0; i < 26; i++)
    {
        int temp;
        temp = alph[i] / 2;
        for(int j = 0; j < temp; j++)
        {
            printf("%c", (char)i + 'A');
            alph[i]--;
        }
    }
    //홀수인 문자는 가운데에 출력
    if(count == 1)
    {
        printf("%c", (char)idx + 'A');
        alph[idx]--;
    }
    //나머지 역순으로 출력
    for(int i = 25; i >= 0; i--)
    {
        for(int j = 0; j < alph[i]; j++)
        {
            printf("%c", (char)i + 'A');
        }
    }
}