#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef struct _data
{
    int x;
    int y;
    int dir;
    int K;
}Data;
Data atom[1005], zoneChk[1005];
int N, zone[2005][2005], chk[1005], result, Count, zidx;
int arrA[4] = {0, 0, -1, 1};
int arrB[4] = {-1, 1, 0, 0};

/*
2000x2000배열을 잡고 시뮬레이션을 돌렸다.
입력값은 음수가 있는 좌표평면으로 주어지기 때문에 배열 인덱스로 맞추기 위해 x값을 +1000
y값을 -1곱하고 +1000을 해주었다.
각각의 원자들을 맵 배열에 표시를 해주었고 원자들이 이동하다가 충돌하는 것들을 해주었다.
한점에 모여서 충돌하는 경우는 배열의 한개의 인덱스에 모이는것을 구현 하면 되고
0.5초만에 충돌하는 경우는 모든 원자들을 한번씩 이동 시킨 후 해당 원자의 다음칸에 방향이 반대인 원자가
존재 할 경우 충돌시키는 방식으로 구현 하였다.
그리고 2000x2000배열을 넘어갈 경우 해당 원자는 절대 충돌이 일어나지 않으므로 시뮬레이션에서 제외 시켰다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        //맵에 남은 원자 수
        Count = 0;
        result = 0;
        memset(chk, 0, sizeof chk);
        scanf("%d", &N);
        for(int i = 1; i <= N; i++)
        {
            scanf("%d %d %d %d", &atom[i].x, &atom[i].y, &atom[i].dir, &atom[i].K);
            //좌표평면에서 배열로
            atom[i].x += 1000;
            atom[i].y = -atom[i].y + 1000;
            zone[atom[i].y][atom[i].x] = i;
        }
        for(int Time = 0; Time < 2005; Time++)
        {
            //초기화 시킬 맵 인덱스
            zidx = 0;
            //맵에 원자가 없을 경우 종료
            if(Count == N)
            {
                break;
            }
            //원자와 원자가 한칸 차이나는 경우 탐색
            for(int i = 1; i <= N; i++)
            {
                //삭제된 원자는 시뮬레이션에서 제외
                if(chk[i] == 1)
                {
                    continue;
                }
                zone[atom[i].y][atom[i].x] = 0;
                int nextx, nexty;
                //다음 위치
                nextx = atom[i].x + arrA[atom[i].dir];
                nexty = atom[i].y + arrB[atom[i].dir];
                //다음 위치가 맵을 벗어나면 제외시킴
                if(nextx < 0 || nextx > 2000 || nexty < 0 || nexty > 2000)
                {
                    Count++;
                    chk[i] = 1;
                    continue;
                }
                //다음 위치에 있는 원자가 자기와 반대 방향인 경우 충돌 시킴
                if(chk[zone[nexty][nextx]] == 0 && zone[nexty][nextx] != 0 && (atom[i].dir ^ atom[zone[nexty][nextx]].dir) == 1)
                {
                    Count += 2;
                    chk[i] = 1;
                    chk[zone[nexty][nextx]] = 1;
                    result += atom[i].K + atom[zone[nexty][nextx]].K;
                    zone[nexty][nextx] = 0;
                }
            }
            //모든 원자 한칸씩 이동
            for(int i = 1; i <= N; i++)
            {
                if(chk[i] == 1)
                {
                    continue;
                }
                int nextx, nexty;
                nextx = atom[i].x + arrA[atom[i].dir];
                nexty = atom[i].y + arrB[atom[i].dir];
                if(nextx < 0 || nextx > 2000 || nexty < 0 || nexty > 2000)
                {
                    Count++;
                    chk[i] = 1;
                    continue;
                }
                //다음 위치에 원자가 있는 경우
                if(zone[nexty][nextx] != 0)
                {
                    //중복 해서 충돌시키면 안되기 때문
                    if(chk[zone[nexty][nextx]] == 0)
                    {
                        Count++;
                        chk[zone[nexty][nextx]] = 1;
                        result += atom[zone[nexty][nextx]].K;
                    }
                    Count++;
                    chk[i] = 1;
                    result += atom[i].K;
                    //초기화 배열에 해당 맵 인덱스 저장
                    zoneChk[zidx].x = nextx;
                    zoneChk[zidx++].y = nexty;
                }
                zone[nexty][nextx] = i;
                atom[i].x = nextx;
                atom[i].y = nexty;
            }
            //맵 초기화
            for(int i = 0; i < zidx; i++)
            {
                zone[zoneChk[i].y][zoneChk[i].x] = 0;
            }
        }
        //맵 초기화
        for(int i = 1; i <= N; i++)
        {
            zone[atom[i].y][atom[i].x] = 0;
        }
        printf("#%d %d\n", testcase, result);
    }
}