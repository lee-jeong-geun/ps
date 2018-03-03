#include <cstdio>
#include <iostream>
using namespace std;
int n;

/*
n을 0번째 비트부터 &연산을 해서 0이 아닐 경우 출력 하면 된다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        scanf("%d", &n);
        for(int i = 0; i < 25; i++)
        {
            if((n & (1 << i)) != 0)
            {
                printf("%d ", i);
            }
        }
        printf("\n");
    }    
}