#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int v, d;
}Data;
Data stone[5];
int w, h;

/*
조건에 맞게 시뮬레이션 하면 된다.
*/

int main()
{
    scanf("%d %d", &w, &h);
    for(int i = 0; i < 2; i++)
    {
        scanf("%d %d", &stone[i].v, &stone[i].d);
    }
    //높이가 더 높은 바위의 인덱스를 앞으로 위치시킴
    if(stone[0].d < stone[1].d)
    {
        stone[2] = stone[0];
        stone[0] = stone[1];
        stone[1] = stone[2];
    }
    int idx = 0;
    for(int i = h; i >= 0; i--)
    {
        w += i;
        if(stone[idx].d == i)
        {
            w -= stone[idx++].v;
        }
        if(w < 0)
        {
            w = 0;
        }
    }
    printf("%d", w);
}