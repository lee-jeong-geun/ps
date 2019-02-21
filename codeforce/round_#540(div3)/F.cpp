#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> vec[300005];
int n, color[300005], Count[300005][3], result;

/*
트리를 구성 후 루트 노드부터 DFS를 돌면서 각 노드들의 빨간색, 파란색 개수에 자식 노드들의 빨간색, 파란색
개수를 더한다. 그리고 루트 노드를 제외한 노드들을 지우면서 루트 노드쪽에 빨간색, 파란색 개수와
지운 노드의 빨간색, 파란색 개수를 확인 후 문제의 조건에 맞을시 결과값을 더해주면 된다.
*/

//DFS
int func(int node, int type, int parent)
{
    int hap = 0;
    for(int i = 0; i < vec[node].size(); i++)
    {
        //사이클 제거
        if(vec[node][i] == parent)
        {
            continue;
        }
        //자식 노드들의 색깔 개수
        hap += func(vec[node][i], type, node);
    }
    //현재 노드에 색깔 개수 저장
    Count[node][type] += hap;
    return Count[node][type];
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &color[i]);
        Count[i][color[i]]++;
    }
    for(int i = 0; i < n - 1; i++)
    {
        int v, u;
        scanf("%d %d", &v, &u);
        vec[v].push_back(u);
        vec[u].push_back(v);
    }
    for(int i = 1; i < 3; i++)
    {
        func(1, i, 1);
    }
    for(int i = 2; i <= n; i++)
    {
        int rootRed, rootBlue;
        rootRed = Count[1][1] - Count[i][1];
        rootBlue = Count[1][2] - Count[i][2];
        //문제의 조건
        if((rootRed == 0 || rootBlue == 0) && (Count[i][1] == 0 || Count[i][2] == 0))
        {
            result++;
        }
    }
    printf("%d", result);
}