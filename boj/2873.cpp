#include <bits/stdc++.h>
using namespace std;
vector<int> result;
int R, C, zone[1005][1005], Min = 987654231, MinR, MinC;
string op = "URDL";

/*
규칙을 잘 보면 행 또는 열이 홀수라면 모든 칸을 방문할 수 있다.
하지만 둘 다 짝수라면 1칸을 빼고 전부 방문할 수 있다.
그 1칸은 행 + 열이 홀수인 칸이면서 최솟값이다.
전체 행을 2개씩 짝지었을 때 빼야 할 1칸이 포함된 짝은 놔두고
그 짝의 전, 후인 행들은 전부 -----> 
                                |
                           <------
이런 식으로 탐색을 하면 된다.
빼야 할 1칸이 존재하는 곳은 |x|-> |->  
                          --> |-> |
이렇게 x를 제외하고 탐색하면 된다.
*/

void func(int dir, int start, int end)
{
    for(int i = start; i < end; i++)
    {
        for(int j = 1; j < C; j++)
        {
            result.push_back(dir);
        }
        dir = (dir + 2) % 4;
        result.push_back(2);
    }
}

int main()
{
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            scanf("%d", &zone[i][j]);
            if((i + j) % 2 == 1 && Min > zone[i][j])
            {
                Min = zone[i][j];
                MinR = i;
                MinC = j;
            }
        }
    }
    if(R % 2 == 1)
        func(1, 0, R);
    else if(C % 2 == 1)
    {
        int dir = 2;
        for(int i = 0; i < C; i++)
        {
            for(int j = 1; j < R; j++)
            {
                result.push_back(dir);
            }
            dir = (dir + 2) % 4;
            result.push_back(1);
        }
    }
    else
    {
        int dir, tempR;
        tempR = MinR / 2 * 2;
        func(1, 0, tempR);
        dir = 2;
        for(int i = 0; i < MinC; i++)
        {
            result.push_back(dir);
            result.push_back(1);
            dir = (dir + 2) % 4;
        }
        for(int i = MinC + 1; i < C; i++)
        {
            result.push_back(1);
            result.push_back(dir);
            dir = (dir + 2) % 4;
        }
        result.push_back(2);
        func(3, tempR + 2, R);
    }
    for(int i = 0; i < result.size() - 1; i++)
    {
        printf("%c", op[result[i]]);
    }
}