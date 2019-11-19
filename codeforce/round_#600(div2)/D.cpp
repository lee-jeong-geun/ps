#include <bits/stdc++.h>
using namespace std;
vector<int> vec[200005];
vector<pair<int, int>> vec2, vec3;
int n, m, chk[200005], Min, Max, parent[200005], result;

/*
주어진 노드들을 DFS를 이용하여 연결된 노드들끼리 그룹화 시킨다.
이때 해당 그룹의 가장 작은 번호의 노드와 가장 큰 번호의 노드를 저장해서 
vec2에 저장을 하고 vec2에 저장 되어있는 구간들중 (1 ~ 200000, 2 ~ 15)처럼
어떤 구간에 속해있는 구간들을 라인스위핑을 이용하여 전부 하나로 합쳐준다.
그러면 어디에도 속하지 않는 개별적인 구간들만 남아있는데 해당 구간의(Min ~ Max)까지
탐색을 하면서 서로 다른 그룹이라면 합쳐주고 결과값을 1증가 시키면 된다.
그룹들을 관리하는 자료구조는 union-find를 이용하면 된다.
*/

int find(int node)
{
    if(parent[node] == node)
        return node;
    return parent[node] = find(parent[node]);
}

void uni(int node1, int node2)
{
    node1 = find(node1);
    node2 = find(node2);
    if(node1 != node2)
        parent[node1] = node2;
}

void func(int node)
{
    //해당 그룹의 Min, Max탐색
    Min = min(Min, node);
    Max = max(Max, node);
    chk[node] = 1;
    for(int i = 0; i < vec[node].size(); i++)
    {
        int next;
        next = vec[node][i];
        if(chk[next] == 0)
        {
            uni(node, next);
            func(next);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        vec[s].push_back(e);
        vec[e].push_back(s);
    }
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        Min = 987654321;
        Max = 0;
        if(chk[i] == 0)
        {
            func(i);
            vec2.push_back({Min, Max});
        }
    }
    //라인스위핑을 위한 Min값으로 오름차순 정렬
    sort(vec2.begin(), vec2.end());
    //더미 구간을 넣어서 맨 마지막값 예외 처리
    vec2.push_back({987654321, 987654321});
    int l, r;
    l = vec2[0].first;
    r = vec2[0].second;
    for(int i = 1; i < vec2.size(); i++)
    {
        //겹쳐있지 않는  구간이라면 vec3에 푸쉬
        if(r < vec2[i].first)
        {
            vec3.push_back({l, r});
            l = vec2[i].first;
            r = vec2[i].second;
        }
        r = max(r, vec2[i].second);
    }
    for(int i = 0; i < vec3.size(); i++)
    {
        int node;
        node = vec3[i].first;
        //Min ~ Max까지 하나의 그룹으로 만들어주는 과정
        for(int j = vec3[i].first + 1; j < vec3[i].second; j++)
        {
            //하나의 그룹이 아니라면 하나로 합침
            if(find(node) != find(j))
            {
                uni(node, j);
                result++;
            }
        }
    }
    printf("%d", result);
}