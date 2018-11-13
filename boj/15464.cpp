#include <cstdio>
#include <iostream>
using namespace std;
int N, arr[105], id[105][5];

/*
세번 셔플하기 전으로 되돌리면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &id[i][0]);
    }
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            //되돌림
            id[j][i] = id[arr[j]][i - 1];
        }
    }
    for(int i = 1; i <= N; i++)
    {
        printf("%d\n", id[i][3]);
    }
}