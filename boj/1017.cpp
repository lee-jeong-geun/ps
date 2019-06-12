#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
    int v, capa, rev;
    Edge(int v, int capa, int rev) : v(v), capa(capa), rev(rev) {}
};
vector<vector<Edge>> vec;
vector<int> Num[5], result;
int N, arr[55], level[55], work[55], prime[2005], chk[55][55];

/*
2를 제외한 소수는 무조건 홀수이기 때문에 짝수와 홀수로 나눠서 이분매칭을 시키면 된다.
이분매칭은 하나의 쌍이라도 매칭이 안될때까지 하고 매칭이 끝날때마다 다시 그래프를 만드는데 
이때 1번 숫자와 매칭된 숫자의 간선을 연결 시키지 않는다.

예외 케이스 
4
20 6 11 9
*/

void addEdge(int start, int end, int capa)
{
    vec[start].emplace_back(end, capa, vec[end].size());
    vec[end].emplace_back(start, 0, vec[start].size() - 1);
}

int BFS()
{
    memset(level, -1, sizeof level);
    queue<int> q;
    q.push(0);
    level[0] = 0;
    while(!q.empty())
    {
        int temp;
        temp = q.front();
        q.pop();
        for(int i = 0; i < vec[temp].size(); i++)
        {
            int next, nextCapa;
            next = vec[temp][i].v;
            nextCapa = vec[temp][i].capa;
            if(level[next] == -1 && nextCapa > 0)
            {
                level[next] = level[temp] + 1;
                q.push(next);
            }
        }
    }
    return level[N + 1] != -1;
}

int DFS(int node, int f)
{
    if(node == N + 1)
        return f;
    int minFlow;
    for(int &i = work[node]; i < vec[node].size(); i++)
    {
        int next, nextCapa;
        next = vec[node][i].v;
        nextCapa = vec[node][i].capa;
        if(level[next] == level[node] + 1 && nextCapa > 0)
        {
            minFlow = DFS(next, min(f, nextCapa));
            if(minFlow > 0)
            {
                vec[node][i].capa -= minFlow;
                vec[next][vec[node][i].rev].capa += minFlow;
                return minFlow;
            }
        }
    }
    return 0;
}

//그래프 만드는 함수
void build()
{
    vec.clear();
    vec.resize(N * 2 + 5);
    for(int i = 0; i < Num[0].size(); i++)
    {
        addEdge(0, Num[0][i], 1);
    }
    for(int i = 0; i < Num[1].size(); i++)
    {
        addEdge(Num[1][i], N + 1, 1);
    }
    for(int i = 0; i < Num[0].size(); i++)
    {
        for(int j = 0; j < Num[1].size(); j++)
        {
            //한번이라도 매칭된 간선일 경우 패스
            if(chk[Num[0][i]][Num[1][j]] == 1)
                continue;
            //합이 소수라면 연결
            if(prime[arr[Num[0][i]] + arr[Num[1][j]]] == 0)
            {
                addEdge(Num[0][i], Num[1][j], 1);
            }
        }
    }
}

int main()
{
    //에라토스 테네스의 체
    for(int i = 2; i <= 2000; i++)
    {
        if(prime[i] == 1)
            continue;
        for(int j = i + i; j <= 2000; j += i)
        {
            prime[j] = 1;
        }
    }
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
        //짝수 홀수 분할
        Num[arr[i] % 2].push_back(i);
    }
    //항상 첫번째 숫자가 Num[0]으로 오게 설정
    if(arr[1] % 2 == 1)
        swap(Num[0], Num[1]);
    while(1)
    {
        build();
        int count = 0;
        while(BFS())
        {
            memset(work, 0, sizeof work);
            int minFlow;
            while(1)
            {
                minFlow = DFS(0, 987654321);
                if(minFlow == 0)
                    break;
                count += minFlow;
            }
        }
        if(count < N / 2)
            break;
        for(int i = 0; i < vec[Num[0][0]].size(); i++)
        {
            //1번숫자와 매칭된 간선인 경우 유량이 0
            if(vec[Num[0][0]][i].capa == 0)
            {
                chk[Num[0][0]][vec[Num[0][0]][i].v] = 1;
                result.push_back(arr[vec[Num[0][0]][i].v]);
                break;
            }
        }
    }
    if(result.size() == 0)
    {
        printf("-1");
        return 0;
    }
    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
}