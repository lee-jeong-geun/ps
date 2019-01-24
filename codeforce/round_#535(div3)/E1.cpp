#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int start;
    int end;
    int idx;
}Data;
Data Line[305];
int n, m, Num[305], tNum[305], result, resultNum[305], rIdx;
int Max = -987654321;
int Min = 987654321;

/*
세그먼트들을 정렬 시킨 후 완전탐색을 이용하여 쿼리들을 하나씩 하나씩 실행 시키면서 
최대값을 갱신해주면 된다.
*/

//정렬 조건
bool comp(Data &t, Data &u)
{
    if(t.start == u.start)
    {
        if(t.end == u.end)
        {
            return t.idx < u.idx;
        }
        return t.end < u.end;
    }
    return t.start < u.start;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Num[i]);
        Max = max(Max, Num[i]);
        Min = min(Min, Num[i]);
        tNum[i] = Num[i];
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &Line[i].start, &Line[i].end);
        Line[i].start--;
        Line[i].end--;
        Line[i].idx = i + 1;
    }
    sort(Line, Line + m, comp);
    result = Max - Min;
    for(int i = 0; i < m; i++)
    {
        //초기화
        for(int j = 0; j < n; j++)
        {
            Num[j] = tNum[j];
        }
        for(int j = i; j < m; j++)
        {
            Max = -987654321;
            Min = 987654321;
            //구간의 값들 1감소
            for(int k = Line[j].start; k <= Line[j].end; k++)
            {
                Num[k]--;
            }
            for(int k = 0; k < n; k++)
            {
                Max = max(Max, Num[k]);
                Min = min(Min, Num[k]);
            }
            if(result < Max - Min)
            {
                result = Max - Min;
                rIdx = 0;
                for(int k = i; k <= j; k++)
                {
                    resultNum[rIdx++] = Line[k].idx;
                }
            }
        }
    }
    printf("%d\n", result);
    printf("%d\n", rIdx);
    for(int i = 0; i < rIdx; i++)
    {
        printf("%d ", resultNum[i]);
    }
}