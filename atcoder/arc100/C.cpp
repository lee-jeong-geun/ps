#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Num[200005];
long long result;

/*
절대값이라서 수의 크기를 최대한 줄여야 한다.
이때 b의 값을 너무 크게 잡으면 0에서 먼쪽은 작아지고 0에서 가까운 쪽은 커진다.
따라서 적당한 값의 b를 찾아야 하는데 Ai - i의 값들을 계산후 그 수들을 정렬 시키고
중앙에 있는 값을 b로 채택시 수들을 고르게 만들어 준다.
*/

int abs(int num)
{
    return num > 0 ? num : -num;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Num[i]);
        Num[i] -= i;
    }
    sort(Num, Num + N);
    for(int i = 0; i < N; i++)
    {
        result += abs(Num[i] - Num[N / 2]);
    }
    printf("%lld", result);
}