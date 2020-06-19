#include <bits/stdc++.h>
using namespace std;
vector<int> vec, vec2;
int T, N, M, arrA[1005], arrB[1005];
long long result;

/*
배열의 길이가 1000이므로 부 배열의 총 개수는 1000 * 1000밖에 되지 않는다.
전체를 구하고 정렬을 한다. 투 포인터를 이용해 하나는 A 배열의 0번 인덱스에 두고
다른 하나는 B 배열의 M-1 번 인덱스에 둔다. 정렬된 상태이기 때문에 A[l] + B[r]가 T보다 작으면
당연하게 l을 증가시켜야 하고 T보다 크면 r을 감소시키면 된다. T와 같은 경우에는
A 배열의 경우에는 같은 값이 안 나올 때까지 계속 증가시키고 B 배열은 같은 값이 안 나올 때까지 감소시킨다.
*/

int main()
{
    scanf("%d %d", &T, &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arrA[i]);
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &arrB[i]);
    }
    for(int i = 0; i < N; i++)
    {
        int Sum = 0;
        for(int j = i; j < N; j++)
        {
            Sum += arrA[j];
            vec.push_back(Sum);
        }
    }
    for(int i = 0; i < M; i++)
    {
        int Sum = 0;
        for(int j = i; j < M; j++)
        {
            Sum += arrB[j];
            vec2.push_back(Sum);
        }
    }
    sort(vec.begin(), vec.end());
    sort(vec2.begin(), vec2.end());
    int l, r;
    l = 0;
    r = vec2.size() - 1;
    while(l < vec.size() && r >= 0)
    {
        if(vec[l] + vec2[r] < T)
            l++;
        else if(vec[l] + vec2[r] > T)
            r--;
        else
        {
            long long l2, r2;
            l2 = l + 1;
            r2 = r - 1;
            while(vec[l2] == vec[l2 - 1] && l2 < vec.size())
            {
                l2++;
            }
            while(vec2[r2] == vec2[r2 + 1] && r2 >= 0)
            {
                r2--;
            }
            result += (l2 - l) * (r - r2);
            l = l2;
            r = r2;
        }
    }
    printf("%lld", result);
}