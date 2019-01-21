#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, k, result[200005], resultIdx, Count;

/*
어떤 수 n을 k개의 2의 거듭제곱들의 덧셈으로 나타 내야 한다.
n을 1로만 나타냈을때 가장 많은 수로 나타 낼수있다. 즉 최대로 나타 낼수있는
개수는 n이다. k가 n보다 크거나 n을 비트로 나타냈을때 1의 개수보다 작다면
절대 k개로 n을 표현 할 수 없다.
n을 k개로 표현 하기 위해서는 비트로 나타냈을때 최상위 비트부터 쪼개면서 나타 낸다면 k개가 되었을때
하위 비트들을 쪼갤 필요없이 그냥 출력하기만 하면 된다.
이때 쪼개는 방법은 재귀함수로 해당 비트를 쪼갰을 때 하위비트 2개가 생기고 이 2개를 이용 했을때도
k개보다 모자란다면 더 쪼개는 방식으로 하면 된다.
*/

void func(int num, int count)
{
    //결과 저장
    if(Count + count == k || num == 1 && Count + count < k)
    {
        result[resultIdx++] = num;
        return;
    }
    //k개보다 많아진다면 더 쪼갤 필요없음
    if(num == 1 || Count + count > k)
    {
        return;
    }
    //해당 비트를 쪼개면 2개의 하위 비트가 생김
    if(Count + count + 1 <= k)
    {
        func(num / 2, count + 1);
        func(num / 2, count + 1);
        Count++;
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < 31; i++)
    {
        if((n & (1 << i)) != 0)
        {
            Count++;
        }
    }
    //안되는 조건들
    if(n < k || Count > k)
    {
        printf("NO");
        return 0;
    }
    //최상위 비트부터 접근
    for(int i = 31; i >= 0; i--)
    {
        int temp;
        //해당 비트가 있는 경우
        if((n & (1 << i)) != 0)
        {
            Count--;
            temp = n & (1 << i);
            func(temp, 1);
            Count++;
        }
    }
    printf("YES\n");
    for(int i = 0; i < resultIdx; i++)
    {
        printf("%d ", result[i]);
    }
}