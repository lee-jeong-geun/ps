#include <cstdio>
#include <iostream>
using namespace std;
int Num[5], result = 1;

/*
올바른 괄호의 상태는 1번 4번 괄호의 개수가 반드시 일치하고
3번 괄호가 존재시 1번 4번 괄호도 존재해야 한다.
*/

int main()
{
    for(int i = 0; i < 4; i++)
    {
        scanf("%d", &Num[i]);
    }
    //3번 괄호가 존재시
    if(Num[2] != 0)
    {
        //1번 4번 괄호중 하나라도 없는 경우
        if(Num[0] < 1 || Num[3] < 1)
        {
            result = 0;
        }
    }
    //1번 4번 괄호 개수 다른 경우
    if(Num[0] != Num[3])
    {
        result = 0;
    }
    printf("%d", result);
}