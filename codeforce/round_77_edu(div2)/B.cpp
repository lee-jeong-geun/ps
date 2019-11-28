#include <bits/stdc++.h>
using namespace std;
int a, b, result;

/*
주어진 연산 a를 1깎고 b를 2깎거나 a를 2깎고 b를 1깎아서 a, b둘다 0으로 만들어야 한다.
둘다 0으로 만들기 위해서는 a + b가 3의 배수여야 한다. 그 이유는 2가지 연산 모두
한번 실행할 때마다 a와 b에 대해서 총 3을 깎기 때문에 a + b가 3의 배수가 아니라면
절대 0, 0으로 만들수 없다.
a + b가 3의 배수일 때 a, b둘중 작은 수에 대해서 계속 1씩 깎고 큰수에 대해서
계속 2씩 깎았을때 작은수가 0이되고 큰수가 0이 안되는 경우 또한 0, 0으로 만들 수 없다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        result = 0;
        scanf("%d %d", &a, &b);
        if((a + b) % 3 == 0 && min(a, b) * 2 >= max(a, b))
            result = 1;
        if(result == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}