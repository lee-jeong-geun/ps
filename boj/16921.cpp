#include <cstdio>
#include <iostream>
using namespace std;
int N, Num[25] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};
long long result = 292;

/*
N이 12부터 49씩 증가하는 규칙을 가지고 있다.
따라서 11까지 구해놓고 12부터는 49씩 더하면 된다.
*/

int main()
{
    scanf("%d", &N);
    if(N < 12)
    {
        result = Num[N];
    }
    printf("%lld", result + (long long)max(0, N - 11) * 49);
}