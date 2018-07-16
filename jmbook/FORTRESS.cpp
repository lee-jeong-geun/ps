#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int x, y, r;
}Data;
vector<int>vec[105];
Data circle[105];
int N, result;

bool operator < (Data t, Data u)
{
    return t.r > u.r;
}

int sqr(int a)
{
    return a * a;
}

int chk(Data a, Data b)
{
    if(sqr(a.x - b.x) + sqr(a.y - b.y) < sqr(a.r - b.r))
    {
        return 1;
    }
    return 0;
}

int func(int node)
{
    int Max1 = 0, Max2 = 0;
    for(int i = 0; i < vec[node].size(); i++)
    {
        int temp;
        temp = func(vec[node][i]) + 1;
        if(Max1 < temp)
        {
            Max2 = Max1;
            Max1 = temp;
        }
        else if(Max2 < temp)
        {
            Max2 = temp;
        }
    }
    result = max(result, Max1 + Max2);
    return Max1;
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        result = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%d %d %d", &circle[i].x, &circle[i].y, &circle[i].r);
            vec[i].clear();
        }
        sort(circle, circle  + N);
        for(int i = 1; i < N; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(chk(circle[i], circle[j]) == 1)
                {
                    vec[j].push_back(i);
                    break;
                }
            }
        }
        func(0);
        printf("%d\n", result);
    }
}