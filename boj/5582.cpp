#include <cstdio>
#include <iostream>
using namespace std;
char Str1[4005], Str2[4005];
int length1, length2, memo[4005][4005], result;

/*
O(A * B)로 완전탐색해서 가장 긴 부분 문자열을 찾을 수 있다.
단 한번 탐색 했던 곳은 메모이제이션을 해서 다음에 같은 곳을 또 탐색 할 때
바로 값을 반환 하게 해준다.
*/

int max(int a, int b)
{
    return a > b ? a : b;
}

int strlen(char *str)
{
    int len = 0;
    while(*str != 0)
    {
        len++;
        str++;
    }
    return len;
}

int func(int idx1, int idx2)
{
    //두 문자열중 하나라도 끝에 도달시 리턴
    if(idx1 == length1 || idx2 == length2)
    {
        return 0;
    }
    int &ret = memo[idx1][idx2];
    //이미 한번 탐색 했던 곳이면 리턴
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    //문자가 같을시 다음 재귀로 넘어감
    if(Str1[idx1] == Str2[idx2])
    {
        ret = max(ret, func(idx1 + 1, idx2 + 1) + 1);
    }
    //그게 아니라면 바로 리턴
    return ret;
}

int main()
{
    scanf("%s %s", Str1, Str2);
    for(int i = 0; i < 4004; i++)
    {
        for(int j = 0; j < 4004; j++)
        {
            memo[i][j] = -1;
        }
    }
    length1 = strlen(Str1);
    length2 = strlen(Str2);
    for(int i = 0; i < length1; i++)
    {
        for(int j = 0; j < length2; j++)
        {
            //해당 인덱스의 문자가 같으면 탐색
            if(Str1[i] == Str2[j])
            {
                result = max(result, func(i, j));
            }
        }
    }
    printf("%d", result);
}