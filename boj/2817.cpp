#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int idx;
    int num;
}Data;
Data point[145];
int X, N, score[30], chk[30], result[30], pIdx;

/*
주어진 조건에 맞게 구현하면 된다.
*/

bool comp(Data &t, Data &u)
{
    return t.num > u.num;
}

int main()
{
    scanf("%d %d", &X, &N);
    for(int i = 0; i < N; i++)
    {
        int num;
        char staff;
        scanf(" %c %d", &staff, &num);
        score[staff - 'A'] = num;
        chk[staff - 'A'] = 1;
        //5% 미만 스태프
        if(X * 5 / 100 > num)
        {
            chk[staff - 'A'] = 2;
            continue;
        }
        for(int j = 1; j <= 14; j++)
        {
            point[pIdx].idx = staff - 'A';
            point[pIdx++].num = num / j;
        }
    }
    sort(point, point + (14 * N), comp);
    for(int i = 0; i < 14; i++)
    {
        result[point[i].idx]++;
    }
    for(int i = 0; i < 26; i++)
    {
        if(chk[i] == 1)
        {
            printf("%c %d\n", i + 'A', result[i]);
        }
    }
}