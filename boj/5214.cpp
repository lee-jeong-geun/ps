#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<int> vec[100005], node[1005];
int N, K, M, chkNum[100005], chkNode[1005], result = 987654321;

/*
역에 대해서 그래프를 만들게 되면 간선이 너무 많이 생기므로 하이퍼 튜브에 대해서 그래프를 만든다.
하이퍼 튜브에 대해서 BFS를 돌리는데 하이퍼 튜브 안에 있는 역이 속해있는 하이퍼 튜브를 큐에 계속 넣는
방식으로 하면 된다.
*/

void BFS()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    chkNode[0] = 1;
    while(!q.empty())
    {
        pii temp;
        temp = q.front();
        q.pop();
        if(temp.first == M + 1)
        {
            result = temp.second;
            return;
        }
        for(int i = 0; i < node[temp.first].size(); i++)
        {
            int nextNum;
            nextNum = node[temp.first][i];
            if(chkNum[nextNum] == 1)
                continue;
            chkNum[nextNum] = 1;
            for(int j = 0; j < vec[nextNum].size(); j++)
            {
                int nextNode;
                nextNode = vec[nextNum][j];
                if(chkNode[nextNode] == 0)
                {
                    chkNode[nextNode] = 1;
                    q.push({nextNode, temp.second + 1});
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &K, &M);
    node[0].push_back(1);
    for(int i = 1; i <= M; i++)
    {
        for(int j = 0; j < K; j++)
        {
            int num;
            scanf("%d", &num);
            vec[num].push_back(i);
            node[i].push_back(num);
        }
    }
    vec[N].push_back(M + 1);
    BFS();
    if(result == 987654321)
        result = -1;
    printf("%d", result);
}