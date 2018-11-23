#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x;
    int y;
}Data;
Data point[230];
int N, M, zone[20][20], chk[20][20], result[20][20], Min = 987654321, pidx;
int arrX[5] = {0, 0, 1, 0, -1};
int arrY[5] = {0, -1, 0, 1, 0};

/*
모든 맵에 대해서 버튼을 누르고 안누르고의 경우의 수는 2 ^ 225개가 된다.
어떤 행을 모두 0으로 만들고 싶으면 1인 열의 바로 아래 행에 버튼을 누르면 0으로 만들 수 있다.
이런 방식으로 모든 행에 대해서 수행을 한 후 맨 아래 행에 1인 열이 하나라도 존재 하는지 확인 하면 된다.
최소한의 격자를 누르는 경우를 찾기 위해서는 맨 위의 행을 열에 대하여 누르고 안누르고의 조합을 한 후
위에 방법으로 모든 격자를 0으로 바꿀 수 있는지 확인 하면 된다.
*/

//격자 상태 바꿈
void change(int x, int y)
{
    for(int i = 0; i < 5; i++)
    {
        int nextx, nexty;
        nextx = x + arrX[i];
        nexty = y + arrY[i];
        if(nextx >= 0 && nextx < N && nexty >= 0 && nexty < M)
        {
            zone[nexty][nextx] ^= 1;
        }
    }
}

void func(int idx, int count)
{
    if(idx == N)
    {
        pidx = 0;
        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {
                //해당 열이 1일 경우
                if(zone[i][j] == 1)
                {
                    //맨 아래 행이 아니라면 버튼을 누름
                    if(i < M - 1)
                    {
                        change(j, i + 1);
                        chk[i + 1][j] = 1;
                        count++;
                        point[pidx].x = j;
                        point[pidx++].y = i + 1;
                    }
                    //맨 아래 행인 경우 안되는 조건임
                    else
                    {
                        count = 987654321;
                    }
                }
            }
        }
        //갱신
        if(count < Min)
        {
            Min = count;
            for(int i = 0; i < M; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    result[i][j] = chk[i][j];
                }
            }
        }
        //버튼을 누르기 전으로 되돌림
        for(int i = 0; i < pidx; i++)
        {
            change(point[i].x, point[i].y);
            chk[point[i].y][point[i].x] = 0;
        }
        return;
    }
    //버튼을 안누르는 경우
    func(idx + 1, count);
    //버튼을 누르는 경우
    change(idx, 0);
    chk[0][idx] = 1;
    func(idx + 1, count + 1);
    chk[0][idx] = 0;
    change(idx, 0);
}

int main()
{
    scanf("%d %d", &M, &N);
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &zone[i][j]);
        }
    }
    func(0, 0);
    if(Min == 987654321)
    {
        printf("IMPOSSIBLE");
        return 0;
    }
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}