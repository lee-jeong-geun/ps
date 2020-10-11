#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> piii;
queue<piii> q;
int N, M, sr, sc, er, ec, dist[505][505], chk[505][505], result;
int arrR[4] = {-1, 0, 1, 0};
int arrC[4] = {0, 1, 0, -1};

/*
우선 각 나무로부터 BFS를 돌려서 모든 길에 나무와의 거리 차를 저장한다.
그런 다음 V에서 J까지 다익스트라를 이용하여 가장 안전한 길을 구하면 된다.
*/

int rangeChk(int r, int c)
{
    if(r >= 0 && r < N && c >= 0 && c < M)
        return 1;
    return 0;
}

int main()
{
    scanf("%d %d", &N, &M);
    memset(dist, 0x3f, sizeof dist);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            char word;
            scanf(" %c", &word);
            if(word == '+')
            {
                q.push({0, {i, j}});
                dist[i][j] = 0;
            }
            else if(word == 'V')
            {
                sr = i;
                sc = j;
            }
            else if(word == 'J')
            {
                er = i;
                ec = j;
            }
        }
    }
    while(!q.empty())
    {
        piii temp;
        temp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nextR, nextC, nextCount;
            nextR = temp.second.first + arrR[i];
            nextC = temp.second.second + arrC[i];
            nextCount = temp.first + 1;
            if(rangeChk(nextR, nextC) == 1 && dist[nextR][nextC] > nextCount)
            {
                dist[nextR][nextC] = nextCount;
                q.push({nextCount, {nextR, nextC}});
            }
        }
    }
    priority_queue<piii> pq;
    pq.push({dist[sr][sc], {sr, sc}});
    chk[sr][sc] = 1;
    while(!pq.empty())
    {
        piii temp;
        temp = pq.top();
        pq.pop();
        if(temp.second.first == er && temp.second.second == ec)
        {
            result = temp.first;
            break;
        }
        for(int i = 0; i < 4; i++)
        {
            int nextR, nextC, nextCount;
            nextR = temp.second.first + arrR[i];
            nextC = temp.second.second + arrC[i];
            if(rangeChk(nextR, nextC) == 1 && chk[nextR][nextC] == 0)
            {
                chk[nextR][nextC] = 1;
                nextCount = min(temp.first, dist[nextR][nextC]);
                pq.push({nextCount, {nextR, nextC}});
            }
        }
    }
    printf("%d", result);
}