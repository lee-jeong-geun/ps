#include <bits/stdc++.h>
using namespace std;
vector<int> result;
int N, Q, arr[300005], parent[300005], cycle[300005], chk[300005], query[300005][3];

/*
유니온 파인드를 이용하여 1번 쿼리를 처리해준다. 
삭제하게 되는 경우 자식들의 부모를 전부 다시 구해야 하므로 쿼리를 반대로 접근 하면서 2번 쿼리를
삭제가 아닌 합치는 연산으로 바꿔서 경로 압축을 잘 사용할 수 있도록 만들면 된다.
사이클을 찾는 방법은 단순하게 합치는 두 노드의 루트가 같으면 사이클이다.
*/

int find(int node)
{
    if(node == parent[node])
        return node;
    return parent[node] = find(parent[node]);
}

void uni(int node1, int node2)
{
    int p1, p2;
    p1 = find(node1);
    p2 = find(node2);
    if(p1 == p2)
        cycle[p1] = 1;
    else
        parent[p1] = p2;
}

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
        parent[i] = i;
    }
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++)
    {
        scanf("%d %d", &query[i][0], &query[i][1]);
        if(query[i][0] == 2)
            chk[query[i][1]] = 1;
    }
    for(int i = 1; i <= N; i++)
    {
        if(arr[i] != 0 && chk[i] == 0)
            uni(i, arr[i]);
    }
    for(int i = Q - 1; i >= 0; i--)
    {
        if(query[i][0] == 1)
        {
            if(cycle[find(query[i][1])] == 0)
                result.push_back(find(query[i][1]));
            else
                result.push_back(-1);
        }
        else
            uni(query[i][1], arr[query[i][1]]);
    }
    for(int i = result.size() - 1; i >= 0; i--)
    {
        if(result[i] == -1)
            printf("CIKLUS\n");
        else
            printf("%d\n", result[i]);
    }
}