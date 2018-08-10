#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int segTree[400005][2], N, Q, H[100005], arr[5];

int init(int left, int right, int node, int flag)
{
    if(left == right)
    {
        return segTree[node][flag] = H[left];
    }
    int mid, temp;
    mid = (left + right) / 2;
    if(flag == 0)
    {
        temp = min(init(left, mid, node * 2, flag), init(mid + 1, right, node * 2 + 1, flag));
    }
    else
    {
        temp = max(init(left, mid, node * 2, flag), init(mid + 1, right, node * 2 + 1, flag));
    }
    return segTree[node][flag] = temp;
}

int query(int start, int end, int left, int right, int node, int flag)
{
    if(end < left || start > right)
    {
        return arr[flag];
    }
    if(start <= left && right <= end)
    {
        return segTree[node][flag];
    }
    int mid;
    mid = (left + right) / 2;
    if(flag == 0)
    {
        return min(query(start, end, left, mid, node * 2, flag), query(start, end, mid + 1, right, node * 2 + 1, flag));
    }
    return max(query(start, end, left, mid, node * 2, flag), query(start, end, mid + 1, right, node * 2 + 1, flag));
}

int main()
{
    arr[0] = 987654321;
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        scanf("%d %d", &N, &Q);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &H[i]);
        }
        init(0, N - 1, 1, 0);
        init(0, N - 1, 1, 1);
        for(int i = 0; i < Q; i++)
        {
            int a, b, t1, t2;
            scanf("%d %d", &a, &b);
            printf("%d\n", query(a, b, 0, N - 1, 1, 1) - query(a, b, 0, N - 1, 1, 0));
        }
    }
}