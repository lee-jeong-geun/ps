#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int alph[30][5], idx[30], result;

/*
어떤 소와 어떤 소가 포함 관계가 아닌 걸쳐 있는 관계를 찾으면 된다.
*/

int main()
{
    for(int i = 0; i < 52; i++)
    {
        char word;
        scanf("%c", &word);
        alph[word - 'A'][idx[word - 'A']++] = i;
    }
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(alph[i][0] < alph[j][0] && alph[j][0] < alph[i][1] && alph[i][1] < alph[j][1])
            {
                result++;
            }
        }
    }
    printf("%d", result);
}