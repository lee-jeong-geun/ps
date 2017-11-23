#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int>vec[10005];
vector<int>SCC[10005];
vector<int>SCCvec[10005];
vector<int>Print;
int N, M, dfsdepth[10005], depth, sccchk[10005], scc[10005], scount, computer[10005], result[10005], Max;

stack<int> s;

int DFS(int node)
{
    s.push(node);
    dfsdepth[node] = ++depth;
    int ret = dfsdepth[node];
    for(int i = 0; i < vec[node].size(); i++)
    {
        int next;
        next = vec[node][i];
        if(dfsdepth[next] == 0)
        {
            ret = min(ret, DFS(next));
        }
        else if(scc[next] == 0)
        {
            ret = min(ret, dfsdepth[next]);
        }
    }
    if(ret == dfsdepth[node])
    {
        scount++;
        while(!s.empty())
        {
            int temp;
            temp = s.top();
            s.pop();
            scc[temp] = scount;
            computer[scount]++;
            SCC[scount].push_back(temp);
            for(int i = 0; i < vec[temp].size(); i++)
            {
                if(scc[temp] != scc[vec[temp][i]] && sccchk[scc[vec[temp][i]]] == 0)
                {
                    sccchk[scc[vec[temp][i]]] = 1;
                    SCCvec[scount].push_back(scc[vec[temp][i]]);
                }
            }
            if(temp == node)
            {
                break;
            }
        }
        memset(sccchk, 0, sizeof sccchk);
    }
    return ret;
}

void func(int start, int node)
{
    if(sccchk[node] == 0)
    {
        sccchk[node] = 1;
        result[start] += computer[node];
    }
    Max = max(Max, result[start]);
    for(int i = 0; i < SCCvec[node].size(); i++)
    {
        int next;
        next = SCCvec[node][i];
        func(start, next);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        vec[e].push_back(s);
    }
    for(int i = 1; i <= N; i++)
    {
        if(dfsdepth[i] == 0)
        {
            DFS(i);
        }
    }
    for(int i = 1; i <= scount; i++)
    {
        memset(sccchk, 0, sizeof sccchk);
        func(i, i);
    }
    for(int i = 1; i <= scount; i++)
    {
        if(Max == result[i])
        {
            for(int j = 0; j < SCC[i].size(); j++)
            {
                Print.push_back(SCC[i][j]);
            }
        }
    }
    sort(Print.begin(), Print.end());
    for(int i = 0; i < Print.size(); i++)
    {
        printf("%d ", Print[i]);
    }
}