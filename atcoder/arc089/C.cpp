#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int time;
    int x;
    int y;
}Data;
Data point[100005];
int N, sx, sy, Time, result;
char word[2][5] = {"Yes", "No"};

/*
현재 위치에서 다음 위치로 갈때 시간이 안되거나 남는 시간이 있을때 홀수라면 못가는 경우다.
*/

int abs(int num)
{
    return num > 0 ? num : -num;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &point[i].time, &point[i].x, &point[i].y);
    }
    for(int i = 0; i < N; i++)
    {
        int dis;
        dis = abs(sx - point[i].x) + abs(sy - point[i].y);
        //시간이 안되는 경우
        if(dis > point[i].time - Time)
        {
            result = 1;
            break;
        }
        //남는 시간이 홀수인 경우
        else if(dis < point[i].time - Time && (point[i].time - Time - dis) % 2 == 1)
        {
            result = 1;
            break;
        }
        Time = point[i].time;
        sx = point[i].x;
        sy = point[i].y;
    }
    printf("%s", word[result]);
}