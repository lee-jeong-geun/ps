#include <bits/stdc++.h>
using namespace std;
int N, result;
char word[105];

/*
주어진 문자열의 절반이 나머지 절반과 같은지 확인하면 된다.
*/

int main()
{
    scanf("%d %s", &N, word);
    for(int i = 0; i < N / 2; i++)
    {
        if(word[i] != word[N / 2 + i])
            result = 1;
    }
    if(result == 1 || N % 2 == 1)
        printf("No");
    else
        printf("Yes");
}