#include <cstdio>
#include <iostream>
using namespace std;
int N, arr[100005], Sum[100005];

/*
부분합을 이용하여 모든 요소의 합을 저장후 i번째 인덱스를 지운다는것은 i번째 인덱스의 합이 포함된 부분을
지우면 된다는 의미 이므로 Sum[N + 1] - Sum[i + 1] 해준후 i - 1과 i + 1을 이어준 값을 더해주면 된다.
*/

int abs(int num)
{
    return num > 0 ? num : -num;
}

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
        Sum[i] = Sum[i - 1] + abs(arr[i] - arr[i - 1]);
    }
    Sum[N + 1] = Sum[N] + abs(arr[N]);
    for(int i = 1; i <= N; i++)
    {
        printf("%d\n", Sum[N + 1] - Sum[i + 1] + Sum[i - 1] + abs(arr[i - 1] - arr[i + 1]));
    }
}