#include <cstdio>
#include <iostream>
using namespace std;
int N, Sum[15][305][305], Q;

/*
이 문제는 2차원 누적합에 서로다른 정수의 개수를 추가해야 돼서 3차원 누적합을 이용하면 된다.
Sum[k][300][300]은 1,1부터 300,300까지 k의 개수가 들어있다.
쿼리 x1,y1 부터 x2,y2는 여기에 k의 종류가 총 몇개인지를 파악하는 것이다.
Sum[1 ~ 10][y2][x2] - Sum[1 ~ 10][y1 - 1][x2] - Sum[1 ~ 10][y2][x1 - 1] + Sum[1 ~ 10][y1 - 1][x1 - 1]
가 0이 아니면 존재 하므로 카운트를 해주면 된다.
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
            for(int k = 1; k <= 10; k++)
            {
                Sum[k][i][j] = Sum[k][i - 1][j] + Sum[k][i][j - 1] - Sum[k][i - 1][j - 1];
                if(num == k)
                {
                    Sum[k][i][j]++;
                }
            }
        }
    }
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++)
    {
        int sx, sy, ex, ey, count = 0;
        scanf("%d %d %d %d", &sy, &sx, &ey, &ex);
        for(int k = 1; k <= 10; k++)
        {
            //0이 아니라는 건 k가 존재 한다는 뜻
            if(Sum[k][ey][ex] - Sum[k][sy - 1][ex] - Sum[k][ey][sx - 1] + Sum[k][sy - 1][sx - 1] != 0)
            {
                count++;
            }
        }
        printf("%d\n", count);
    }
}