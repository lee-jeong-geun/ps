#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int Length, rFlag, chk[30];
char S[30], result[30];

/*
순열을 만들면 된다.
*/

void func(int depth)
{
    //현재 사전순에서 하나를 추가한것
    if(depth == Length)
    {
        for(int i = 0; i < 26; i++)
        {
            //한번도 쓰지 않은 경우
            if(chk[i] == 0)
            {
                rFlag = 1;
                result[depth] = i + 'a';
                result[depth + 1] = 0;
                break;
            }
        }
        return;
    }
    for(int i = S[depth] - 'a'; i < 26; i++)
    {
        if(chk[i] == 0 && rFlag == 0)
        {
            chk[i] = 1;
            result[depth] = i + 'a';
            //사전순으로 자기 자신
            if(i == S[depth] - 'a')
            {
                func(depth + 1);
                chk[i] = 0;
                continue;
            }
            //다음 사전순
            result[depth + 1] = 0;
            rFlag = 1;
        }
    }
}

int main()
{
    scanf("%s", S);
    Length = strlen(S);
    func(0);
    if(rFlag == 0)
    {
        printf("-1");
        return 0;
    }
    printf("%s", result);
}