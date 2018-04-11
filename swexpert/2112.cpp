#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int D, W, K, zone[15][25], result = 987654321;

/*
각 행에 대하여 나올수 있는 가지 수는 3개이고 총 13개의 행이라서
모든 경우의 수는 3 ^ 13개 이다. 가지치기를 이용해서 경우의 수를 확 줄일수 있다.
*/

int schk(int x)
{
    int count = 1, temp = zone[0][x];
    for(int i = 1; i < D; i++)
    {
        if(temp == zone[i][x])
        {
            count++;
            if(count >= K)
            {
                return 1;
            }
        }
        else
        {
            count = 1;
            temp = zone[i][x];
        }
    }
    if(count >= K)
    {
        return 1;
    }
    return 0;
}

void func(int idx, int changecount)
{
    int tempzone[25];
    int chkcount = 0;
    if(idx == D)
    {
        for(int i = 0; i < W; i++)
        {
            int tcount;
            tcount = schk(i);
            if(tcount == 0)
            {
                break;
            }
            chkcount += tcount;
        }
        if(chkcount == W)
        {
            result = min(result, changecount);
        }
        return;
    }
    if(changecount >= result)
    {
        return;
    }
    func(idx + 1, changecount);
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < W; j++)
        {
            tempzone[j] = zone[idx][j];
            zone[idx][j] = i;
        }
        func(idx + 1, changecount + 1);
        for(int j = 0; j < W; j++)
        {
            zone[idx][j] = tempzone[j];
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        result = 987654321;
        scanf("%d %d %d", &D, &W, &K);
        for(int i = 0; i < D; i++)
        {
            for(int j = 0; j < W; j++)
            {
                scanf("%d", &zone[i][j]);
            }
        }
        func(0, 0);
        printf("#%d %d\n", testcase, result);
    }
}




//나중에 푼 것

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int D, W, K, zone[25][25], result;

//성능검사
bool funcchk()
{
	if (K == 1)
	{
		return 1;
	}
	for (int i = 0; i < W; i++)
	{
		int count = 1, flag = 0;
		for (int j = 0; j < D - 1; j++)
		{
			if (zone[j][i] == zone[j + 1][i])
			{
				count++;
				if (count >= K)
				{
					flag = 1;
					break;
				}
			}
			else
			{
				count = 1;
			}
		}
		if (flag == 0)
		{
			return 0;
		}
	}
	return 1;
}

void func(int depth, int count)
{
    //현재 바꾼 횟수가 결과보다 크면 더이상 볼 필요 없음
	if (count >= result)
	{
		return;
	}
	int temp[25];
	if (depth == D)
	{
		if (funcchk() == 1)
		{
			result = min(result, count);
		}
		return;
	}
	func(depth + 1, count);
	for (int i = 0; i < W; i++)
	{
		temp[i] = zone[depth][i];
		zone[depth][i] = 1;
	}
	func(depth + 1, count + 1);
	for (int i = 0; i < W; i++)
	{
		zone[depth][i] = 0;
	}
	func(depth + 1, count + 1);
	for (int i = 0; i < W; i++)
	{
		zone[depth][i] = temp[i];
	}

}

int main()
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		result = 987654321;
		scanf("%d %d %d", &D, &W, &K);
		for (int i = 0; i < D; i++)
		{
			for (int j = 0; j < W; j++)
			{
				scanf("%d", &zone[i][j]);
			}
		}
		func(0, 0);
		printf("#%d %d\n", testcase, result);
	}
}