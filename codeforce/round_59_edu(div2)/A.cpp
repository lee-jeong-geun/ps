#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int q, Num[305];

/*
주어진 수를 최소 2개의 구간으로 나눠야 하는데 오름차순이 되도록 나눠야 한다.
간단하게 받은 수의 첫번째와 나머지 숫자로 구간을 나눈다. 이때 첫번째 수가 나머지보다 크거나 같으면
NO다.
*/

int main()
{
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        int n;
        scanf("%d", &n);
        for(int j = 0; j < n; j++)
        {
            scanf("%1d", &Num[j]);
        }
        //받은 수가 2개이고 첫번째가 두번째보다 크거나 같은 경우
        if(n == 2 && Num[0] >= Num[1])
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n%d\n", 2);
        printf("%d ", Num[0]);
        for(int j = 1; j < n; j++)
        {
            printf("%d", Num[j]);
        }
        printf("\n");
    }
}