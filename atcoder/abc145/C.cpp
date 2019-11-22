#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[15];
int N, parr[15], fact = 1;
double result;

/*
모든 순열을 구하고 그 순열 사이의 관계에서 좌표 거리를 다 더한 후 평균을 구하면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &arr[i].first, &arr[i].second);
        parr[i] = i;
        fact *= i + 1;
    }
    do
    {
        for(int i = 0; i < N - 1; i++)
        {
            double t1, t2;
            t1 = arr[parr[i]].first - arr[parr[i + 1]].first;
            t2 = arr[parr[i]].second - arr[parr[i + 1]].second;
            result += sqrt(t1 * t1 + t2 * t2);
        }
    }
    while(next_permutation(parr, parr + N));
    printf("%0.10lf", result / fact);
}