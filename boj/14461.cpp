#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int N, T, zone[105][105];
int arrX[4] = {0, 1, 0, -1};
int arrY[4] = {-1, 0, 1, 0};
long long result = 98765432100, chk[105][105][5];
typedef long long ll;

/*
어떤 좌표 x는 어떤 좌표들로 부터 1칸, 2칸, 3칸을 이동해 도착한 좌표이다.
따라서 visit배열을 1칸, 2칸, 3칸으로 이동한 경우로 나눠서 잡으면 된다.
visit 배열 chk[y][x][moveCount]는 (x, y)좌표에 1칸, 2칸, 3칸으로 이동한 경우 누적 시간들의 최소를
저장한다.
이렇게 BFS를 돌리면 항상 최소만 저장되는데 큐 안에 있는 어떤 좌표의 누적시간이 visit배열의 누적시간보다
크면 절대 최소가 될 수 없으므로 continue 시키면 된다.
*/

void BFS()
{
    priority_queue<pair<ll, pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, {0, 0}}});
    chk[0][0][0] = 0;
    while(!pq.empty())
    {
        ll tempWeight;
        int tempX, tempY, tempMoveCount;
        tempWeight = -pq.top().first;
        tempX = pq.top().second.second.first;
        tempY = pq.top().second.second.second;
        tempMoveCount = pq.top().second.first;
        pq.pop();
        //해당 좌표의 시간보다 큰 경우
        if(chk[tempY][tempX][tempMoveCount] < tempWeight)
        {
            continue;
        }
        //도착지에 도착한 경우
        if(tempX == N - 1 && tempY == N - 1)
        {
            result = min(result, tempWeight);
            continue;
        }
        for(int i = 0; i < 4; i++)
        {
            ll nextWeight;
            int nextX, nextY, nextMoveCount;
            nextX = tempX + arrX[i];
            nextY = tempY + arrY[i];
            nextMoveCount = tempMoveCount + 1;
            nextWeight = tempWeight + T;
            if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < N)
            {
                //3칸을 이동한 경우
                if(nextMoveCount == 3)
                {
                    nextWeight += zone[nextY][nextX];
                    nextMoveCount = 0;
                }
                //다음 좌표의 최소값보다 작은 경우
                if(chk[nextY][nextX][nextMoveCount] > nextWeight)
                {
                    chk[nextY][nextX][nextMoveCount] = nextWeight;
                    pq.push({-nextWeight, {nextMoveCount, {nextX, nextY}}});
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &T);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &zone[i][j]);
            for(int k = 0; k < 3; k++)
            {
                chk[i][j][k] = (long long)1 << 60;
            }
        }
    }
    BFS();
    printf("%lld", result);
}