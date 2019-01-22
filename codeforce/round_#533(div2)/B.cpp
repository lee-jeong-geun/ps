#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, k, chk[30], result;
char Str[200005];

/*
문자열 전체에서 연속된 문자가 몇개 있는지 완전탐색을 이용하면 된다.
*/

int main()
{
    int length;
    scanf("%d %d %s", &n, &k, Str);
    length = strlen(Str);
    Str[length] = 'A';
    length++;
    Str[length] = 0;
    for(int i = 0; i < length - 1; i++)
    {
        int count = 0;
        char word;
        word = Str[i];
        for(int j = i; j < length; j++)
        {
            //연속된 문자 카운트
            if(word == Str[j])
            {
                count++;
            }
            //아니라면 다음 문자로 이동
            else
            {
                i = j - 1;
                break;
            }
            //카운트가 k라면 개수 저장
            if(count == k)
            {
                chk[word - 'a']++;
                i = j;
                break;
            }
        }
    }
    for(int i = 0; i < 27; i++)
    {
        result = max(result, chk[i]);
    }
    printf("%d", result);
}