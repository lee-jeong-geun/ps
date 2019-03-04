#include <cstdio>
#include <iostream>
using namespace std;
int N, K, Num[1005], result = 987654321;

/*
A[0]값의 시작지점은 1부터 1000까지 이므로
1부터 1000일때 뒤에 수들이 오름차순이 몇개가 완성되는지 확인하면 된다.
*/

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Num[i]);
    }
    for(int i = 1; i <= 1000; i++)
    {
        int count = 0;
        for(int j = 0; j < N; j++)
        {
            if(Num[j] != K * j + i)
            {
                count++;
            }
        }
        result = min(result, count);
    }
    printf("%d", result);
}