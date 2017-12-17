#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, result = 987654321, resulta, resultb;
char picture[55][5][15];

int main()
{
	scanf("%d", &N);
	for (int k = 1; k <= N; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			scanf("%s", picture[k][i]);
		}
    }
    //두개씩 짝지어서(n^2) 비교
	for (int k = 1; k <= N; k++)
	{
		for (int l = k + 1; l <= N; l++)
		{
			int count = 0;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					if (picture[k][i][j] != picture[l][i][j])
					{
						count++;
					}
				}
			}
			if (result > count)
			{
				result = count;
				resulta = k;
				resultb = l;
			}
		}
	}
	printf("%d %d", resulta, resultb);
}