#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef struct _data
{
  int x, y;
}Data;
int M, N, K, zone[55][55], chk[55][55], result;
int arrA[4] = {0, 0, 1, -1};
int arrB[4] = {1, -1, 0, 0};

int range(int a, int b)
{
  if(a >= 0 && a < M && b >= 0 && b < N)
  {
    return 1;
  }
  return 0;
}

void init()
{
  result = 0;
  memset(chk, 0, sizeof chk);
  memset(zone, 0, sizeof zone);
}

void BFS(int x, int y)
{
  queue<Data>q;
  q.push({x, y});
  while(!q.empty())
  {
    Data temp;
    temp = q.front();
    q.pop();
    for(int i = 0; i < 4; i++)
    {
      Data next;
      next.x = temp.x + arrA[i];
      next.y = temp.y + arrB[i];
      if(range(next.x, next.y) == 1 && zone[next.y][next.x] == 1 && chk[next.y][next.x] == 0)
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
  for(int testcase = 0; testcase < T; testcase++)
  {
    init();
    scanf("%d %d %d", &M, &N, &K);
    for(int i = 0; i < K; i++)
    {
      int x, y;
      scanf("%d %d", &x, &y);
      zone[y][x] = 1;
    }
    for(int i = 0; i < N; i++)
    {
      for(int j = 0; j < M; j++)
      {
        if(zone[i][j] == 1 && chk[i][j] == 0)
        {
          chk[i][j] = 1;
          result++;
          BFS(j, i);
        }
      }
    }
    printf("%d\n", result);
  }
}