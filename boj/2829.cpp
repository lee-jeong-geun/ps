#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Sum[2][405][405], A, result = -987654321;

/*
주어진 행렬에서 모든 부분 행렬에 대해 (주대각선 성분 합 - 다른 대각선 성분 합)의 최대치를 구하면 된다.
각각의 부분 행렬에 대해 대각선 성분을 일일이 구하는 것은 시간이 오래 걸리므로 부분합을 이용하여
빠르게 구해준다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int num;
            scanf("%d", &num);
            //주대각선의 부분합
            Sum[0][i][j] = Sum[0][i - 1][j - 1] + num;
            //다른 대각선의 부분합
            Sum[1][i][j] = Sum[1][i - 1][j + 1] + num;
        }
    }
    for(int i = 1; i < N; i++)
    {
        for(int j = 1; j < N; j++)
        {
            int nextx, nexty;
            nextx = j + 1;
            nexty = i + 1;
            while(nextx <= N && nexty <= N)
            {
                int right, left;
                //주대각선
                right = Sum[0][nexty][nextx] - Sum[0][i - 1][j - 1];
                //다른 대각선
                left = Sum[1][nexty][j] - Sum[1][i - 1][nextx + 1];
                result = max(result, right - left);
                nextx++;
                nexty++;
            }
        }
    }
    printf("%d", result);
}