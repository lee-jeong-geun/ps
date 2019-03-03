#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, Num[1005], chk[200005], result;

/*
모든 쌍의 합을 카운트 한 후 개수가 가장 많은 카운트를 출력하면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Num[i]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            //쌍의 개수 + 1
            chk[Num[i] + Num[j]]++;
            result = max(result, chk[Num[i] + Num[j]]);
        }
    }
    printf("%d", result);
}