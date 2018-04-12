#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, y, count, dir;
}Data;
Data virus[1005];
int N, M, K, result, chk[5][105][105];
int arrA[4] = {0, 0, -1, 1};
int arrB[4] = {-1, 1, 0, 0};
int Dir[4] = {1, 0, 3, 2};

/*
주어진 조건에 맞게 시뮬레이션 돌리면 된다.
*/

void init()
{
    result = 0;
}

//맵의 가장자리인지 판별
bool range(int a, int b)
{
    if(a == 0 || a == N - 1 || b == 0 || b == N - 1)
    {
        return 1;
    }
    return 0;
}

void func()
{
    //맵에서 초기화 해야할 좌표 개수
    int clearcount = 0;
    Data clearzone[1005];
    while(M--)
    {
        clearcount = 0;
        for(int i = 0; i < K; i++)
        {
            //합쳐진 미생물이라서 패스
            if(virus[i].count == 0)
            {
                continue;
            }
            virus[i].x += arrA[virus[i].dir];
            virus[i].y += arrB[virus[i].dir];
            //맵의 가장자리이면 절반 감소
            if(range(virus[i].x, virus[i].y) == 1)
            {
                virus[i].count /= 2;
                virus[i].dir = Dir[virus[i].dir];
            }
            //현재 좌표의 미생물들 합
            chk[1][virus[i].y][virus[i].x] += virus[i].count;
            //현재 좌표의 미생물보다(합 말고) 많을 경우
            if(chk[0][virus[i].y][virus[i].x] < virus[i].count)
            {
                //미생물이 이미 왔던 경우
                if(chk[0][virus[i].y][virus[i].x] != 0)
                {
                    //그 미생물을 없앰
                    virus[chk[2][virus[i].y][virus[i].x]].count = 0;
                }
                //초기화 하기 위해 좌표를 넣어줌
                clearzone[clearcount].x = virus[i].x;
                clearzone[clearcount++].y = virus[i].y;
                //현재 좌표의 미생물을 갱신 해줌
                chk[0][virus[i].y][virus[i].x] = virus[i].count;
                //인덱스도 갱신 해줌
                chk[2][virus[i].y][virus[i].x] = i;
            }
            else
            {
                virus[i].count = 0;
            }
        }
        //초기화
        for(int i = 0; i < clearcount; i++)
        {
            if(chk[1][clearzone[i].y][clearzone[i].x] == 0)
            {
                continue;
            }
            //미생물을 합쳐줌
            virus[chk[2][clearzone[i].y][clearzone[i].x]].count = chk[1][clearzone[i].y][clearzone[i].x];
            chk[0][clearzone[i].y][clearzone[i].x] = 0;
            chk[1][clearzone[i].y][clearzone[i].x] = 0;
        }
    }
    for(int i = 0; i < K; i++)
    {
        result += virus[i].count;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        init();
        scanf("%d %d %d", &N, &M, &K);
        for(int i = 0; i < K; i++)
        {
            scanf("%d %d %d %d", &virus[i].y, &virus[i].x, &virus[i].count, &virus[i].dir);
            virus[i].dir--;
        }
        func();
        printf("#%d %d\n", testcase, result);
    }
}


///나중에 푼것




#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef struct _data
{
	int x, y, vcount, dir, flag;
}Data;
Data virus[1005];
int N, K, M, result, zone[105][105], Count[105][105];
int arrA[4] = { 0, 0, -1, 1 };
int arrB[4] = { -1, 1, 0, 0 };

void init()
{
	memset(zone, -1, sizeof zone);
	memset(Count, 0, sizeof Count);
	result = 0;
}

bool range(int a, int b)
{
	if (a == 0 || a == N - 1 || b == 0 || b == N - 1)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		init();
		scanf("%d %d %d", &N, &M, &K);
		for (int i = 0; i < K; i++)
		{
			scanf("%d %d %d %d", &virus[i].y, &virus[i].x, &virus[i].vcount, &virus[i].dir);
			virus[i].dir--;
			virus[i].flag = 0;
		}
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < K; j++)
			{
				if (virus[j].flag == 0)
				{
					zone[virus[j].y][virus[j].x] = -1;
					Count[virus[j].y][virus[j].x] = 0;
				}
			}
			for (int j = 0; j < K; j++)
			{
				if (virus[j].flag == 1)
				{
					continue;
				}
				int nextx, nexty;
				nextx = virus[j].x + arrA[virus[j].dir];
				nexty = virus[j].y + arrB[virus[j].dir];
				if (range(nextx, nexty) == 1)
				{
					virus[j].vcount /= 2;
					if (virus[j].dir % 2 == 0)
					{
						virus[j].dir++;
					}
					else
					{
						virus[j].dir--;
					}
				}
                //미생물이 한번도 안온 경우
				if (zone[nexty][nextx] == -1)
				{
					zone[nexty][nextx] = j;
					Count[nexty][nextx] = virus[j].vcount;
				}
				else
				{
					if (virus[j].vcount > virus[zone[nexty][nextx]].vcount)
					{
						virus[zone[nexty][nextx]].flag = 1;
						zone[nexty][nextx] = j;
					}
					else
					{
						virus[j].flag = 1;
					}
					Count[nexty][nextx] += virus[j].vcount;
				}
				virus[j].x = nextx;
				virus[j].y = nexty;
			}
			for (int j = 0; j < K; j++)
			{
				if (virus[j].flag == 0)
				{
					virus[j].vcount = Count[virus[j].y][virus[j].x];
				}
			}
		}
		for (int i = 0; i < K; i++)
		{
			if (virus[i].flag == 0)
			{
				result += virus[i].vcount;
			}
		}
		printf("#%d %d\n", testcase, result);
	}
}