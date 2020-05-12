#include <bits/stdc++.h>
using namespace std;
vector<int> vec[15];
int K, arr[1030];

/*
조건에 맞는 트리를 중위 순회 하면 된다.
*/

void func(int depth, int left, int right)
{
    if(left == right)
        return;
    int mid;
    mid = (left + right) / 2;
    func(depth + 1, left, mid);
    vec[depth].push_back(arr[mid]);
    func(depth + 1, mid + 1, right);
}

int main()
{
    scanf("%d", &K);
    for(int i = 0; i < (1 << K) - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
    func(0, 0, (1 << K) - 1);
    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < vec[i].size(); j++)
        {
            printf("%d ", vec[i][j]);
        }
        printf("\n");
    }
}