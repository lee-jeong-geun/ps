#include <cstdio>
#include <algorithm>
using namespace std;
int N, M, garo[10005], sero[10005], gSum[10005], sSum[10005], gCount[10005], sCount[10005], gResult = 987654321, sResult = 987654321;

/*
naive하게 푸는 시간 복잡도는 O(N^2 M)정도 나온다.
N이 최대 10000이고 M이 최대 100000이므로 다른 방법을 찾아야한다.
자세히 보면 최소가 되는 행의 위치는 열에 상관없이 행가지고 판단 가능하다. 열 또한 마찬가지다.
입력 받을때 행 배열, 열 배열을 만들어서 이곳에 저장 후 최소가 되는 지점을 찾아야 하는데
그 지점은 그곳을 제외한 나머지 지점들이 그 지점에 이동 할 때 걸리는 거리의 총합들 중에서 최소가 되는 지점이다.
i번째 열은 i번째를 제외한 나머지 열들에서 i번째로 이동 할 때 드는 거리의 총합이다. N개의 열들 중에서 총합이 최소가 되는 것을 찾으면 되는데
N개의 열을 모두 탐색하기 위해선 각각의 열에서 N - 1개를 탐색해야 하므로 O(N^2)의 시간 복잡도가 발생하게 된다.
누적합을 이용하여 O(N)으로 줄일 수 있다.
*/

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        int x, y;
        scanf("%d %d", &y, &x);
        //행 열 따로 입력 받음
        garo[x]++;
        sero[y]++;
    }
    for(int i = 1; i <= N; i++)
    {
        //열 누적합
        gSum[i] = gSum[i - 1] + garo[i] * i;
        //개수 누적합
        gCount[i] = gCount[i - 1] + garo[i];
        //행 누적합
        sSum[i] = sSum[i - 1] + sero[i] * i;
        sCount[i] = sCount[i - 1] + sero[i];
    }
    //i번째 지점 앞부분들 더하기 용도
    int gcountSum = 0, scountSum = 0;
    for(int i = 1; i <= N; i++)
    {
        int gtemp, stemp;
        //i번째 열의 오른쪽 + 왼쪽
        //빼주는 이유는 기준을 1번째 부터 잡았기 때문에 옮긴 좌표만큼 빼줘야 함
        gtemp = gSum[N] - gSum[i] - (gCount[N] - gCount[i]) * i + gcountSum;
        gcountSum += gCount[i];
        stemp = sSum[N] - sSum[i] - (sCount[N] - sCount[i]) * i + scountSum;
        scountSum += sCount[i];
        gResult = min(gResult, gtemp);
        sResult = min(sResult, stemp);
    }
    printf("%d", gResult + sResult);
}