#include <bits/stdc++.h>
using namespace std;
int N, arr[5005], result, chk[400005];

/*
a + b + c = arr[i]가 몇 개인지 찾으면 된다.
(a, b, c)의 쌍들을 전부 찾기에는 대략 5000^3의 경우의 수가 나오기 때문에 (a, b)의 모든 쌍만 구해놓고
a + b = arr[i] - c를 이용하면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        for(int j = 0; j < i; j++)
        {
            if(chk[arr[i] - arr[j] + 200000] == 1)
            {
                result++;
                break;
            }
        }
        for(int j = 0; j <= i; j++)
        {
            chk[arr[i] + arr[j] + 200000] = 1;
        }
    }
    printf("%d", result);
}