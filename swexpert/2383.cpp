#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int x, y;
}Data;
Data Exit[5], Human[15];
int N, zone[15][15], excount, hcount, exitzero[15], exitone[15], zerocount, onecount, result;

/*
사람들은 1번 계단을 가든 2번 계단을 가든 무조건 선택 해야한다.
그리고 계단은 한번에 3명 까지만 이용할 수 있기 때문에 3명을 다 수용한 상태에서 그다음 사람이
도착하는 시간은 계단을 이용하는 3명중에서 가장 빨리 도착하는 사람의 시간 + 그 사람이 계단을 내려오는 시간이다.
*/

void init()
{
    excount = 0;
    hcount = 0;
    result = 987654321;
}

int abs(int a)
{
    return a >= 0 ? a : a * -1;
}

//퀵정렬
void sort(int *arr, int left, int right)
{
    int leftidx, rightidx, pivot;
    leftidx = left;
    rightidx = right;
    pivot = arr[(left + right) / 2];
    while(leftidx <= rightidx)
    {
        while(arr[leftidx] < pivot)
        {
            leftidx++;
        }
        while(pivot < arr[rightidx])
        {
            rightidx--;
        }
        if(leftidx <= rightidx)
        {
            int temp;
            temp = arr[leftidx];
            arr[leftidx] = arr[rightidx];
            arr[rightidx] = temp;
            leftidx++;
            rightidx--;
        }
    }
    if(leftidx < right)
    {
        sort(arr, leftidx, right);
    }
    if(left < rightidx)
    {
        sort(arr, left, rightidx);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        init();
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                scanf("%d", &zone[i][j]);
                if(zone[i][j] > 1)
                {
                    Exit[excount].x = j;
                    Exit[excount++].y = i;
                }
                else if(zone[i][j] == 1)
                {
                    Human[hcount].x = j;
                    Human[hcount++].y = i;
                }
            }
        }
        //전체 조합
        for(int i = 0; i < (1 << hcount); i++)
        {
            int zeromax = 0, onemax = 0;
            zerocount = 0;
            onecount = 0;
            for(int j = 0; j < hcount; j++)
            {
                //1번 계단 선택
                if(((1 << j) & i) == 0)
                {
                    exitzero[zerocount++] = abs(Human[j].x - Exit[0].x) + abs(Human[j].y - Exit[0].y);
                }
                //2번 계단 선택
                else
                {
                    exitone[onecount++] = abs(Human[j].x - Exit[1].x) + abs(Human[j].y - Exit[1].y);
                }
            }
            //오름차순으로 정렬
            sort(exitzero, 0, zerocount - 1);
            sort(exitone, 0, onecount - 1);
            for(int j = 0; j < zerocount; j++)
            {
                //계단 3명 이용하는게 아니라서 기다리는 시간 없음
                if(j < 3)
                {
                    exitzero[j] += zone[Exit[0].y][Exit[0].x] + 1;
                }
                else
                {
                    //기다리지 않는 경우
                    if(exitzero[j - 3] <= exitzero[j])
                    {
                        exitzero[j] += zone[Exit[0].y][Exit[0].x] + 1;
                    }
                    //기다리는 경우
                    else
                    {
                        exitzero[j] = exitzero[j - 3] + zone[Exit[0].y][Exit[0].x];
                    }
                }
                zeromax = max(zeromax, exitzero[j]);
            }
            for(int j = 0; j < onecount; j++)
            {
                if(j < 3)
                {
                    exitone[j] += zone[Exit[1].y][Exit[1].x] + 1;
                }
                else
                {
                    if(exitone[j - 3] <= exitone[j])
                    {
                        exitone[j] += zone[Exit[1].y][Exit[1].x] + 1;
                    }
                    else
                    {
                        exitone[j] = exitone[j - 3] + zone[Exit[1].y][Exit[1].x];
                    }
                }
                onemax = max(onemax, exitone[j]);
            }
            result = min(result, max(zeromax, onemax));
        }
        printf("#%d %d\n", testcase, result);
    }
}


//나중에 푼것



#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
	int x, y, Time;
}Data;
Data people[15], Exit[5];
int N, zone[15][15], pcount, result, ecount, choice[2][15];

void init()
{
	pcount = 0;
	ecount = 0;
	result = 987654321;
}

int abs(int a)
{
	return a > 0 ? a : -a;
}

int chk(int flag, int count)
{
	int weight[15], ret = 0;
	for (int i = 0; i < count; i++)
	{
		weight[i] = abs(Exit[flag].x - people[choice[flag][i]].x) + abs(Exit[flag].y - people[choice[flag][i]].y);
	}
	sort(weight, weight + count);
	for (int i = 0; i < count; i++)
	{
		if (i < 3)
		{
			ret = Exit[flag].Time + weight[i] + 1;
		}
		else
		{
			if (weight[i - 3] + Exit[flag].Time + 1 > weight[i])
			{
				ret = weight[i - 3] + Exit[flag].Time + 1 + Exit[flag].Time;
			}
			else
			{
				ret = Exit[flag].Time + weight[i] + 1;
			}
		}
	}
	return ret;
}

void func(int depth, int first, int second)
{
	if (depth == pcount)
	{
		result = min(result, max(chk(0, first), chk(1, second)));
		return;
	}
	choice[0][first] = depth;
	func(depth + 1, first + 1, second);
	choice[1][second] = depth;
	func(depth + 1, first, second + 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		init();
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &zone[i][j]);
				if (zone[i][j] == 1)
				{
					people[pcount].x = j;
					people[pcount++].y = i;
				}
				else if(zone[i][j] > 1)
				{
					Exit[ecount].x = j;
					Exit[ecount].y = i;
					Exit[ecount++].Time = zone[i][j];
				}
			}
		}
		func(0, 0, 0);
		printf("#%d %d\n", testcase, result);
	}
}