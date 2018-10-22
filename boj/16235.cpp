#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int idx;
    int age;
}Data;
typedef struct _data2
{
    int x;
    int y;
}Data2;
Data DeadTree[170005];
Data2 Move[105];
int Tree[105][1705], Tidx[105];
int Didx;
int N, M, K, zone[105], plusZone[105], result;
int arrX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int arrY[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

/*
문제의 조건에 맞게 시뮬레이션을 구현 하면 된다.
시뮬레이션 경우의 수가 매우 많으므로 벡터를 이용하면 시간초과가 나게된다.
봄 조건중에서 나무의 나이가 어린순으로 양분을 주기 때문에 겨울이 끝나고 각각의 땅에 대해 나무의 나이순으로 정렬을 해주면 된다.
그리고 봄에서 죽는 나무들을 따로 배열에 담아서 여름에 한번에 처리해 주면 된다.'
가을은 살아있는 나무들 전체를 확인 하면서 5의 배수이면 퍼지도록 하였다.
겨울은 각 땅에 양분을 더해주면 된다.
*/

void Spring()
{
    for(int i = 1; i <= N * N; i++)
    {
        //삭제 해야 할 개수
        int count = 0;
        for(int j = 0; j < Tidx[i]; j++)
        {
            //남아있는 양분이 나무의 나이 이상인 경우
            if(zone[i] != 0 && zone[i] >= Tree[i][j])
            {
                //양분 빼줌
                zone[i] -= Tree[i][j];
                //나이 1증가
                Tree[i][j]++;
            }
            else
            {
                //죽은 나무들 관리 배열에 저장
                DeadTree[Didx].idx = i;
                DeadTree[Didx++].age = Tree[i][j];
                count++;
            }
        }
        //살아있는 나무 개수 감소
        Tidx[i] -= count;
    }
}

void Summer()
{
    for(int i = 0; i < Didx; i++)
    {
        //각각의 땅에 죽은 나무 나이만큼 양분 증가
        zone[DeadTree[i].idx] += DeadTree[i].age / 2;    
    }
    Didx = 0;
}

void Fall()
{
    for(int i = 1; i <= N * N; i++)
    {
        for(int j = 0; j < Tidx[i]; j++)
        {
            if(Tree[i][j] % 5 == 0)
            {
                for(int k = 0; k < 8; k++)
                {
                    int nextx, nexty, nextidx;
                    nextx = Move[i].x + arrX[k];
                    nexty = Move[i].y + arrY[k];
                    nextidx = nexty * N + nextx + 1;
                    //맵 안에 있다면
                    if(nextx >= 0 && nextx < N && nexty >= 0 && nexty < N)
                    {
                        //나무 추가
                        Tree[nextidx][Tidx[nextidx]] = 1;
                        Tidx[nextidx]++;
                    }
                }
            }
        }
    }
}

void Winter()
{
    for(int i = 1; i <= N * N; i++)
    {
        zone[i] += plusZone[i];
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int num;
            scanf("%d", &num);
            plusZone[i * N + j + 1] = num;
            zone[i * N + j + 1] = 5;
            Move[i * N + j + 1].x = j;
            Move[i * N + j + 1].y = i;
        }
    }
    for(int i = 0; i < M; i++)
    {
        int x, y, age;
        scanf("%d %d %d", &y, &x, &age);
        x--;
        y--;
        Tree[y * N + x + 1][Tidx[y * N + x + 1]] = age;
        Tidx[y * N + x + 1]++;
    }
    for(int age = 1; age <= K; age++)
    {
        Spring();
        Summer();
        Fall();
        Winter();
        for(int i = 1; i <= N * N; i++)
        {
            //각각의 땅에 있는 나무들 나이순으로 정렬
            sort(Tree[i], Tree[i] + Tidx[i]);
        }
    }
    for(int i = 1; i <= N * N; i++)
    {
        result += Tidx[i];
    }
    printf("%d", result);
}