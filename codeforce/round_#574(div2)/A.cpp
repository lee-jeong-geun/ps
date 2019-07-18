#include <bits/stdc++.h>
using namespace std;
int n, k, Count[1005], result, rCount;

/*
각각의 수들의 개수를 배열에 저장 후 짝수 개수, 홀수 개수 순으로 꺼내 주면 된다.
짝수 홀수 순으로 꺼내는 이유는 홀수를 먼저 꺼낼 경우 짝수를 먼저 꺼내는 것 보다 1개가 손실되기 때문에
짝수 개수들을 먼저 꺼내는 것이다. 예를 들어 1 1 1 1 3 3 3 2 2 2 일 때 홀수 개수들을 먼저 꺼내면
8개를 꺼낼 수 있는데 짝수 개수들을 먼저 꺼내면 9개를 꺼낼 수 있게 된다.
*/

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        Count[num]++;
    }
    //세트 개수
    rCount = (n + 1) / 2;
    int Min;
    for(int i = 1; i <= k; i++)
    {
        //2이상이라면 개수를 짝수로 꺼낼 수 있음
        if(Count[i] >= 2)
        {
            Min = min(Count[i] / 2 * 2, rCount * 2);
            result += Min;
            Count[i] -= Min;
            rCount -= Min / 2;
        }
    }
    for(int i = 1; i <= k; i++)
    {
        if(Count[i] == 1 && rCount > 0)
        {
            result++;
            rCount--;
        }
    }
    printf("%d", result);
}