#include <cstdio>
#include <iostream>
using namespace std;
int N, M, zone[205][205], city[205], chk[205], Start;

/*
여행 계획 도시들이 하나로 묶여있는지 확인을 하면 된다.
union-find를 이용해서 연결 되어있는 도시들을 하나의 집합으로 묶으면 된다.
*/

//여행 계획 도시들에서 연결 되어있는 도시들 확인
void func(int node)
{
    chk[node] = 1;
    for(int i = 1; i <= N; i++)
    {
        if(zone[node][i] == 1 && chk[i] == 0)
        {
            func(i);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            scanf("%d", &zone[i][j]);
        }
    }
    for(int i = 0; i < M; i++)
    {
        int a;
        scanf("%d", &a);
        city[a] = 1;
        Start = a;
    }
    func(Start);
    for(int i = 1; i <= N; i++)
    {
        //여행 계획 도시인데 연결x도시
        if(chk[i] == 0 && city[i] == 1)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}