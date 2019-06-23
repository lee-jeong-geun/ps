#include <bits/stdc++.h>
using namespace std;
vector<int> modeVec;
vector<pair<int, int>> vec[30];
vector<pair<pair<int, int>, pair<int, int>>> result;
int t, n, m, Last, rflag;
char zone[2005][2005], tzone[2005][2005];
int arrX[5] = {1, 0};
int arrY[5] = {0, 1};

/*
모든 뱀들은 가로 한줄 or 세로 한줄로 되어 있어야 한다.
이러한 조건을 판별하기 위해서는 입력을 받을때 같은 종류의 알파벳들을 하나의 벡터에 넣어서
알파벳들이 한줄로 이루어져 있는지 확인을 하면 된다.
한줄로 되어있다면 이제 빈 그림판에 주어진 알파벳으로 뱀을 그리면 된다.
이때 입력으로 주어진 그림판에서 없는 알파벳들이 있을것이다. 그러한 알파벳들은 그것들 보다 늦은 순번의
알파벳에 덮어 씌여 졌다고 생각하면 된다. 다 그리고 난 후 입력으로 주어진 그림판과 비교를 해서 다르면
NO 맞으면 YES를 출력 하면 된다.
*/

void init()
{
    rflag = 0;
    //마지막 알파벳
    Last = -1;
    //해당 알파벳이 가로or세로 판별
    modeVec.clear();
    result.clear();
    for(int i = 0; i < 26; i++)
    {
        vec[i].clear();
    }
}

int main()
{
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        init();
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                scanf(" %c", &zone[i][j]);
                if(zone[i][j] != '.')
                {
                    //같은 종류의 알파벳을 모으는 벡터
                    vec[zone[i][j] - 'a'].push_back({j, i});
                    Last = max(Last, zone[i][j] - 'a');
                }
            }
        }
        for(int i = 0; i <= Last; i++)
        {
            int count = 0, flag = 0;
            for(int j = 0; j < vec[i].size(); j++)
            {
                //행이 전부 같다는 것은 가로로 이루어진 뱀
                if(vec[i][0].first == vec[i][j].first)
                    count++;
            }
            if(count == vec[i].size())
            {
                //1은 앞으로 탐색할 때 가로로 탐색 한다는 뜻
                modeVec.push_back(1);
                flag = 1;
                continue;
            }
            count = 0;
            for(int j = 0; j < vec[i].size(); j++)
            {
                //열이 전부 같은것은 세로로 이루어진 뱀
                if(vec[i][0].second == vec[i][j].second)
                    count++;
            }
            if(count == vec[i].size())
            {
                //0은 세로로 탐색
                modeVec.push_back(0);
                flag = 1;
            }
            if(flag == 0)
                rflag = 1;
        }
        if(rflag == 1)
        {
            printf("NO\n");
            continue;
        }
        for(int i = 0; i <= Last; i++)
        {
            int tx, ty, mode, ex, ey;
            //비어있는 알파벳은 맨 마지막 알파벳이 덮었다고 생각하면 됨
            if(vec[i].size() == 0)
            {
                result.push_back({{vec[Last].begin()->first, vec[Last].begin()->second}, {vec[Last].rbegin()->first, vec[Last].rbegin()->second}});
                continue;
            }
            tx = vec[i][0].first;
            ty = vec[i][0].second;
            mode = modeVec[i];
            ex = vec[i].rbegin()->first;
            ey = vec[i].rbegin()->second;
            while(tx <= ex && ty <= ey)
            {
                //하나라도 빈칸이면 안됨
                if(zone[ty][tx] == '.')
                    rflag = 1;
                tzone[ty][tx] = 'a' + i;
                tx += arrX[mode];
                ty += arrY[mode];
            }
            result.push_back({{vec[i][0].first, vec[i][0].second}, {ex, ey}});
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(zone[i][j] != '.' && zone[i][j] != tzone[i][j])
                    rflag = 1;
            }
        }
        if(rflag == 1)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        printf("%d\n", result.size());
        for(int i = 0; i < result.size(); i++)
        {
            printf("%d %d %d %d\n", result[i].first.second + 1, result[i].first.first + 1, result[i].second.second + 1, result[i].second.first + 1);
        }
    }
}