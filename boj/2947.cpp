#include <cstdio>
#include <iostream>
using namespace std;
int stick[6];

/*
버블 정렬 한번 완료 할때마다 출력 해주면 된다.
*/

int main()
{
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &stick[i]);
    }
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5 - i - 1; j++)
        {
            if(stick[j] > stick[j + 1])
            {
                int temp;
                temp = stick[j];
                stick[j] = stick[j + 1];
                stick[j + 1] = temp;
                for(int k = 0; k < 5; k++)
                {
                    printf("%d ", stick[k]);
                }
                printf("\n");
            }
        }
    }
}