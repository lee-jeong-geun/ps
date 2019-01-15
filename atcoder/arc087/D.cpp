#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<pair<int, int>> fVec, tVec;
vector<int> dirVec[2];
int e[5], memo[8001][16004], result[5];
char s[8005];

/*
연속된 F는 방향 변함없이 직진하는 것이기 때문에 압축 시키면 된다.
연속된 T는 현재 이동방향에서 x축과 평행하게 이동하거나 y축과 평행하게 이동하는 것중 하나이다.
T가 짝수개라면 현재 이동방향과 동일한 축으로 이동한다. 홀수개라면 현재 이동방향에서 방향이 수직인 축으로 바뀐다.
x축이라면 y축으로, y축이라면 x축으로.
모든 F와 T를 연속된 부분을 하나로 압축 시킨 상태에서 완전탐색에 들어간다.
x, y, 방향, 인덱스로 메모이제이션 가능하나 경우의 수가 워낙 많이 때문에 시간 초과가 난다.
잘 보면 x축으로 이동 하는것은  y축으로 이동 하든 안하든 변함이 없다.
무슨 소리냐면 3, 0에서 y축으로 -3칸 가든 3칸 가든 x가 3인 것은 변함이 없다.
즉 x축으로만 이동해서 목표지점의 x좌표에 도달 할 수 있냐를 y축 이동을 제외하고 확인 할 수 있다.
따라서 x축 이동하는 것들만 따로 빼서 다 이동 시킨 후 마지막 좌표가 목표 지점 x좌표인지 확인 하면 된다.
y축 이동도 위와 같은 식으로 한다면 위의 x, y, 방향, 인덱스의 디피 테이블을
x, 인덱스와 y, 인덱스로 줄일 수 있다.
*/

void func(int dir, int tidx, int hap, int fidx)
{
    //한번이라도 목표지점에 도달한 경우
    if(result[dir] == 1)
    {
        return;
    }
    //끝의 인덱스인 경우
    if(tidx == dirVec[dir].size())
    {
        //목표지점 도착 한 경우
        if(hap == e[dir])
        {
            result[dir] = 1;
        }
        return;
    }
    int &ret = memo[tidx][hap + 8001];
    if(ret != 0)
    {
        return;
    }
    ret = 1;
    int nextHap = 0;
    for(int i = fidx; i < fVec.size(); i++)
    {
        //F인덱스가 현재 축 이동하는 인덱스보다 작은 경우는 무시
        if(fVec[i].first > dirVec[dir][tidx])
        {
            nextHap = fVec[i].second;
            fidx = i;
            break;
        }
    }
    //축 양쪽으로 이동
    func(dir, tidx + 1, hap + nextHap, fidx + 1); 
    func(dir, tidx + 1, hap - nextHap, fidx + 1);
    return;
}

int main()
{
    int length;
    scanf("%s %d %d", s, &e[0], &e[1]);
    length = strlen(s);
    int count = 1;
    for(int i = 0; i < length; i++)
    {
        //연속된 F와 T들 압축
        if(s[i] != s[i + 1])
        {
            if(s[i] == 'T')
            {
                tVec.push_back({i, count});
            }
            else
            {
                fVec.push_back({i, count});
            }
            count = 0;
        }
        count++;
    }
    //T가 하나도 없는 경우
    if(tVec.size() == 0)
    {
        //x축으로만 이동가능
        //따라서 목표 좌표가 y는 0이고 x는 F만큼 이동한 거리일 경우
        if(e[1] == 0 && fVec[0].second == e[0])
        {
            printf("Yes");
        }
        else
        {
            printf("No");
        }
        return 0;
    }
    //F가 하나도 없는 경우
    if(fVec.size() == 0)
    {
        //목표 좌표가 0, 0 이여야 함
        if(e[0] == 0 && e[1] == 0)
        {
            printf("Yes");
        }
        else
        {
            printf("No");
        }
        return 0;
    }
    int flag = 0;
    for(int i = 0; i < tVec.size(); i++)
    {
        //x축, y축 이동 분류
        if(tVec[i].second % 2 != 0)
        {
            flag = !flag;
        }
        dirVec[flag].push_back(tVec[i].first);
    }
    int startHap = 0, startF = 0;
    //처음 시작은 오른쪽 방향이라서
    //T가 나오기 전에 F가 있는 경우 F만큼 이동 시킴
    if(fVec[0].first < tVec[0].first)
    {
        startHap = fVec[0].second;
        startF = 1;
    }
    func(0, 0, startHap, startF);
    memset(memo, 0, sizeof memo);
    func(1, 0, 0, 0);
    result[0] + result[1] == 2 ? printf("Yes") : printf("No");
}