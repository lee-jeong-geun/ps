#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int team;
    int sub[105];
    int score;
    int sm;
    int last;
}Data;
Data Team[105];
int n, k, t, m;

bool comp(Data t, Data u)
{
    if(t.score == u.score)
    {
        if(t.sm == u.sm)
        {
            return t.last < u.last;
        }
        return t.sm < u.sm;
    }
    return t.score > u.score;
}

void sort(Data *arr, int left, int right)
{
    int leftidx, rightidx;
    Data pivot;
    leftidx = left;
    rightidx = right;
    pivot = arr[(left + right) / 2];
    while(leftidx <= rightidx)
    {
        while(comp(arr[leftidx], pivot))
        {
            leftidx++;
        }
        while(comp(pivot, arr[rightidx]))
        {
            rightidx--;
        }
        if(leftidx <= rightidx)
        {
            Data temp;
            temp = arr[leftidx];
            arr[leftidx] = arr[rightidx];
            arr[rightidx] = temp;
            leftidx++;
            rightidx--;
        }
    }
    if(left < rightidx)
    {
        sort(arr, left, rightidx);
    }
    if(leftidx < right)
    {
        sort(arr, leftidx, right);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        scanf("%d %d %d %d", &n, &k, &t, &m);
        for(int i = 1; i <= n; i++)
        {
            Team[i].team = i;
            for(int j = 1; j <= k; j++)
            {
                Team[i].sub[j] = 0;
            }
            Team[i].score = 0;
            Team[i].sm = 0;
            Team[i].last = 0;
        }
        for(int i = 1; i <= m; i++)
        {
            int ID, J, S;
            scanf("%d %d %d", &ID, &J, &S);
            if(Team[ID].sub[J] < S)
            {
                Team[ID].score += S - Team[ID].sub[J];
                Team[ID].sub[J] = S;
            }
            Team[ID].sm++;
            Team[ID].last = i;
        }
        sort(Team, 1, n);
        for(int i = 1; i <= n; i++)
        {
            if(Team[i].team == t)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
}