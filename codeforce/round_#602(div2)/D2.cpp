#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
pii arr[200005];
pair<pii, int> queryArr[200005];
int n, m, chk[200005], segTree[200005 * 4], Num[200005], result[200005];

/*
연속적으로 고르지 않아도 되므로 k개를 고를때 합이 가장 크게 되는 방법은
정렬을 했을때 큰 순으로 k개를 고르는 방법이 가장 합이 크다.
k개를 벡터에 넣고 다시 인덱스 순으로 정렬을 한 후 pos번째 수를 출력해주면 된다.
하지만 벡터에 넣고 다시 정렬을 하는 방법은 n이 200000이나 되므로 제한 시간안에 돌릴수 없다.
그러므로 k개를 벡터에 넣는 방법 대신에 세그먼트 트리를 이용하여 k개의 수를 세그먼트 트리에 넣고
해당 구간에는 x개가 존재하는 방식을 이용해서 pos번째 수를 찾으면 된다. 세그먼트 트리에서
pos번째 수를 찾는 방법은 해당 구간을 반으로 나눴을때 왼쪽의 개수가 pos보다 작으면 pos번째는
반드시 오른쪽에 있고 pos보다 크거나 같으면 왼쪽에 있다. 이러한 방식으로 계속 반씩 줄여나가면
O(log N)만에 pos번째 수를 찾을 수 있다. 이제 k개를 세그먼트 트리에 넣어야 하는데
쿼리가 1, 2, 3, 4처럼 순차적으로 들어오면 간단하게 순차적으로 트리에 넣어주면 되지만
1, 10, 4, 7처럼 k가 정렬 되어있지 않으면 트리에 수들이 어디까지 들어와있는지 확인하기 어렵기 때문에
최악의 경우 O(N ^ 2)으로 수가 들어가 있는지 없는지 확인해야 한다. 따라서
쿼리를 정렬해서 1, 4, 7, 10으로 만들고 1개 넣고 3개 넣고 3개 넣고 3개 넣으면 O(N)으로 트리에 수를
넣을 수 있다.
*/

bool comp(pii &t, pii &u)
{
    if(t.first == u.first)
        return t.second > u.second;
    return t.first < u.first;
}

void update(int num, int left, int right, int node)
{
    if(num < left || right < num)
        return;
    if(left == right)
    {
        segTree[node] = 1;
        return;
    }
    int mid;
    mid = (left + right) / 2;
    update(num, left, mid, node * 2);
    update(num, mid + 1, right, node * 2 + 1);
    segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
    return;
}

int query(int num, int left, int right, int node)
{
    if(left == right)
        return left;
    int mid;
    mid = (left + right) / 2;
    //왼쪽 구간의 수의 개수가 pos번째보다 크거나 같으면 왼쪽을 탐색
    if(segTree[node * 2] >= num)
        return query(num, left, mid, node * 2);
    //그게 아니라면 오른쪽 탐색
    return query(num - segTree[node * 2], mid + 1, right, node * 2 + 1);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Num[i]);
        arr[i].first = Num[i];
        arr[i].second = i;
    }
    sort(arr, arr + n, comp);
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &queryArr[i].first.first, &queryArr[i].first.second);
        queryArr[i].second = i;
    }
    //쿼리를 k오름차순으로 정렬
    sort(queryArr, queryArr + m);
    //마지막으로 확인한 개수
    int last = n;
    for(int i = 0; i < m; i++)
    {
        //쿼리가 k = 4, k = 4, k = 4처럼
        //동일한 k가 여러개 들어올수 있기 때문에 여러번 확인하는것을 방지
        if(chk[queryArr[i].first.first] == 0)
        {
            chk[queryArr[i].first.first] = 1;
            for(int j = n - queryArr[i].first.first; j < last; j++)
            {
                update(arr[j].second, 0, n - 1, 1);
            }
            last = n - queryArr[i].first.first;
        }
        result[queryArr[i].second] = Num[query(queryArr[i].first.second, 0, n - 1, 1)];
    }
    for(int i = 0; i < m; i++)
    {
        printf("%d\n", result[i]);
    }
}