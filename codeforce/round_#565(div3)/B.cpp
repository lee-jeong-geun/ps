#include <bits/stdc++.h>
using namespace std;
int t, n, Count[5];

/*
3의 배수로 만드는 것은 모든 수들을 3으로 나눈 나머지로 표현해서 1 + 2, 1 + 1 + 1, 2 + 2 + 2의 방법으로
만들 수 있다. 1 + 2는 min(1개수, 2개수)로 할 수 있고 1 + 1 + 1은 1의 개수에서 min(1개수, 2개수) 뺀 값을
3으로 나눈 값이다. 2 + 2 + 2도 1 + 1 + 1과 같은 방법이다.
*/

int main()
{
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++)
    {
        memset(Count, 0, sizeof Count);
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            int num;
            scanf("%d", &num);
            Count[num % 3]++;
        }
        int temp;
        temp = min(Count[1], Count[2]);
        printf("%d\n", Count[0] + temp + (Count[1] - temp) / 3 + (Count[2] - temp) / 3);
    }
}