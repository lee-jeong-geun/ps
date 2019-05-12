#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[100005], Left[100005], Right[100005], result;

/*
모든 수들의  최대공약수를 구하고 하나씩 제외 할 때 최대공약수가 어떻게 되는지 구하면 된다.
이때 제외 할 때는 제외한 수의 왼쪽수들의 최대공약수 오른쪽 수들의 최대공약수를 구하면 된다.
따라서 left, right배열을 만든 후 left배열에는 해당 인덱스의 왼쪽 최대공약수를 저장하고
right배열에는 해당 인덱스의 오른쪽 최대공약수를 구하면 된다.
*/

int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    Left[0] = arr[0];
    for(int i = 1; i < N; i++)
    {
        Left[i] = gcd(Left[i - 1], arr[i]);
    }
    Right[N - 1] = arr[N - 1];
    for(int i = N - 2; i >= 0; i--)
    {
        Right[i] = gcd(Right[i + 1], arr[i]);
    }
    result = max(Left[N - 2], Right[1]);
    for(int i = 1; i < N - 1; i++)
    {
        result = max(result, gcd(Left[i - 1], Right[i + 1]));
    }
    printf("%d", result);
}