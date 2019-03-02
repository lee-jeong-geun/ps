#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int chk[15];
char word[15][15], route[15][15], result[15] = "aaaaaaaaa";

/*
완전탐색을 이용하여 가로줄을 다 채운후 세로줄을 비교하면 된다.
*/

void func(int depth)
{
    if(depth == 6)
    {
        char temp[15];
        //결과 배열이랑 비교하기 위해 임시배열에 저장
        for(int i = 0; i < 9; i++)
        {
            temp[i] = route[i / 3][i % 3];
        }
        temp[9] = 0;
        //사전순으로 더 앞인 경우 갱신
        if(strcmp(temp, result) < 0)
        {
            strcpy(result, temp);
        }
        return;
    }
    for(int i = 0; i < 6; i++)
    {
        if(chk[i] == 1)
        {
            continue;
        }
        //가로줄 먼저 채우기
        if(depth < 3)
        {
            chk[i] = 1;
            strcpy(route[depth], word[i]);
            func(depth + 1);
            chk[i] = 0;
        }
        //세로줄은 비교만
        else
        {
            int count = 0;
            for(int j = 0; j < 3; j++)
            {
                if(route[j][depth % 3] == word[i][j])
                {
                    count++;
                }
            }
            if(count == 3)
            {
                chk[i] = 1;
                func(depth + 1);
                chk[i] = 0;
            }
        }
    }
}

int main()
{
    for(int i = 0; i < 6; i++)
    {
        scanf("%s", word[i]);
    }
    func(0);
    //퍼즐 완성 못한 경우
    if(result[0] == 'a')
    {
        printf("0");
        return 0;
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%c", result[i * 3 + j]);
        }
        printf("\n");
    }
}