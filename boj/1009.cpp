#include <bits/stdc++.h>
using namespace std;
int a, b, T, result;

/*
a ^ b 형식이고 컴퓨터는 1 ~ 10까지 총 10대이므로 10보다 큰 수는 볼 필요가 없다.
그리고 a ^ b는 1의 자리가 네 번을 기점으로 사이클을 돈다.
따라서 a를 b를 4로 나눈 나머지만큼 곱하고 1의 자리가 몇인지 확인하면 된다.
*/

int main()
{
    scanf("%d", &T);
    for(int tc = 0; tc < T; tc++)
    {
        scanf("%d %d", &a, &b);
        result = 1;
        a %= 10;
        b = (b + 3) % 4 + 1;
        for(int i = 0; i < b; i++)
        {
            result = result * a % 10;
        }
        if(result == 0)
            result = 10;
        printf("%d\n", result);
    }
}