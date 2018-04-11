#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, C, zone[15][15], result;

/*
두명의 일꾼이 선택하는 구간들을 구한 후 구간에서 합이 C보다 아래고 그 합들을 제곱했을때
최대값을 완전탐색으로 찾으면 된다.
*/


//구간에서 제곱 최대값 탐색
int func2(int sx, int ex, int y, int hap, int money)
{
    int Max = 0;
    Max = max(Max, money);
    for(int i = sx; i <= ex; i++)
    {
        if(hap + zone[y][i] <= C)
        {
            Max = max(Max, func2(i + 1, ex, y, hap + zone[y][i], money + zone[y][i] * zone[y][i]));
        }
    }
    return Max;
}

//구간 나누기
void func(int sx, int ex, int y)
{
    int fhap, shap;
    for(int i = y; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i == y && j <= ex)
            {
                continue;
            }
            if(j + M - 1 >= N)
            {
                continue;
            }
            fhap = func2(sx, ex, y, 0, 0);
            shap = func2(j, j + M - 1, i, 0, 0);
            result = max(result, fhap + shap);
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        result = 0;
        scanf("%d %d %d", &N, &M, &C);
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
                if(j + M - 1 >= N)
                {
                    continue;
                }
                func(j, j + M - 1, i);
            }
        }
        printf("#%d %d\n", testcase, result);
    }
}


//나중에 푼것



#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, C, zone[15][15], result;

//제곱 최대값 찾기
int func(int depth, int x, int y, int count, int hap)
{
	int Max = 0;
	if (depth == M)
	{
		return hap;
	}
	Max = func(depth + 1, x + 1, y, count, hap);
	if (count + zone[y][x] <= C)
	{
		Max = max(Max, func(depth + 1, x + 1, y, count + zone[y][x], hap + zone[y][x] * zone[y][x]));
	}
	return Max;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		result = 0;
		scanf("%d %d %d", &N, &M, &C);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &zone[i][j]);
			}
		}
        //구간 나누기
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= N - M; j++)
			{
				int temp1, temp2;
				temp1 = func(0, j, i, 0, 0);
				for (int k = i; k < N; k++)
				{
					for (int l = 0; l <= N - M; l++)
					{
						if (i == k && l <= j + M - 1)
						{
							continue;
						}
						temp2 = func(0, l, k, 0, 0);
						result = max(result, temp1 + temp2);
					}
				}
			}
		}
		printf("#%d %d\n", testcase, result);
	}
}