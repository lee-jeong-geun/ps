#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int pad[30] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
int N, result;
char S[1005], word[1000005];

/*
각각의 문자들을 키패드에 매칭시켜줘서 일치하는지 확인하면 된다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        int Slength;
        result = 0;
        scanf("%s %d", S, &N);
        Slength = strlen(S);
        for(int i = 0; i < N; i++)
        {
            int length, flag = 1;
            scanf("%s", word);
            length = strlen(word);
            //길이다르면 대응x
            if(Slength != length)
            {
                continue;
            }
            for(int j = 0; j < length; j++)
            {
                if(S[j] - 48 != pad[word[j] - 'a'])
                {
                    flag = 0;
                    break;
                }
            }
            result += flag;
        }
        printf("#%d %d\n", testcase, result);
    }
}