#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char S[45];
int memo[45], Slength;

/*
1부터 34까지이므로 카드 하나당 최대 두자리수밖에 되지 않는다.
탐색을 할 때 한자리 or 두자리씩 채워 나가면 된다.
채워 나갈때 0예외 처리를 해줘야 한다.
최대 길이가 40이므로 완전탐색 한다면 시간초과 하게된다.
*/

int func(int depth)
{
    //기저 사례
    if(depth == Slength)
    {
        return 1;
    }
    int &ret = memo[depth];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    //0예외 처리
    if(S[depth] != '0')
    {
        ret += func(depth + 1);
        //두자리 채울때 34이하인지 확인
        if(depth + 2 <= Slength && (S[depth] - '0') * 10 + (S[depth + 1] - '0') <= 34)
        {
            ret += func(depth + 2);
        }
    }
    return ret;
}

int main()
{
    memset(memo, -1, sizeof memo);
    scanf("%s", S);
    Slength = strlen(S);
    printf("%d", func(0));
}