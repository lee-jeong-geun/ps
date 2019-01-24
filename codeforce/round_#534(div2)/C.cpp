#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char Str[1005];

/*
4x4 배열에 2x1, 1x2 블록을 안겹치게 계속 채우는 것이다. 이때 한 행이든 한 열이든
다 채워져있으면 지우는데 빈칸이 있는곳 마다 블록을 둔다면 블록을 못두는 상황이 발생하게 된다.
쉽게 2x1블록은 1~2행에 두고 1x2블록은 3~4행에 두면 된다.
*/

int main()
{
    int length, zero = 0, one = 0;
    scanf("%s", Str);
    length = strlen(Str);
    for(int i = 0; i < length; i++)
    {
        if(Str[i] == '0')
        {
            printf("%d %d\n", 1, zero + 1);
            zero = (zero + 1) % 4;
        }
        else
        {
            printf("%d %d\n", 3, one + 1);
            one = (one + 2) % 4;
        }
    }
}