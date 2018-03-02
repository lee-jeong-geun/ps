#include <cstdio>
#include <iostream>
using namespace std;
char Str[5005];
int alph[30], Max;

/*
모든 문자를 입력 받으면서 카운트 하면 된다.
*/

int main()
{
    while(gets(Str) != 0)
    {
        for(int i = 0; Str[i] != 0; i++)
        {
            //공백은 제외
            if(Str[i] == ' ')
            {
                continue;
            }
            //문자 카운트
            alph[Str[i] - 'a']++;
            //최대값 갱신
            if(Max < alph[Str[i] - 'a'])
            {
                Max = alph[Str[i] - 'a'];
            }
        }
    }
    //여러개면 모두 출력 해야함
    for(int i = 0; i < 26; i++)
    {
        if(Max == alph[i])
        {
            printf("%c", (char)i + 'a');
        }
    }
}