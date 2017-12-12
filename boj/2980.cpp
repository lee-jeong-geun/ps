#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, red, green;
}Data;
Data light[105];
int N, L, zone[1005], result, pos;

int main()
{
    scanf("%d %d", &N, &L);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d %d %d", &light[i].x, &light[i].red, &light[i].green);
        zone[light[i].x] = light[i].red * -1;
    }
    while(pos != L)
    {
        if(zone[pos] >= 0)
        {
            pos++;
        }
        for(int i = 1; i <= N; i++)
        {
            if(zone[light[i].x] > 0)
            {
                if(zone[light[i].x] == 1)
                {
                    zone[light[i].x] = light[i].red * -1 + 1;
                }
                zone[light[i].x]--;
            }
            else
            {
                if(zone[light[i].x] == -1)
                {
                    zone[light[i].x] = light[i].green - 1;
                }
                zone[light[i].x]++;
            }
        }
        result++;
    }
    printf("%d", result);
}