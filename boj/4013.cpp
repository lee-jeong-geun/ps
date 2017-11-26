#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int>vec[500005];
vector<int>SCC[500005];
int N, M, ATM[500005], S, P, R[500005], dfsdepth[500005], depth, scc[500005], scount, ATMmoney[500005], sccchk[500005], RSCC[500005], Max, result[500005], BFSchk[500005];

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
            ATMmoney[scount] += ATM[temp];
            if(R[temp] == 1)
            {
                RSCC[scount] = 1;
            }
            for(int i = 0; i < vec[temp].size(); i++)
            {
                if(scc[vec[temp][i]] != scc[temp] && sccchk[vec[temp][i]] == 0)
                {
                    sccchk[vec[temp][i]] = 1;
                    BFSchk[scc[vec[temp][i]]]++;
                    SCC[scount].push_back(scc[vec[temp][i]]);
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

void BFS()
{
    queue<int>q;
    for(int i = 1; i <= scount; i++)
    {
        if(i == scc[S])
        {
            result[i] = ATMmoney[i];
        }
        if(BFSchk[i] == 0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int temp;
        temp = q.front();
        q.pop();
        if(RSCC[temp] == 1)
        {
            Max = max(Max, result[temp]);
        }
        for(int i = 0; i < SCC[temp].size(); i++)
        {
            int next;
            next = SCC[temp][i];
            if(result[temp] == 0)
            {
                result[next] = max(result[next], 0);
            }
            else
            {
                result[next] = max(result[next], result[temp] + ATMmoney[next]);
            }
            BFSchk[next]--;
            if(BFSchk[next] == 0)
            {
                q.push(next);
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        vec[s].push_back(e);
    }
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &ATM[i]);
    }
    scanf("%d %d", &S, &P);
    for(int i = 0; i < P; i++)
    {
        int r;
        scanf("%d", &r);
        R[r] = 1;
    }
    for(int i = 1; i <= N; i++)
    {
        if(dfsdepth[i] == 0)
        {
            DFS(i);
        }
    }
    BFS();
    printf("%d", Max);
}