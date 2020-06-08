#include <bits/stdc++.h>
using namespace std;
vector<int> result;
int N, Q, arr[200005], parent[200005], query[400005][3];

/*
경로가 존재하는 것은 같은 트리안에 있다는 뜻이다.
같은 트리는 곧 루트가 같다는 뜻이므로 유니온 파인드를 이용하여 같은 그룹에 있는지 아닌지
빠르게 파악하면 된다. 하지만 1번 쿼리인 간선 삭제를 하게 되면 유니온 파인드의 핵심인 경로 압축의
효과가 사라지게 된다. 그 이유는 삭제하게 되면 루트가 달라지므로 해당 간선의 자식 노드들은
전부 루트를 바꿔줘야 하기 때문이다. 
따라서 매번 쿼리가 들어올 때마다 처리하는 것보다 한 번에 모아서 처리하는 테크닉을 써야 한다.
간선을 제거해서 그룹을 분리하는 것은 반대로 접근하면 간선을 추가해서 그룹을 합치는 것이다.
즉 쿼리를 들어오는 순서대로 처리하는 것이 아니라 한 번에 받아두고 역순으로 처리하면서
1번 쿼리는 두 개의 그룹을 합치고 2번 쿼리는 두 노드가 같은 노드인지 확인을 하면 된다.
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
    if(p1 != p2)
        parent[p1] = p2;
}

int main()
{
    scanf("%d %d", &N, &Q);
    parent[1] = 1;
    for(int i = 2; i <= N; i++)
    {
        scanf("%d", &arr[i]);
        parent[i] = i;
    }
    for(int i = 0; i < N + Q - 1; i++)
    {
        scanf("%d %d", &query[i][0], &query[i][1]);
        if(query[i][0] == 1)
            scanf("%d", &query[i][2]);
    }
    for(int i = N + Q - 2; i >= 0; i--)
    {
        if(query[i][0] == 1)
        {
            if(find(query[i][1]) == find(query[i][2]))
                result.push_back(1);
            else
                result.push_back(0);
        }
        else
            uni(query[i][1], arr[query[i][1]]);
    }
    for(int i = result.size() - 1; i >= 0; i--)
    {
        if(result[i] == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}