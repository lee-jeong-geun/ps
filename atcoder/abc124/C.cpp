#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int length, result, flag;
char S[100005], change[5] = "01";

/*
01010101이거나 10101010의 형태로 나타나기 때문에
두 형태로 바꿨을때 바꿔야 하는 개수의 최소를 찾으면 된다.
*/

int main()
{
    scanf("%s", S);
    length = strlen(S);
    int count = 0;
    //01010101
    for(int i = 0; i < length; i++)
    {
        if(S[i] != change[flag])
        {
            count++;
        }
        flag = !flag;
    }
    result = count;
    flag = 1;
    count = 0;
    //10101010
    for(int i = 0; i < length; i++)
    {
        if(S[i] != change[flag])
        {
            count++;
        }
        flag = !flag;
    }
    printf("%d", min(result, count));
}