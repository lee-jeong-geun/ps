#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, result, Bit[30];
char Str[200005], intToWord[10] = "0RG0B";

/*
i번째 문자와 i + 1번째 문자가 같을 경우 i + 1번째 문자를 교체 해주면 된다.
이때 i + 2번째 문자와도 같으면 안되기 때문에 i + 2번째 문자를 고려해서 교체 해주면 된다.
*/

int main()
{
    Bit['R' - 'A'] = 1;
    Bit['G' - 'A'] = 2;
    Bit['B' - 'A'] = 4;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf(" %c", &Str[i]);
    }
    Str[n] = 'R';
    for(int i = 0; i < n - 1; i++)
    {
        if(Str[i] == Str[i + 1])
        {
            result++;
            int temp;
            //비트연산을 통해 조건문 줄임
            temp = Bit[Str[i] - 'A'] | Bit[Str[i + 2] - 'A'];
            //i, i + 1, i + 2가 동일한 경우
            if(Str[i + 1] == Str[i + 2])
            {
                Str[i + 1] = 'R';
                if(Str[i] == 'R')
                {
                    Str[i + 1] = 'G';
                }
                else if(Str[i] == 'G')
                {
                    Str[i + 1] = 'B';
                }
                continue;
            }
            Str[i + 1] = intToWord[7 - temp];
        }
    }
    printf("%d\n", result);
    for(int i = 0; i < n; i++)
    {
        printf("%c", Str[i]);
    }
}