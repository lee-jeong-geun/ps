#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int chk[105], length, result;
char S[15];

/*
주어진 조건에 맞게 최대 연속 길이가 몇인지 찾으면 된다.
*/

int main()
{
    chk['A'] = 1;
    chk['C'] = 1;
    chk['G'] = 1;
    chk['T'] = 1;
    scanf("%s", S);
    length = strlen(S);
    for(int i = 0; i < length; i++)
    {
        int count = 0;
        for(int j = i; j < length; j++)
        {
            //주어진 조건이 아니라면 종료
            if(chk[S[j]] != 1)
            {
                break;
            }
            count++;
            result = max(result, count);
        }
    }
    printf("%d", result);
}