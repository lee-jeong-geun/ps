#include <cstdio>
#include <iostream>
using namespace std;
int memo[55], n, result[50], resultidx;

int main()
{
    memo[1] = 1;
    for(int i = 2; i < 46; i++)
    {
        memo[i] = memo[i - 2] + memo[i - 1];
    }
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        resultidx = 0;
        scanf("%d", &n);
        for(int i = 45; i >= 0; i--)
        {
            if(n == 0)
            {
                break;
            }
            if(n >= memo[i])
            {
                n -= memo[i];
                result[resultidx++] = memo[i];
            }
        }
        for(int i = resultidx - 1; i >= 0; i--)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
}