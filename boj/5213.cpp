#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
vector<pair<int, int>> arr[250005];
int N, zone[1005][1005], chk[250005], node[250005];
int arrR[4] = {-1, 0, 1, 0};
int arrC[4] = {0, 1, 0, -1};

/*
각 타일을 노드화 시키고 BFS 돌리면 된다.
경로를 역추적하는 방법은 BFS 돌면서 다음 타일에 현재 타일을 저장하는 방식으로 하면 된다.
그러면 맨 마지막 타일에서 첫 번째 타일이 나올 때 까지 반복문을 돌리면 된다.
*/

int getNode(int r, int c)
{
    int ret = 0;
    ret = (r / 2 + r % 2) * N + (r / 2) * (N - 1);
    if(r % 2 == 0)
        ret += c / 2;
    else
        ret += (c - 1) / 2;
    return ret;
}

void BFS(int r, int c)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{r, c}, 1});
    chk[0] = 1;
    node[0] = -1;
    while(!q.empty())
    {
        int tempR, tempC, tempCount, tempNode;
        tempR = q.front().first.first;
        tempC = q.front().first.second;
        tempCount = q.front().second;
        tempNode = getNode(tempR, tempC);
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nextR, nextC, nextCount, nextNode;
            nextR = tempR + arrR[i];
            nextC = tempC + arrC[i];
            nextCount = tempCount + 1;
            nextNode = getNode(nextR, nextC);
            if(nextR < 0 || nextR >= N || nextC < 0 || nextC >= N * 2 || zone[nextR][nextC] == 987654321)
                continue;
            if(zone[tempR][tempC] == zone[nextR][nextC] && chk[nextNode] == 0)
            {
                chk[nextNode] = 1;
                node[nextNode] = tempNode;
                for(int j = 0; j < 2; j++)
                {
                    q.push({{arr[nextNode][j].first, arr[nextNode][j].second}, nextCount});
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N * 2; j++)
        {
            int num = 987654321;
            if(i % 2 != 1 || (j != 0 && j != N * 2 - 1))
                scanf("%d", &num);
            zone[i][j] = num;
            if(num != 987654321)
                arr[getNode(i, j)].push_back({i, j});
        }
    }
    BFS(0, 1);
    int idx = -1;
    for(int i = N - 1; i >= 0; i--)
    {
        for(int j = N * 2 - 1; j >= 0; j--)
        {
            if(chk[getNode(i, j)] == 1)
            {
                idx = getNode(i, j);
                break;
            }
        }
        if(idx != -1)
            break;
    }
    while(idx != -1)
    {
        vec.push_back(idx);
        idx = node[idx];
    }
    reverse(vec.begin(), vec.end());
    printf("%d\n", vec.size());
    for(int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i] + 1);
    }
}