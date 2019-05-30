#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int money;
    int count;
}Data;
Data arr[100005];
int N, M;
long long result;

/*
최소의 돈으로 M개의 음료를 사기 위해서는 각각의 가게를 음료가격 순으로 정렬 후 싼가격부터 차근차근 사면 된다.
*/

bool comp(Data &t, Data &u)
{
    return t.money < u.money;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &arr[i].money, &arr[i].count);
    }
    sort(arr, arr + N, comp);
    for(int i = 0; i < N; i++)
    {
        //현재 사야되는 음료와 가게에 있는 음료중 작은것 선택
        result += (long long)arr[i].money * min(M, arr[i].count);
        M -= min(M, arr[i].count);
    }
    printf("%lld", result);
}