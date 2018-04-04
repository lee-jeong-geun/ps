#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int N, zone[1005][1005], memo[1000005], Max, result;
int arrA[4] = {0, 1, 0, -1};
int arrB[4] = {-1, 0, 1, 0};

/*
1씩 차이나는걸 4방향으로 계속 찾으면 된다.
모든 배열의 원소 값은 유일하므로 한번 탐색했던 곳은 메모이제이션을 이용해서 값 만 받고 그곳을
다시 탐색 할 필요가 없다. 그리고 1000 * 1000이 최대이므로 재귀 함수를 이용할 시 최악의 경우에 1000 * 1000을 
한번에 탐색하게 되어서 스택 오버 플로우가 일어날 수 있다. 그래서 재귀 함수 말고 반복문으로 탐색을 하였다.
*/

void init()
{
    memset(memo, -1, sizeof memo);
    Max = 0;
    result = 0;
}

void func(int x, int y)
{
    int tx, ty, flag = 0, count = 1;
    tx = x;
    ty = y;
    while(1)
    {
        flag = 0;
        for(int i = 0; i < 4; i++)
        {
            //현재 위치보다 1클 경우
            if(zone[ty][tx] == zone[ty + arrB[i]][tx + arrA[i]] - 1)
            {
                //이미 탐색한 곳일 경우
                if(memo[zone[ty + arrB[i]][tx + arrA[i]]] != -1)
                {
                    //값만 더해줌
                    count += memo[zone[ty + arrB[i]][tx + arrA[i]]];
                }
                else
                {
                    //탐색 표시를 함
                    memo[zone[ty + arrB[i]][tx + arrA[i]]] = 0;
                    count++;
                    flag = 1;
                    tx += arrA[i];
                    ty += arrB[i];
                }
                break;
            }
        }
        //1큰걸 못 찾았을 경우 빠져 나감
        if(flag == 0)
        {
            break;
        }
    }
    //현재 위치에 값을 넣어줌
    memo[zone[y][x]] = count;
    //최대값 갱신
    if(Max < count)
    {
        Max = count;
        result = zone[y][x];
    }
    //최대값 같으면 수가 더 작은걸 취함
    else if(Max == count && result > zone[y][x])
    {
        result = zone[y][x];
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
            }
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                //한번도 가지 않은 곳이라면 탐색
                if(memo[zone[i][j]] == -1)
                {
                    func(j, i);
                }
            }
        }
        printf("#%d %d %d\n", testcase, result, Max);
    }
}