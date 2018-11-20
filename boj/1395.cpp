#include <cstdio>
#include <iostream>
using namespace std;
int N, M, segTree[400005], lazyTree[400005];

/*
구간 S ~ T를 한번에 반전 시켜야 한다.
일일이 구간에 속해있는 값들을 하나씩 반전 시킨다면 각 쿼리마다 최대 N개를 반전 시켜야 하므로
O(M * N)의 시간 복잡도가 되므로 시간 초과가 나게 된다.
구간을 세그먼트 트리로 관리하게 될 경우 해당 구간을 업데이트 할 경우 log N이 걸리지만
그 구간에 속해있는 값들을 전부 변경 해야하므로 lazy propagation을 이용해서 구간을 한번에 업데이트 해야 한다.
lazy배열에 해당 구간이 몇번 토글 되었는지를 저장 하면 된다. 어차피 토글은 10번을 하든 2번을 하든 같으므로 1, 0을 이용해서
해당 구간의 토글 상태를 저장하면 된다. 나중에 그 구간에 접근하면 lazy배열을 확인 후 토글을 해야되는 상태라면 그 구간을 토글 시켜 주면 된다.
세그먼트 트리에 해당 구간의 켜진 스위치 개수를 저장 해서 토글시 구간의 스위치 개수 - 켜진 스위치 개수를 하면 토글된 개수를 얻을 수 있다.
*/

//lazy함수
void update_lazy(int left, int right, int node)
{
    //토글이 안된 경우
    if(lazyTree[node] == 0)
    {
        return;
    }
    //토글 시킨 개수 == 구간의 스위치 개수 - 켜진 스위치 개수
    segTree[node] = right - left + 1 - segTree[node];
    //리프 노드가 아닐 경우 자식에게 토글 상태를 물려줌
    if(left != right)
    {
        lazyTree[node * 2] ^= 1;
        lazyTree[node * 2 + 1] ^= 1;
    }
    lazyTree[node] = 0;
}

void update(int start, int end, int left, int right, int node)
{
    //해당 구간 lazy배열 확인
    update_lazy(left, right, node);
    //속해 있는 구간이 아닐 경우
    if(start > right || end < left)
    {
        return;
    }
    //속해 있는 구간인 경우
    if(start <= left && right <= end)
    {
        //토글 시킴
        segTree[node] = right - left + 1 - segTree[node];
        //리프 노드가 아닐 경우
        if(left != right)
        {
            lazyTree[node * 2] ^= 1;
            lazyTree[node * 2 + 1] ^= 1;
        }
        return;
    }
    int mid;
    mid = (left + right) / 2;
    update(start, end, left, mid, node * 2);
    update(start, end, mid + 1, right, node * 2 + 1);
    //왼쪽 자식 오른쪽 자식 켜진 스위치 개수 합
    segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

int query(int start, int end, int left, int right, int node)
{
    update_lazy(left, right, node);
    if(start > right || end < left)
    {
        return 0;
    }
    if(start <= left && right <= end)
    {
        return segTree[node];
    }
    int mid;
    mid = (left + right) / 2;
    return query(start, end, left, mid, node * 2) + query(start, end, mid + 1, right, node * 2 + 1);
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        int O, S, T;
        scanf("%d %d %d", &O, &S, &T);
        if(O == 0)
        {
            update(S - 1, T - 1, 0, N - 1, 1);
        }
        else
        {
            printf("%d\n", query(S - 1, T - 1, 0, N - 1, 1));
        }
    }
}