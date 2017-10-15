#include <cstdio>
#include <iostream>
using namespace std;
int N, memo[25][15], result = -1, arr[15], flag;

void func(int depth, int maxdepth, int num)
{
  if(depth == maxdepth)
  {  
    if(result == N)
    {
      for(int i = 0; i < depth; i++)
      {
        flag = 1;
        printf("%d", arr[i]);
      }
    }
    result--;
    return;
  }
  for(int i = num; i >= 0; i--)
  {
    if(flag == 1)
    {
      return;
    }
    arr[depth] = i;
    func(depth + 1, maxdepth, i - 1);
  }
}

int main()
{
  scanf("%d", &N);
  for(int i = 0; i < 10; i++)
  {
    memo[0][i] = 1;
    result++;
    if(result == N)
    {
      printf("%d", i);
      return 0;
    }
  }
  for(int i = 1; i < 20; i++)
  {
    for(int j = 1; j <= 9; j++)
    {
      memo[i][j] = memo[i][j - 1] + memo[i - 1][j - 1];
      result += memo[i][j];
      if(result >= N)
      {
        func(0, i + 1, j);
        return 0;
      }
    }
  }
  printf("-1");
}