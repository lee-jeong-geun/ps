#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, zone[25][25], result = 987654321;
int arrA[5] = { 0, 0, 0, 1, -1 }; // 버튼 기능 
int arrB[5] = { 0, 1, -1, 0, 0 }; // 구현

// 전구 전부다 off인지 확인
bool zonechk()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (zone[i][j] == 1)
			{
				return 0;
			}
		}
	}
	return 1;
}

//버튼 누른곳 주위 전구 reverse
void change(int x, int y)
{
	for (int i = 0; i < 5; i++)
	{
		if (x + arrA[i] >= 0 && x + arrA[i] < N && y + arrB[i] >= 0 && y + arrB[i] < N)
		{
			zone[y + arrB[i]][x + arrA[i]] = !zone[y + arrB[i]][x + arrA[i]];
		}
	}
}

//맨윗줄 제외한 나머지줄 재귀 함수
void func2(int x, int y, int depth)
{
	if (y == N)
	{
		if (zonechk() == 1)
		{
			result = min(result, depth);
		}
		return;
	}
	if (zone[y - 1][x] == 1)
	{
		change(x, y);
		if (x + 1 == N)
		{
			func2(0, y + 1, depth + 1);
		}
		else
		{
			func2(x + 1, y, depth + 1);
		}
		change(x, y);
	}
	else
	{
		if (x + 1 == N)
		{
			func2(0, y + 1, depth);
		}
		else
		{
			func2(x + 1, y, depth);
		}
	}
}

//맨윗줄 조합 재귀함수
void func(int x, int depth)
{
	for (int i = x + 1; i < N; i++)
	{
		change(i, 0);
		func(i, depth + 1);
		change(i, 0);
	}
	func2(0, 1, depth);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &zone[i][j]);
		}
	}
	if (zonechk() == 1)
	{
		result = min(result, 0);
	}
	func(-1, 0);
	if (result == 987654321)
	{
		result = -1;
	}
	printf("%d", result);
}