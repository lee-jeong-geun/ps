#include <bits/stdc++.h>
using namespace std;
int N, K, arr[300005], Sum[25];
long long result;

/*
i번째 등수에서 i + K까지 같은 길이의 이름이 몇 개 있는지 찾으면 된다.
길이는 최대 20글자이므로 0 ~ K - 1번째 까지 개수를 세서 20칸짜리 배열에 저장한 다음
스위핑 하면서 좋은 친구의 쌍을 찾으면 된다.
*/

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
    {
        char name[25];
        int length;
        scanf("%s", name);
        length = strlen(name);
        arr[i] = length;
    }
    for(int i = 0; i < K; i++)
    {
        Sum[arr[i]]++;
    }
    for(int i = 0; i < N; i++)
    {
        if(i + K < N)
            Sum[arr[i + K]]++;
        Sum[arr[i]]--;
        result += Sum[arr[i]];
    }
    printf("%lld", result);
}