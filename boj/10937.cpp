#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int N, result, zone[130], memo[130][1 << 12];
int score[5][5] = {{100, 70, 40, 0}, {70, 50, 30, 0}, {40, 30, 20, 0}, {0, 0, 0, 0}};

/*
디피를 이용하는 방법과 MCMF를 이용하는 방법이 있다.
*/

/*
완전탐색으로 한다면 상태가 안고름, 가로, 세로 총 3개가 나오게 되는데 맵을 꽉 채우는 경우
대략 3 ^ N ^ 2 / 2의 경우의 수가 나오게 된다. 무조건 시간초과가 나게 되므로 DP를 이용해야 한다.
우선 주어진 2차원 맵을 1차원으로 늘어 뜨린다. 0번째 인덱스에서 가로를 고르게 되면 0, 1인덱스는
사용을 못한다. 세로를 고르게 된다면 0, 0 + N인덱스는 사용을 못하게 된다. 3번째 인덱스에서 세로를 고른다면
3 + N인덱스를 고르지 못한다. 각 인덱스는 + 1, + N에 영향을 미치게 된다.
인덱스 3, 4, 5에서 세로를 고르면 3 + N, 4 + N, 5 + N에 영향을 미치는데 이 상태는 5 + N이하의 인덱스에서
가로를 고를때 고르지 못하도록 한다. 따라서 각 인덱스마다 인덱스 + N까지의 상태를 보고 가로, 세로를 고르는 
판별을 하고 현재 인덱스에서 이전에 똑같은 상태를 고른적이 있다면 더이상 고를 필요가 없으므로 리턴해주면 된다.
즉 dp[현재 인덱스][고른 상태]를 가지고 메모이제이션을 하면 되는데 상태는 비트 마스크를 이용하면 된다.
최대 N개까지만 보면 되므로 11개의 비트를 가지고 상태를 결정 하면 된다.
N이 5인 경우 00000의 비트가 있는데 여기서 가로를 고른다면 01000이 되고 세로를 고른다면 00001이 된다.
이러한 비트를 다음 인덱스로 이동한다면 맨왼쪽 비트를 없애고 전체비트를 왼쪽으로 쉬프트 한다.
01000에서 다음 인덱스로 이동하면 10000이 되는데 이 상황에서는 가로든 세로든 고르지 못하므로 다음 인덱스로
이동한다. 그러면 00000이 되고 이 상태에서는 가로든 세로든 고를 수 있게 된다.
*/

int func(int x, int state)
{
    if(x == N * N)
        return 0;
    int &ret = memo[x][state];
    if(ret != -1)
        return ret;
    ret = 0;
    int next;
    //맨왼쪽 비트만 제거
    next = (state & ((1 << N) - 1)) << 1;
    //현재 위치 사용 안한 경우
    if(((1 << N) & state) == 0)
    {
        //가로 고르기
        //원래 맵은 2차원이므로 현재 위치를 2차원으로 했을때 오른쪽 끝에 있다면 가로 못고름
        if((x + 1) % N != 0 && (state & (1 << (N - 1))) == 0)
            ret = max(ret, func(x + 1, next | (1 << N)) + score[zone[x]][zone[x + 1]]);
        //세로 고르기
        if(x + N < N * N && (state & 1) == 0)
            ret = max(ret, func(x + 1, next | 2) + score[zone[x]][zone[x + N]]);
    }
    //안고르고 넘어감
    ret = max(ret, func(x + 1, next));
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N * N; i++)
    {
        char word;
        scanf(" %c", &word);
        zone[i] = word - 'A';
        if(word == 'F')
            zone[i] = 3;
    }
    memset(memo, -1, sizeof memo);
    printf("%d", func(0, 0));
}









#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
struct Edge
{
    int v, capa, cost, rev;
    Edge(int v, int capa, int cost, int rev) : v(v), capa(capa), cost(cost), rev(rev) {}
};
vector<vector<Edge>> vec;
int N, result, zone[15][15], zoneIdx[15][15];
int score[5][5] = {{100, 70, 40, 0}, {70, 50, 30, 0}, {40, 30, 20, 0}, {0, 0, 0, 0}};
int arrX[4] = {0, 0, 1, -1};
int arrY[4] = {1, -1, 0, 0};
int dist[135], preNode[135], preEdge[135], inQ[135];

/*
규칙을 잘 보면 주어진 배열을 체스판으로 생각했을 때 같은색의 자리는 절대 쌍이 될 수 없다.
따라서 같은색끼리 한팀으로 하여 MCMF를 구하면 된다. 이때 최대 매칭을 하여도 최대 값이 나오지 않을 수도
있다. 무조건 매칭을 시키는게 아니라 매칭을 하지 못할 때는 바로 싱크로 가게끔 간선 하나를 만들어 주면 된다.
*/

void addEdge(int start, int end, int capa, int cost)
{
    vec[start].emplace_back(end, capa, cost, vec[end].size());
    vec[end].emplace_back(start, 0, -cost, vec[start].size() - 1);
}

int SPFA()
{
    memset(dist, 0x3f, sizeof dist);
    memset(preNode, 0, sizeof preNode);
    memset(preEdge, 0, sizeof preEdge);
    memset(inQ, 0, sizeof inQ);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty())
    {
        int temp;
        temp = q.front();
        q.pop();
        inQ[temp] = 0;
        for(int i = 0; i < vec[temp].size(); i++)
        {
            int next, nextCapa, nextCost;
            next = vec[temp][i].v;
            nextCapa = vec[temp][i].capa;
            nextCost = dist[temp] - vec[temp][i].cost;
            if(nextCapa > 0 && dist[next] > nextCost)
            {
                dist[next] = nextCost;
                preNode[next] = temp;
                preEdge[next] = i;
                if(inQ[next] == 0)
                {
                    inQ[next] = 1;
                    q.push(next);
                }
            }
        }
    }
    return dist[N * N + 1] < 987654321;
}

int main()
{
    scanf("%d", &N);
    vec.resize(N * N + 5);
    int idx = 1;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if((i + j) % 2 == 0)
                addEdge(0, idx, 1, 0);
            //싱크로 바로 가는 간선 추가
            addEdge(idx, N * N + 1, 1, 0);
            char word;
            scanf(" %c", &word);
            zone[i][j] = word - 'A';
            if(word == 'F')
                zone[i][j] = 3;
            zoneIdx[i][j] = idx++;
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if((i + j) % 2 != 0)
                continue;
            //4방향에 있는 다른색깔 자리랑 연결
            for(int k = 0; k < 4; k++)
            {
                int nextx, nexty;
                nextx = j + arrX[k];
                nexty = i + arrY[k];
                if(nextx >= 0 && nextx < N && nexty >= 0 && nexty < N)
                    addEdge(zoneIdx[i][j], zoneIdx[nexty][nextx], 1, score[zone[i][j]][zone[nexty][nextx]]);
            }
        }
    }
    while(SPFA())
    {
        int minFlow = 987654321;
        for(int i = N * N + 1; i != 0; i = preNode[i])
        {
            int node, idx;
            node = preNode[i];
            idx = preEdge[i];
            minFlow = min(minFlow, vec[node][idx].capa);
        }
        for(int i = N * N + 1; i != 0; i = preNode[i])
        {
            int node, idx;
            node = preNode[i];
            idx = preEdge[i];
            vec[node][idx].capa -= minFlow;
            vec[i][vec[node][idx].rev].capa += minFlow;
            result += vec[node][idx].cost * minFlow;
        }
    }
    printf("%d", result);
}