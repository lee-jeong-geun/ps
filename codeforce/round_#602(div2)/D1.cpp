#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
pii arr[105];
vector<int> vec;
int n, m, Num[105];

/*
연속적으로 고르지 않아도 되므로 k개를 고를때 합이 가장 크게 되는 방법은
정렬을 했을때 큰 순으로 k개를 고르는 방법이 가장 합이 크다.
k개를 벡터에 넣고 다시 인덱스 순으로 정렬을 한 후 pos번째 수를 출력해주면 된다.
*/

bool comp(pii &t, pii &u)
{
    if(t.first == u.first)
        return t.second > u.second;
    return t.first < u.first;
}

int main()
{
    int n;
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
        int k, pos;
        scanf("%d %d", &k, &pos);
        vec.clear();
        //k개의 수를 벡터에 저장
        //수가 같을땐 작은 인덱스가 들어가게 저장
        for(int j = n - k; j < n; j++)
        {
            vec.push_back(arr[j].second);
        }
        //인덱스 순으로 정렬
        sort(vec.begin(), vec.end());
        printf("%d\n", Num[vec[pos - 1]]);
    }
}