#include <cstdio>
#include <iostream>
using namespace std;
int n;
long long result;
char Str[5000005];

/*
단순 구현 문제
char형 숫자들을 int형 숫자들로 바꿔주면 된다.
단 int형 범위를 초과 할수 있기 때문에 결과값은 long long 형으로 받는다.
*/

//문자열을 숫자로 바꿔주는 함수
int atoi(char *str, int length)
{
    int hap = 0;
    for(int i = 0; i < length; i++)
    {
        hap *= 10;
        hap += (str[i] - '0');
    }
    return hap;
}

int main()
{
    int idx = 0;
    char word[10];
    scanf("%d %s", &n, Str);
    //이 소스는 for문 안에서 모든 문자들을 처리하기 때문에 aa444와 같이 
    //숫자가 문자열 마지막이면 처리를 못하기 때문에 알파벳 하나를 넣어줌
    Str[n] = 'a';
    Str[n + 1] = NULL;
    for(int i = 0; i <= n; i++)
    {
        if(Str[i] >= '0' && Str[i] <= '9')
        {
            word[idx++] = Str[i];
        }
        else
        {
            if(idx > 0)
            {
                word[idx] = NULL;
                result += atoi(word, idx);
                idx = 0;
            }
        }
    }
    printf("%lld", result);
}