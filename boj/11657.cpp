#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef struct _data
{
    int start;
    int end;
    int weight;
}Data;
vector<Data>vec;
int N, M, dist[505], flag;

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        vec.push_back({s, e, w});
    }
    for(int i = 0; i < 505; i++)
    {
        dist[i] = 987654321;
    }
    dist[1] = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(dist[vec[j].start] == 987654321)
            {
                continue;
            }
            if(dist[vec[j].end] > dist[vec[j].start] + vec[j].weight)
            {
                dist[vec[j].end] = dist[vec[j].start] + vec[j].weight;
                if(i == N)
                {
                    flag = 1;
                }
            }
        }
    }
    if(flag == 1 || N == 1)
    {
        printf("-1");
    }
    else
    {
        for(int i = 2; i <= N; i++)
        {
            if(dist[i] == 987654321)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", dist[i]);
            }
        }
    }
}