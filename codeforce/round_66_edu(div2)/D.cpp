#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
long long Sum[300005], arr[300005], result;

/*
k를 3으로 잡고 a배열의 원소들을 문제의 조건에 맞게 더하였을때 모습은 대략
a1 + a2 + a3 + ... + an
          a3 + ... + an
               ... + an
이런 모습이 나오게 된다. 첫번째 구간은 한번만 더하고 두번째 구간은 두번 더하고
.... k번째 구간은 k번 더하므로 저런 모습이 나오게 된다.
k개의 구간을 나눴을때 구간의 합이 큰 부분들을 최대한 많이 더해야 한다.
따라서 부분합을 이용하여 a1 ~ an, a2 ~ an, a3 ~ an, .... 이런식으로
부분합들을 따로 배열에 저장 후 그 배열을 정렬 하여 구간의 값들이 큰 순서로 많이 더해주면 된다.
*/

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);
        Sum[i] = Sum[i - 1] + num;
    }
    for(int i = 1; i <= n; i++)
    {
        //ai ~ an까지의 합
        arr[i] = Sum[n] - Sum[i - 1];
    }
    //a1 ~ an은 반드시 한번 더하게 되어있음
    result = arr[1];
    sort(arr + 2, arr + n + 1);
    for(int i = n, count = 1; i > 1; i--, count++)
    {
        //k개 골랐을 경우 종료
        if(count == k)
            break;
        result += arr[i];
    }
    printf("%lld", result);
}