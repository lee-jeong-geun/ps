#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int idx;
    int num;
}Data;
Data tNum[500005];
int N, Num[500005], segtree[2000005];

/*
좌표압축후 세그먼트 트리를 이용해서 각각의 선수들의 실력 보다 큰 수들을 찾는다.
찾은후 세그먼트 트리를 갱신해 주면 된다.
*/

bool comp(Data t, Data u)
{
    return t.num < u.num;
}

//구간 업데이트
int update(int start, int left, int right, int node)
{
    if(start > right || start < left)
    {
        return segtree[node];
    }
    if(left == right)
    {
        return segtree[node] = segtree[node] + 1;
    }
    int mid;
    mid = (left + right) / 2;
    return segtree[node] = update(start, left, mid, node * 2) + update(start, mid + 1, right, node * 2 + 1);
}

//구간 탐색
int Search(int start, int end, int left, int right, int node)
{
    if(start > right || end < left)
    {
        return 0;
    }
    if(start <= left && right <= end)
    {
        return segtree[node];
    }
    int mid;
    mid = (left + right) / 2;
    return Search(start, end, left, mid, node * 2) + Search(start, end, mid + 1, right, node * 2 + 1);
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Num[i]);
        //좌표 압축할 배열
        tNum[i].idx = i;
        tNum[i].num = Num[i];
    }
    sort(tNum, tNum + N, comp);
    //좌표 압축
    for(int i = 0; i < N; i++)
    {
        Num[tNum[i].idx] = i + 1;
    }
    for(int i = 0; i < N; i++)
    {
        printf("%d\n", Search(Num[i] + 1, N, 1, N, 1) + 1);
        update(Num[i], 1, N, 1);
    }
}