#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, y, pointer;
}Data;
Data Robot[105];
int A, B, N, M;
int arrA[4] = {0, 1, 0, -1};
int arrB[4] = {1, 0, -1, 0};

bool range(int a, int b)
{
    if(a >= 1 && a <= A && b >= 1 && b <= B)
    {
        return 1;
    }
    return 0;
}

int main()
{
    scanf("%d %d %d %d", &A, &B, &N, &M);
    for(int i = 1; i <= N; i++)
    {
        char p;
        scanf("%d %d %c", &Robot[i].x, &Robot[i].y, &p);
        if(p == 'N')
        {
            Robot[i].pointer = 0;
        }
        else if(p == 'E')
        {
            Robot[i].pointer = 1;
        }
        else if(p == 'S')
        {
            Robot[i].pointer = 2;
        }
        else
        {
            Robot[i].pointer = 3;
        }
    }
    for(int testcase = 0; testcase < M; testcase++)
    {
        int r, num;
        char op;
        scanf("%d %c %d", &r, &op, &num);
        if(op == 'F')
        {
            for(int i = 0; i < num; i++)
            {
                Robot[r].x += arrA[Robot[r].pointer];
                Robot[r].y += arrB[Robot[r].pointer];
                if(range(Robot[r].x, Robot[r].y) == 0)
                {
                    printf("Robot %d crashes into the wall", r);
                    return 0;
                }
                for(int j = 1; j <= N; j++)
                {
                    if(j != r)
                    {
                        if(Robot[r].x == Robot[j].x && Robot[r].y == Robot[j].y)
                        {
                            printf("Robot %d crashes into robot %d", r, j);
                            return 0;
                        }
                    }
                }
            }
        }
        else
        {
            if(op == 'R')
            {
                Robot[r].pointer = (Robot[r].pointer + (num % 4)) % 4;
            }
            else
            {
                Robot[r].pointer = (Robot[r].pointer - (num % 4) + 4) % 4;
            }
        }
    }
    printf("OK");
}