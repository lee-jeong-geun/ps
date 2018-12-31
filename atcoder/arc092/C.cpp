#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int x, y;
}Data;
Data red[105], blue[105];
int N, result, chk[105];

/*
처음에 DP로 접근하였지만 테이블 짜기가 어려워서 정렬 후 그리디 방식으로 접근하였다.
파란색 점들을 x좌표 오름차순 y좌표 오름차순으로 정렬 후
빨간색 점들을 파란색점들에게 대조하는 방식으로 하였다. 한개의 파란색점에 여러개의 빨간색 점들이
포함되는 경우 이중에서 y좌표가 가장 높은 빨간색점으로 매칭 시켰다.
그 이유는 매칭되는 빨간색점들은 다음번째 파란색점에도 x좌표가 작기 때문에 y좌표를 제외한다면 무조건
매칭이 된다. 다음번째 파란색점의 y좌표는 현재보다 크거나 작을수도 있는데 크다면 상관없지만 작다면 
빨간색점에서 y좌표가 작은것을 현재 파란색점에 매칭 시켰을 경우 다음 파란색점에 매칭이 안될 수 있기 때문이다.
따라서 가장 큰 y좌표를 매칭 시켜야 다음 파란색점들에 대하여 빨간색 점이 매칭 될 가능성이 생기게 된다.
*/

bool comp(Data t, Data u)
{
    if(t.x == u.x)
    {
        return t.y < u.y;
    }
    return t.x < u.x;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &red[i].x, &red[i].y);
    }
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &blue[i].x, &blue[i].y);
    }
    //파란색 점 정렬
    sort(blue, blue + N, comp);
    for(int i = 0; i < N; i++)
    {
        int Max, Maxidx;
        Max = -1;
        Maxidx = -1;
        for(int j = 0; j < N; j++)
        {
            //매치가 안된 빨간색 점들중 파란색점에 포함 되는 경우
            if(chk[j] == 0 && red[j].x < blue[i].x && red[j].y < blue[i].y)
            {
                //y좌표가 가장 큰 빨간색점 저장
                if(Max < red[j].y)
                {
                    Max = red[j].y;
                    Maxidx = j;
                }
            }
        }
        //매칭 되는게 하나라도 있는 경우
        if(Maxidx != -1)
        {
            chk[Maxidx] = 1;
            result++;
        }
    }
    printf("%d", result);
}