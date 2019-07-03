#include <bits/stdc++.h>
using namespace std;
char a[1000005], b[1000005];
int Count, Sum[1000005], aLength, bLength, result;

/*
규칙을 잘 보면 a의 서브 스트링에서의 1의 개수와 b의 1의 개수를 2로 나눴을 때의 나머지가 동일해야 한다.
즉 b의 1의 개수가 홀수면 서브 스트링은 1의 개수가 홀수여야 하고 짝수면 짝수여야 한다.
따라서 b에서의 1의 개수를 구하고 a에서의 1의 개수는 누적합을 이용하여 빠르게 찾아 주면 된다.
*/

int main()
{
    scanf("%s %s", a, b);
    aLength = strlen(a);
    bLength = strlen(b);
    for(int i = 0; i < bLength; i++)
    {
        if(b[i] == '1')
            Count++;
    }
    for(int i = 0; i < aLength; i++)
    {
        Sum[i + 1] = Sum[i] + a[i] - '0';
    }
    for(int i = bLength; i <= aLength; i++)
    {
        if((Sum[i] - Sum[i - bLength]) % 2 == Count % 2)
            result++;
    }
    printf("%d", result);
}