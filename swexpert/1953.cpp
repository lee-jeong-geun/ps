#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef struct _data
{
	int x, y, Time;
}Data;
int N, M, zone[55][55], R, C, L, chk[55][55], result, route[5][15][15];
int arrA[4] = { 0, 1, 0, -1 };
int arrB[4] = { -1, 0, 1, 0 };

/*
단순 BFS문제이다. 각각의 블록들을 이동 시킬수 있는 조건을 찾은 후
구현 하면 된다.
*/

bool range(int a, int b)
{
	if (a >= 0 && a < M && b >= 0 && b < N)
	{
		return 1;
	}
	return 0;
}

void init(int t)
{
	memset(chk, 0, sizeof chk);
	result = 0;
    //블록 이동 가능 경로
	if (t == 1)
	{
		for (int i = 1; i <= 7; i++)
		{
			if (i == 1 || i == 2 || i == 4 || i == 7)
			{
				route[0][i][1] = 1;
				route[0][i][2] = 1;
				route[0][i][5] = 1;
				route[0][i][6] = 1;
			}
		}
		for (int i = 1; i <= 7; i++)
		{
			if (i == 1 || i == 3 || i == 4 || i == 5)
			{
				route[1][i][1] = 1;
				route[1][i][3] = 1;
				route[1][i][6] = 1;
				route[1][i][7] = 1;
			}
		}
		for (int i = 1; i <= 7; i++)
		{
			if (i == 1 || i == 2 || i == 5 || i == 6)
			{
				route[2][i][1] = 1;
				route[2][i][2] = 1;
				route[2][i][4] = 1;
				route[2][i][7] = 1;
			}
		}
		for (int i = 1; i <= 7; i++)
		{
			if (i == 1 || i == 3 || i == 6 || i == 7)
			{
				route[3][i][1] = 1;
				route[3][i][3] = 1;
				route[3][i][4] = 1;
				route[3][i][5] = 1;
			}
		}
	}
}

void BFS()
{
	queue<Data>q;
	result = 1;
	chk[R][C] = 1;
	q.push({ C, R, L});
	while (!q.empty())
	{
		Data temp;
		temp = q.front();
		q.pop();
		if (temp.Time == 1)
		{
			continue;
		}
		for (int i = 0; i < 4; i++)
		{
			Data next;
			next.x = temp.x + arrA[i];
			next.y = temp.y + arrB[i];
			next.Time = temp.Time - 1;
			if (range(next.x, next.y) == 1 && chk[next.y][next.x] == 0)
			{
				if (route[i][zone[temp.y][temp.x]][zone[next.y][next.x]] == 1)
				{
					chk[next.y][next.x] = 1;
					q.push(next);
					result++;
				}
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		init(testcase);
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &zone[i][j]);
			}
		}
		BFS();
		printf("#%d %d\n", testcase, result);
	}
}