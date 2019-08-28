#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> result;
set<pair<int, int>> s;
int Count[5];
int arrX[4] = {0, 0, 1, -1};
int arrY[4] = {1, -1, 0, 0};

/*
방문해야되는 전체 방 개수가 20만을 넘지 않는다. 이 제약을 이용해서
단순하게 10억 x 10억의 정 중앙에서 DFS를 b, w가 0이 될 때 까지 아니면 더이상 방문 불가능 할 때 까지
돌리면 된다.
*/

void DFS(int x, int y)
{
    //맵이 너무 커서 set에 방문 체크
    s.insert({x, y});
    Count[(x + y) % 2]--;
    result.push_back({x, y});
    for(int i = 0; i < 4; i++)
    {
        int nextx, nexty;
        nextx = x + arrX[i];
        nexty = y + arrY[i];
        //다음 칸의 색깔을 다 모은 경우
        if(Count[(nextx + nexty) % 2] == 0)
            continue;
        if(s.find({nextx, nexty}) == s.end())
            DFS(nextx, nexty);
    }
}

int main()
{
    int q;
    scanf("%d", &q);
    for(int tc = 0; tc < q; tc++)
    {
        s.clear();
        result.clear();
        scanf("%d %d", &Count[1], &Count[0]);
        DFS(500000000, 500000000);
        //b, w둘중 하나라도 다 못 찾는 경우
        if(Count[0] != 0 || Count[1] != 0)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(int i = 0; i < result.size(); i++)
        {
            printf("%d %d\n", result[i].first, result[i].second);
        }
    }
}