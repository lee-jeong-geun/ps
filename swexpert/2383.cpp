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
        for(int i = 0; i < (1 << hcount); i++)
        {
            int zeromax = 0, onemax = 0;
            zerocount = 0;
            onecount = 0;
            for(int j = 0; j < hcount; j++)
            {
                if(((1 << j) & i) == 0)
                {
                    exitzero[zerocount++] = abs(Human[j].x - Exit[0].x) + abs(Human[j].y - Exit[0].y);
                }
                else
                {
                    exitone[onecount++] = abs(Human[j].x - Exit[1].x) + abs(Human[j].y - Exit[1].y);
                }
            }
            sort(exitzero, 0, zerocount - 1);
            sort(exitone, 0, onecount - 1);
            for(int j = 0; j < zerocount; j++)
            {
                if(j < 3)
                {
                    exitzero[j] += zone[Exit[0].y][Exit[0].x] + 1;
                }
                else
                {
                    if(exitzero[j - 3] <= exitzero[j])
                    {
                        exitzero[j] += zone[Exit[0].y][Exit[0].x] + 1;
                    }
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