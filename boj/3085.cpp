#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, result;
char zone[55][55];
int arrA[2] = {1, 0};
int arrB[2] = {0, 1};

/*
맵 전체에 대해서 각 좌표당 좌우, 상하를 스왑하고 스왑한 라인에 대해서만 검사를 하면된다.
좌표당 스왑 후 맵 전체를 검사 안해도 되는 이유가 어차피 탐색을 맵 전체에 대해서 하기 때문이다.
*/

void swap(char &a, char &b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}

//스왑 후 해당 라인 탐색
void linesearch(int x, int y, int dir)
{
    int count = 1, tx = 0, ty = 0;
    //가로 탐색
    if(dir == 0)
    {
        ty = y;
    }
    //세로 탐색
    else
    {
        tx = x;
    }
    for(int i = 0; i < N - 1; i++)
    {
        int nextx, nexty;
        nextx = tx + arrA[dir];
        nexty = ty + arrB[dir];
        //다음 좌표랑 같을경우
        if(zone[ty][tx] == zone[nexty][nextx])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        result = max(result, count);
        tx = nextx;
        ty = nexty;
    }
}

void Search(int x, int y, int dir)
{
    linesearch(x, y, 0);
    linesearch(x, y, 1);
    //가로 스왑 했을 경우
    if(dir == 0)
    {
        linesearch(x + 1, y, 1);
    }
    //세로 스왑 했을 경우
    else
    {
        linesearch(x, y + 1, 0);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%s", zone[i]);
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < 2; k++)
            {
                int nextx, nexty;
                nextx = j + arrA[k];
                nexty = i + arrB[k];
                if(nextx < N && nexty < N)
                {
                    swap(zone[i][j], zone[nexty][nextx]);
                    Search(j, i, k);
                    //스왑후 다시 스왑하면 원상태로 복구 됨
                    swap(zone[i][j], zone[nexty][nextx]);    
                }
            }
        }
    }
    printf("%d", result);
}