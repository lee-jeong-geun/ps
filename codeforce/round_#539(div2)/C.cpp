#include <cstdio>
#include <iostream>
using namespace std;
int n, Sum[300005], memo[(1 << 20) + 5][3];
long long result;

/*
연속된 구간의 절반을 나눠서 앞 구간과 뒷 구간의 XOR값이 같아야 한다.
XOR 값이 같다는것은 두 구간을 XOR 연산 하면 0이 된다는 소리다.
따라서 XOR값을 누적으로 구한 후 해당 XOR값의 등장 횟수를 메모이제이션 하면 된다.
memo[XOR값][인덱스 % 2]에 횟수를 누적 시키면 된다.
홀수 짝수를 나눈 이유는 구간이 반드시 짝수개여야 하기 때문이다.
1번 인덱스와 4번 인덱스의 차이는 3개이기 때문에 홀수 짝수 구분 하였다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);
        Sum[i] = Sum[i - 1] ^ num;
    }
    memo[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        result += memo[Sum[i]][i % 2];
        memo[Sum[i]][i % 2]++;
    }
    printf("%lld", result);
}