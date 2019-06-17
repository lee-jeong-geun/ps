#include <bits/stdc++.h>
using namespace std;
int n, m, visit[1005][1005], result;
char zone[1005][1005];

/*
주어진 맵에서 직사각형들을 찾아야 한다.
모든 맵을 돌면서 문제의 조건에 맞는 직사각형들을 찾으면 되는데 먼저 첫번째 구간의 색깔이
몇개가 연속 되어있는지 확인하고 두번째 세번째 구간이 첫번째 색깔의 개수와 일치 하는지 확인 후
첫번째 두번째 색깔이 다르고 두번째 세번째 색깔이 달랐을때 카운트를 한다. 이런식으로 몇개의
가로줄이 연속 되어있는지 카운트 하고 카운트 * (카운트 + 1) / 2를 결과값에 더해주면 된다.
*/

//몇개가 연속 되어있는지 확인
int BlockCount(int x, int y)
{
    int count = 0, ty;
    ty = y;
    while(ty < n)
    {
        if(zone[y][x] != zone[ty][x])
            break;
        count++;
        ty++;
    }
    return count;
}

//해당 구간이 전부 같은 색깔인지 확인
bool BlockChk(int x, int start, int end)
{
    if(end >= n)
        return 0;
    for(int i = start; i < end; i++)
    {
        if(zone[i][x] != zone[i + 1][x])
            return 0;
    }
    return 1;
}

//해당 구간을 방문 표시
void ChkFunc(int x, int y, int ycount, int xcount)
{
    for(int i = y; i < y + ycount; i++)
    {
        for(int j = x; j < x + xcount; j++)
        {
            visit[i][j] = 1;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", zone[i]);
    }
    int count, bcount, tx;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            count = 0;
            bcount = 0;
            tx = j;
            //이미 방문 한것이라면 패스
            if(visit[i][j] == 1)
                continue;
            //첫번째 색깔이 몇개가 연속인지
            count = BlockCount(tx, i);
            while(tx < m)
            {
                //연속된 색깔이 다른경우
                if(count != BlockCount(tx, i))
                    break;
                //두번째 구간의 색깔이 같지 않거나 세번째 구간의 색깔이 같지 않다면 아웃
                if(!BlockChk(tx, i + count, i + count * 2 - 1) ||
                    !BlockChk(tx, i + count * 2, i + count * 3 - 1))
                    break;
                //모든 가로줄이 동일해야 함
                if(zone[i][tx] != zone[i][j] || zone[i + count][tx] != zone[i + count][j] || 
                    zone[i + count * 2][tx] != zone[i + count * 2][j])
                    break;
                //첫번째 구간과 두번째 구간의 색깔이 달라야 하고 두번째 구간과 세번째 구간이 달라야 함
                if(zone[i][tx] == zone[i + count][tx] || zone[i + count][tx] == zone[i + count * 2][tx])
                    break;
                bcount++;
                tx++;
            }
            ChkFunc(j, i, count, bcount);
            result += bcount * (bcount + 1) / 2;
        }
    }
    printf("%d", result);
}