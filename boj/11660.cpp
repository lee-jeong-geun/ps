#include <cstdio>
#include <iostream>
using namespace std;
int N, M, Sum[1030][1030];

/*
이 문제는 2차원 행렬에서 구간의 합을 구하는 것인데
어떤 구간의 합을 원소 하나씩 다 접근하면서 구한다면
총 1024 * 1024 * 100000의 시간복잡도가 발생한다.
누적합을 이용해서 어떤 구간의 합을 O(1)로 줄일수 있다.
1,1부터 100,100까지의 합을 구하고 싶을때
Num[1][1] + Num[1][2] + ... + Num[100][99] + Num[100][100]처럼 일일이 구할수 있지만
Sum[100][100]에다 위에 식을 저장하면 한번에 구할수 있다.
곧 Sum[100][100]은 1,1부터 100,100까지의 합을 저장한 값이다.
5,5부터 65,40의 합을 구하고 싶으면
Sum[65][40] - Sum[4][40] - Sum[65][4] + Sum[4][4]를 하면된다.
*/



int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int num;
            scanf("%d", &num);
            Sum[i][j] = Sum[i - 1][j] + Sum[i][j - 1] - Sum[i - 1][j - 1] + num;
        }
    }
    for(int j = 0; j < M; j++)
    {
        int sx, sy, ex, ey;
        scanf("%d %d %d %d", &sy, &sx, &ey, &ex);
        printf("%d\n", Sum[ey][ex] - Sum[sy - 1][ex] - Sum[ey][sx - 1] + Sum[sy - 1][sx - 1]);
    }
}