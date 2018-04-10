#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, zone[25][25], chk[105], result;
int arrA[4] = {1, 1, -1, -1};
int arrB[4] = {-1, 1, 1, -1};

/*
대각선으로만 움직여서 자기 자신으로 돌아올때 카운트의 최대값을 찾으면 된다.
단 반드시 사각형을 그려야한다.
*/

int range(int a, int b)
{
    if(a >= 0 && a < N && b >= 0 && b < N)
    {
        return 1;
    }
    return 0;
}

void func(int sx, int sy, int x, int y, int count, int dir)
{
    if(dir == 0 && x == sx && y == sy)
    {
        result = max(result, count);
    }
    if(range(x, y) == 0 || chk[zone[y][x]] == 1)
    {
        return;
    }
    chk[zone[y][x]] = 1;
    int nextx, nexty;
    func(sx, sy, x + arrA[dir], y + arrB[dir], count + 1, dir);
    if(dir == 1)
    {
        func(sx, sy, x + arrA[2], y + arrB[2], count + 1, 2);
    }
    else if(dir == 2)
    {
        func(sx, sy, x + arrA[3], y + arrB[3], count + 1, 3);
    }
    else if(dir == 3)
    {
        func(sx, sy, x + arrA[0], y + arrB[0], count + 1, 0);
    }
    chk[zone[y][x]] = 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        result = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                scanf("%d", &zone[i][j]);
            }
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                func(j, i, j, i, 1, 1);
            }
        }
        printf("#%d ", testcase);
        if(result < 5)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", result - 1);
        }
    }
}

///나중에 푼것

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, chk[105], zone[25][25], result;
int arrA[4] = { 1, -1, -1, 1 };
int arrB[4] = { 1, 1, -1, -1 };

bool range(int a, int b)
{
	if (a >= 0 && a < N && b >= 0 && b < N)
	{
		return 1;
	}
	return 0;
}

void func(int sx, int sy, int x, int y, int dir, int count)
{
	if (x == sx - 1 && y == sy + 1)
	{
		if (dir != 1)
		{
			result = max(result, count);
		}
		return;
	}
	for (int i = 0; i < 2; i++)
	{
		int nextx, nexty;
		nextx = x + arrA[dir + i];
		nexty = y + arrB[dir + i];
		if (range(nextx, nexty) == 1 && chk[zone[nexty][nextx]] == 0 && dir + i < 4 && nexty >= sy)
		{
			chk[zone[nexty][nextx]] = 1;
			func(sx, sy, nextx, nexty, dir + i, count + 1);
			chk[zone[nexty][nextx]] = 0;
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		result = 0;
		memset(chk, 0, sizeof chk);
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &zone[i][j]);
			}
		}
		for (int i = 0; i < N - 2; i++)
		{
			for (int j = 1; j < N - 1; j++)
			{
				chk[zone[i][j]] = 1;
				func(j, i, j, i, 0, 1);
				chk[zone[i][j]] = 0;
			}
		}
		if (result == 0)
		{
			result = -1;
		}
		printf("#%d %d\n", testcase, result);
	}
}