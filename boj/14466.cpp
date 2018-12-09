#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> Data;
typedef pair<int, int> Data2;
set<Data> s;
Data2 cow[10005];
int N, K, R, zone[105][105], chk[105][105], cidx, team[10005], tidx, result;
int arrX[4] = {0, 1, 0, -1};
int arrY[4] = {-1, 0, 1, 0};

/*
길을 건너지 않고 만날수 없는 소들은 길로 둘러 싸여 있는 소들이다.
길로 둘러 싸여서 있는 소들을 찾아야 하는데 여러 소들이 붙어있는 상태에서 길로 둘러 싸여 있을수도 있기 때문에
붙어있는 소들도 찾아 주어야 한다.
즉 각각의 분리 되어있는 공간들을 찾아야 하는 것이다.
BFS를 이용하여 각각의 소들의 위치에서 탐색을 하는데 해당 좌표에서 다음 좌표에 길이 놓여있는 경우를 제외
해주면서 현재 소와 어떤 소들이 같은 공간에 있는지 탐색 해주어야 한다.
모든 쌍을 출력 해야 하므로 각 공간의 개수를 저장 후 쌍을 카운트 하면 된다.
길이 놓여져 있는지 찾을 때는 4차원 배열을 이용할 수 있지만 메모리를 너무 많이 잡아 먹기 때문에 set을 이용하였다.
선형 탐색으로 길이 놓여 있는지 확인하는 방법은 길의 개수가 못해도 10000개는 되기 때문에 시간이 너무 오래 걸린다.
*/

void BFS(int x, int y)
{
    int count = 1;
    queue<Data2> q;
    q.push({x, y});
    zone[y][x] = 0;
    while(!q.empty())
    {
        Data2 temp;
        temp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            Data2 next;
            next.first = temp.first + arrX[i];
            next.second = temp.second + arrY[i];
            //맵안에 위치
            if(next.first >= 1 && next.first <= N && next.second >= 1 && next.second <= N)
            {
                //한번도 가지 않았고 길이 놓여있지 않은 경우
                if(chk[next.second][next.first] == 0 && s.find({{temp.first, temp.second}, {next.first, next.second}}) == s.end())
                {
                    //소가 위치해 있는 경우
                    if(zone[next.second][next.first] == 1)
                    {
                        //개수를 더해주고 없애줌
                        count++;
                        zone[next.second][next.first] = 0;
                    }
                    chk[next.second][next.first] = 1;
                    q.push(next);
                }
            }
        }
    }
    //해당 공간에 속해있는 소의 마리수
    team[tidx++] = count;
}

int main()
{
    scanf("%d %d %d", &N, &K, &R);
    for(int i = 0; i < R; i++)
    {
        int sx, sy, ex, ey;
        scanf("%d %d %d %d", &sy, &sx, &ey, &ex);
        //길을 set에 저장
        s.insert({{sx, sy}, {ex, ey}});
        s.insert({{ex, ey}, {sx, sy}});
    }
    for(int i = 0; i < K; i++)
    {
        int x, y;
        scanf("%d %d", &y, &x);
        cow[cidx].first = x;
        cow[cidx++].second = y;
        zone[y][x] = 1;
    }
    for(int i = 0; i < K; i++)
    {
        if(chk[cow[i].second][cow[i].first] == 0)
        {
            BFS(cow[i].first, cow[i].second);
        }
    }
    int hap = 0;
    for(int i = 0; i < tidx; i++)
    {
        //모든 쌍의 개수
        result += team[i] * (K - hap - team[i]);
        hap += team[i];
    }
    printf("%d", result);
}