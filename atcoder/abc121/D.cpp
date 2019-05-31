#include <cstdio>
#include <iostream>
using namespace std;
long long A, B, result, temp;

/*
O(N)으로는 해결 할 수 없다.
규칙을 잘 보면 (0, 1), (2, 3), (4, 5)와 같이 0을 기준으로 짝홀, 짝홀 되어있는 수들의
XOR은 1이다. 이 규칙을 이용해서 A ~ B까지의 XOR은 저 쌍들을 전부 XOR한 후 남아있는 값과
쌍을 못이룬 수들의 XOR을 구하면 된다. 경우의 수는 총 4가지가 나오게된다.
A가 짝이고 B가 홀인경우 처럼 짝홀, 짝짝, 홀홀, 홀짝이 나오게 되는데 각각의 경우마다 
쌍들을 XOR하고 남아있는 수들과 XOR하면 된다.
*/

int main()
{
    scanf("%lld %lld", &A, &B);
    //가장 기본적인 짝홀
    result = (B - A + 1) / 2 % 2;
    //쌍들을 XOR한 값  0 or 1
    temp = (B - A) / 2 % 2;
    //홀짝
    if(A % 2 == 1 && B % 2 == 0)
    {
        result = A ^ B ^ temp;
    }
    //홀홀
    else if(A % 2 == 1)
    {
        result = A ^ temp;
    }
    //짝짝
    else if(B % 2 == 0)
    {
        result = B ^ temp;
    }
    printf("%lld", result);
}