#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct _data
{
    int x;
    int y;
}Data;
Data Home[105], Chicken[15], chk[15];
int N, M, Hidx, Cidx, result = 987654321;

/*
치킨집을 M개 고르고 각각의 집들에서 M개의 치킨집중에 가장 짧은 거리를 찾도록 탐색하고 그 값들을
다 더한 후 최소값을 갱신해 주면 된다.
*/

//M개의 치킨집 선택
void func(int depth, int idx)
{
    if(depth == M)
    {
        int hap = 0;
        //각각의 집에서 치킨 거리 탐색
        for(int i = 0 ; i < Hidx; i++)
        {
            int count = 987654321;
            for(int j = 0; j < depth; j++)
            {
                count = min(count, abs(Home[i].x - chk[j].x) + abs(Home[i].y - chk[j].y));   
            }
            hap += count;
        }
        result = min(result, hap);
        return;
    }
    for(int i = idx + 1; i < Cidx; i++)
    {
        chk[depth].x = Chicken[i].x;
        chk[depth].y = Chicken[i].y;
        func(depth + 1, i);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int num;
            scanf("%d", &num);
            if(num == 1)
            {
                Home[Hidx].x = j;
                Home[Hidx++].y = i;
            }
            else if(num == 2)
            {
                Chicken[Cidx].x = j;
                Chicken[Cidx++].y = i;
            }
        }
    }
    func(0, -1);
    printf("%d", result);
}