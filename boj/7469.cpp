#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> segTree;
int n, m, arr[100005], result;

/*
매번 구간을 정렬하고 K번째 수를 찾는것은 시간이 오래걸리므로 각 구간별로 정렬된 상태의 배열을
만들면 된다. 세그먼트 트리에 배열을 넣어서 각 구간별로 정렬된 상태를 만들고 탐색할 때는 
해당 구간들에 어떤 수들이 존재하는지 모르므로 이분탐색을 이용하여 K번째 수를 찾으면 된다.
K번째 수를 찾는 방법은 주어진 구간들에 대해서 -10억 ~ 10억 사이의 값을 통해 이분탐색으로 
mid값보다 작은 수들이 몇개 있는지로 판단한다. k보다 작다면 mid값을 작게해도 계속 k보다 작을테니
l을 키우고 그게 아니라면 r을 줄인다. 작은 수들의 개수를 찾는 방법은 upper_bound를 이용해서 찾으면 된다.
*/

void update(int left, int right, int node)
{
    if(left == right)
    {
        segTree[node].push_back(arr[left]);
        return;
    }
    int mid;
    mid = (left + right) / 2;
    update(left, mid, node * 2);
    update(mid + 1, right, node * 2 + 1);
    //분할 후 merge방식으로 구간에 수를 정렬
    int l, r, lSize, rSize;
    l = r = 0;
    lSize = segTree[node * 2].size();
    rSize = segTree[node * 2 + 1].size();
    while(l < lSize && r < rSize)
    {
        if(segTree[node * 2][l] < segTree[node * 2 + 1][r])
            segTree[node].push_back(segTree[node * 2][l++]);
        else
            segTree[node].push_back(segTree[node * 2 + 1][r++]);
    }
    while(l < lSize)
    {
        segTree[node].push_back(segTree[node * 2][l++]);
    }
    while(r < rSize)
    {
        segTree[node].push_back(segTree[node * 2 + 1][r++]);
    }
}

int query(int start, int end, int val, int left, int right, int node)
{
    if(start > right || end < left)
        return 0;
    if(start <= left && right <= end)
        return upper_bound(segTree[node].begin(), segTree[node].end(), val) - segTree[node].begin();
    int mid;
    mid = (left + right) / 2;
    return query(start, end, val, left, mid, node * 2) + query(start, end, val, mid + 1, right, node * 2 + 1);
}

int main()
{
    scanf("%d %d", &n, &m);
    segTree.resize(n * 4);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    update(0, n - 1, 1);
    for(int i = 0; i < m; i++)
    {
        int s, e, k, l, r;
        scanf("%d %d %d", &s, &e, &k);
        l = -1000000000;
        r = 1000000000;
        while(l <= r)
        {
            int mid;
            mid = (l + r) / 2;
            if(query(s - 1, e - 1, mid, 0, n - 1, 1) < k)
                l = mid + 1;
            else
            {
                result = mid;
                r = mid - 1;
            }
        }
        printf("%d\n", result);
    }
}