#include <cstdio>
#include <iostream>
using namespace std;
int N, M, Number[100005], segtree[400005];

/*
구간의 합은 부분합으로 O(1)만에 구할 수 있지만 구간의 값이 변동 되면 구간의 합을 다시 구해야한다.
다시 구하는데 O(N)의 시간이 걸린다. 이 문제는 쿼리가 20만개가 들어오므로 최대 10만 * 20만 이라는 
연산이 걸린다. 세그먼트 트리는 O(logN)만에 구간의 값을 수정 할 수 있고 구간의 합을 구할 수 있다.
*/

//세그먼트 트리 초기화
int init(int left, int right, int node)
{
    //리프 노드일 경우
    if(left == right)
    {
        return segtree[node] = Number[left];
    }
    int mid;
    mid = (left + right) / 2;
    return segtree[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
}

//구간의 값 변화
int Sum(int X, int Y, int left, int right, int node)
{
    //구하고 싶은 구간이 아닐 경우
    if(X < left || X > right)
    {
        return segtree[node];
    }
    if(left == right)
    {
        return segtree[node] += Y;
    }
    int mid;
    mid = (left + right) / 2;
    return segtree[node] = Sum(X, Y, left, mid, node * 2) + Sum(X, Y, mid + 1, right, node * 2 + 1);
}

//구간의 합 구함
int query(int L, int R, int left, int right, int node)
{
    //구하고 싶은 구간에 속할 경우
    if(L <= left && right <= R)
    {
        return segtree[node];
    }
    //구간에 안속할 경우
    if(R < left || L > right)
    {
        return 0;
    }
    int mid;
    mid = (left + right) / 2;
    return query(L, R, left, mid, node * 2) + query(L, R, mid + 1, right, node * 2 + 1);
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        scanf("%d %d", &N, &M);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &Number[i]);
        }
        init(0, N - 1, 1);
        printf("#%d ", testcase);
        for(int i = 0; i < M; i++)
        {
            int C, X, Y;
            scanf("%d %d %d", &C, &X, &Y);
            if(C == 1)
            {
                Sum(X - 1, Y, 0, N - 1, 1);
            }
            else
            {
                printf("%d ", query(X - 1, Y - 1, 0, N - 1, 1));
            }
        }
        printf("\n");
    }
}