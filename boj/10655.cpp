#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
typedef struct _data
{
    int x;
    int y;
}Data;
Data point[100005];
int N, Sum, result = 987654321;

/*
부분합을 이용하여 모든 거리를 다 더한 후 뺄 체크 포인트의 양옆을 다 더한 값에서 빼주고
체크 포인트의 앞과 뒤의 거리를 더해준 값중에서 최소값을 찾으면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &point[i].x, &point[i].y);
        if(i != 0)
        {
            //전부 더함
            Sum += abs(point[i].x - point[i - 1].x) + abs(point[i].y - point[i - 1].y);
        }
    }
    for(int i = 1; i < N - 1; i++)
    {
        int temp;
        //해당 체크포인트와 앞의 포인트를 뺌
        temp = Sum - abs(point[i].x - point[i - 1].x) - abs(point[i].y - point[i - 1].y);
        //해당 체크포인트와 뒤의 포인트를 뺌
        temp += -abs(point[i].x - point[i + 1].x) - abs(point[i].y - point[i + 1].y);
        //체크포인트 앞 뒤를 연결
        temp += abs(point[i + 1].x - point[i - 1].x) + abs(point[i + 1].y - point[i - 1].y);
        result = min(result, temp);
    }
    printf("%d", result);
}