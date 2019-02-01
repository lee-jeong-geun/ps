#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int num;
    int idx;
}Data;
Data Num[15];
int result, chk[15];

/*
주어진 조건에 맞게 구현 하면 된다.
*/

bool comp(Data &t, Data &u)
{
    if(t.num == u.num)
    {
        return t.idx < u.idx;
    }
    return t.num > u.num;
}

int main()
{
    for(int i = 0; i < 8; i++)
    {
        scanf("%d", &Num[i].num);
        Num[i].idx = i + 1;
    }
    sort(Num, Num + 8, comp);
    for(int i = 0; i < 5; i++)
    {
        chk[Num[i].idx] = 1;
        result += Num[i].num;
    }
    printf("%d\n", result);
    for(int i = 1; i < 10; i++)
    {
        if(chk[i] == 1)
        {
            printf("%d ", i);
        }
    }
}