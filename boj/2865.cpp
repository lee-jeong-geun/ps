#include <bits/stdc++.h>
using namespace std;
int N, M, K;
double arr[105], result;

/*
각 사람의 능력을 최대로 갱신해주고 정렬 후 K개의 값을 더하면 된다.
*/

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int idx;
            double num;
            scanf("%d %lf", &idx, &num);
            arr[idx - 1] = max(arr[idx - 1], num);
        }
    }
    sort(arr, arr + N, greater<double>());
    for(int i = 0; i < K; i++)
    {
        result += arr[i];
    }
    printf("%0.1lf", result);
}