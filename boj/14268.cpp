#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<int> vec[100005];
int n, m, nodeIdx, fenwickTree[100005], startNode[100005], endNode[100005];

/*
트리를 펼치고 자식에 대하여 구간 업데이트 하면 된다.
펜윅트리로도 구간 업데이트가 가능하다.
*/

//트리 펼침
void func(int node)
{
    startNode[node] = ++nodeIdx;
    for(int i = 0; i < vec[node].size(); i++)
    {
        func(vec[node][i]);
    }
    endNode[node] = nodeIdx;
}

void update(int num, int cost)
{
    while(num <= n)
    {
        fenwickTree[num] += cost;
        num += (num & -num);
    }
}

int query(int num)
{
    int hap = 0;
    while(num > 0)
    {
        hap += fenwickTree[num];
        num -= (num & -num);
    }
    return hap;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        int parent;
        scanf("%d", &parent);
        if(i == 1)
        {
            continue;
        }
        vec[parent].push_back(i);
    }
    func(1);
    for(int i = 0; i < m; i++)
    {
        int type, num, w;
        scanf("%d %d", &type, &num);
        if(type == 1)
        {
            scanf("%d", &w);
            update(startNode[num], w);
            update(endNode[num] + 1, -w);
        }
        else
        {
            printf("%d\n", query(startNode[num]));
        }
    }
}