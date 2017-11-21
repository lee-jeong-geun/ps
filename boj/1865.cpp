#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef struct _data
{
    int start;
    int end;
    int weight;
}Data;
vector<Data>vec;
int N, M, W, dist[505];

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        vec.clear();
        int flag = 0;
        scanf("%d %d %d", &N, &M, &W);
        for(int i = 0; i < M; i++)
        {
            int s, e, w;
            scanf("%d %d %d", &s, &e, &w);
            vec.push_back({s, e, w});
            vec.push_back({e, s, w});
        }
        for(int i = 0; i < W; i++)
        {
            int s, e, w;
            scanf("%d %d %d", &s, &e, &w);
            vec.push_back({s, e, -w});
        }
        for(int i = 0; i < 505; i++)
        {
            dist[i] = 987654321;
        }
        dist[1] = 0;
        for(int i = 1; i <= N; i++)
        {
            for(int j = 0; j < M * 2 + W; j++)
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
        if(flag == 0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
}