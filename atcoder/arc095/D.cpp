#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Num[100005], Max, Min = 987654321, result;

/*
모든 쌍중에서 comb(a, b)가 가장 큰 (a, b)쌍을 찾으면 된다.
이항계수 특성상 b가 같다면 a가 큰쪽이 무조건 크게 되어있다.
문제의 조건에는 쌍을 선택하는데 있어서 제약이 없으니까 a에 주어진 수들중 가장 큰 값을 넣으면 된다.
이제 b를 찾아야 하는데 b는 b와 a - b의 차가 가장 작은 쪽이 이항계수 값이 크다.
따라서 주어진 값들중 abs(b - (a - b))의 차가 가장 작은 값을 찾으면 된다.
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
        Max = max(Max, Num[i]);
    }
    for(int i = 0; i < N; i++)
    {
        if(Max == Num[i])
        {
            continue;
        }
        if(Min > abs(Num[i] - (Max - Num[i])))
        {
            Min = abs(Num[i] - (Max - Num[i]));
            result = Num[i];
        }
    }
    printf("%d %d", Max, result);
}