#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef struct _data
{
    int x, y;
}Data;
int N, chk[305][305], result;
char zone[305][305];
int arrA[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int arrB[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
 
/*
가장 최소의 버튼을 누르는 건 주변에 지뢰가 한개도 없는 부분을 최대한 많이 누르는 것이다.
8방향에 지뢰가 한개도 없는 땅을 클릭후 그 땅의 8개 방향에 있는 땅에서도 확인을 한다.
계속 이렇게 퍼져 나가듯이 탐색을 하기 위해서는 flood fill(BFS) 알고리즘을 이용하면 된다.
처음에 맵 전체를 탐색하면서 8방향에 지뢰가 한개도 없는 땅들을 모조리 BFS를 탄다.
그렇게 하면 남는 땅들이 있는데 남는 땅들은 주위에 지뢰가 있어서 무조건 1번씩 클릭 해야되는 땅이다.
BFS를 탄 횟수와 남는 땅들의 개수를 더해주면 답을 찾을수 있다.
*/

void init()
{
    memset(chk, 0, sizeof chk);
    result = 0;
}

//맵 안에 있는지 확인
bool range(int a, int b)
{
    if(a >= 0 && a < N && b >= 0 && b < N)
    {
        return 1;
    }
    return 0;
}

//8방향에 지뢰가 있는지 확인
bool minechk(int x, int y)
{
    for(int i = 0; i < 8; i++)
    {
        if(zone[y + arrB[i]][x + arrA[i]] == '*')
        {
            return 1;
        }
    }
    return 0;
}
 
void BFS(int x, int y)
{
    queue<Data>q;
    q.push({x, y});
    chk[y][x] = 1;
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        if(minechk(temp.x, temp.y) == 1)
        {
            continue;
        }
        //8방향에 지뢰가 없으면 큐에 푸쉬
        for(int i = 0; i < 8; i++)
        {
            Data next;
            next.x = temp.x + arrA[i];
            next.y = temp.y + arrB[i];
            if(range(next.x, next.y) == 1 && chk[next.y][next.x] == 0)
            {
                chk[next.y][next.x] = 1;
                q.push(next);
            }
        }
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
                scanf(" %c", &zone[i][j]);
            }
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(zone[i][j] == '*')
                {
                    continue;
                }
                //8방향에 지뢰가 없으면 BFS
                if(minechk(j, i) == 0 && chk[i][j] == 0)
                {
                    result++;
                    BFS(j, i);
                }
            }
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                //남는 땅들 개수 세줌
                if(zone[i][j] == '.' && chk[i][j] == 0)
                {
                    result++;
                }
            }
        }
        printf("#%d %d\n", testcase, result);
    }
}