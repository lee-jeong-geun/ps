#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int x;
    int y;
}Data;
Data point[1005];
int N, T, M, tel[1005], telArr[1005], near[1005], tIdx, result;

/*
두 지점의 최소 이동시간은 min(두지점간에 맨하탄 거리, 텔레포트 타고가는 시간, 가장 가까운 텔레포트
위치 + 텔레포트 타고가는 시간)중에 하나이다.
각각의 지점에서 가장 가까운 텔레포트 위치를 미리 저장한다면 더 빠르다.
*/

int main()
{
    scanf("%d %d", &N, &T);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d %d %d", &tel[i], &point[i].x, &point[i].y);
        //텔레포트 지점 배열에 저장
        if(tel[i])
        {
            telArr[tIdx++] = i;
        }
        near[i] = 987654321;
    }
    for(int i = 1; i <= N; i++)
    {
        if(tel[i] == 1)
        {
            near[i] = 0;
            continue;
        }
        //가장 가까운 텔레포트 위치 찾기
        for(int j = 0; j < tIdx; j++)
        {
            near[i] = min(near[i], abs(point[i].x - point[telArr[j]].x) + abs(point[i].y - point[telArr[j]].y));
        }
        //하나도 없다면 0
        if(tIdx == 0)
        {
            near[i] = 0;
        }
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        int A, B;
        scanf("%d %d", &A, &B);
        //두 지점간에 맨하탄 거리
        result = abs(point[A].x - point[B].x) + abs(point[A].y - point[B].y);
        //두 지점이 텔레포트인 경우
        if(tel[A] == 1 && tel[B] == 1)
        {
            result = min(result, T);
        }
        int countA, countB;
        countA = near[A];
        countB = near[B];
        //가장 가까운 텔레포트로 이동후 텔레포트
        result = min(result, countA + countB + T);
        printf("%d\n", result);
    }
}