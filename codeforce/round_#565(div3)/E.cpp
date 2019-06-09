#include <bits/stdc++.h>
using namespace std;
vector<int> vec[200005], result[5];
int t, n, m, visit[200005], resultFlag, tc;

/*
주어진 그래프의 임의의 노드에서 DFS를 돌면서 짝수 깊이만 선택하거나 홀수 깊이만 선택하면 된다.
답은 항상 보장 되기 때문에 짝수 깊이의 개수가 n / 2를 넘으면 홀수를 출력하면 되고 그 반대라면
짝수를 출력 하면 된다.
*/

void DFS(int node, int mode)
{
    //방문 체크
    visit[node] = tc;
    //mode는 0 or 1(짝 or 홀)
    result[mode].push_back(node);
    for(int i = 0; i < vec[node].size(); i++)
    {
        if(visit[vec[node][i]] != tc)
            DFS(vec[node][i], mode ^ 1);
    }
}

int main()
{
    scanf("%d", &t);
    for(tc = 1; tc <= t; tc++)
    {
        result[0].clear();
        result[1].clear();
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            vec[i].clear();
        }
        for(int i = 0; i < m; i++)
        {
            int start, end;
            scanf("%d %d", &start, &end);
            vec[start].push_back(end);
            vec[end].push_back(start);
        }
        DFS(1, 0);
        resultFlag = 0;
        //짝수가 안되는 경우
        if(result[0].size() > n / 2)
        {
            resultFlag = 1;
        }
        printf("%d\n", result[resultFlag].size());
        for(int i = 0; i < result[resultFlag].size(); i++)
        {
            printf("%d ", result[resultFlag][i]);
        }
        printf("\n");
    }
    
}