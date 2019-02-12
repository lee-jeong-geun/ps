#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
priority_queue<int> minX, maxX, minY, maxY;
int N, M, rx, ry;
long long resultX, resultY;
int arrX[30];
int arrY[30];

/*
처음에 모든 점에서 원점으로 가는 거리의 합을 구하고 X좌표와 Y좌표로 나누어서 힙을 이용하여
0 이상인것들은 min힙에 저장, 0미만인 것들은 max힙에 저장 한다. 로봇이 이동 할 경우
로봇의 X좌표에서 멀어지는 것들의 개수만큼 거리에 증가 시키고 가까워 지는 것들의 개수만큼
거리에서 빼주면 된다. 이렇게 하면서 힙을 계속 갱신 시키면 된다.
*/

int main()
{
    arrX['I' - 'A'] = 1;
    arrX['Z' - 'A'] = -1;
    arrY['S' - 'A'] = 1;
    arrY['J' - 'A'] = -1;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        //힙에 push
        rx <= x ? minX.push(-x) : maxX.push(x);
        ry <= y ? minY.push(-y) : maxY.push(y);
        resultX += abs(rx - x);
        resultY += abs(ry - y);
    }
    for(int i = 0; i < M; i++)
    {
        char op;
        scanf(" %c", &op);
        rx += arrX[op - 'A'];
        ry += arrY[op - 'A'];
        //북쪽 이동
        if(op == 'S')
        {
            //이동한 로봇의 y좌표보다 작은 것이 있는 경우 max힙으로 이동
            while(!minY.empty())
            {
                int temp;
                temp = -minY.top();
                if(ry <= temp)
                {
                    break;
                }
                minY.pop();
                maxY.push(temp);
            }
            //로봇이 이동한 y좌표에서 멀어지는 것들을 더하고 가까워지는 것들을 뺌
            resultY = resultY - minY.size() + maxY.size();
        }
        if(op == 'J')
        {
            resultY = resultY + minY.size() - maxY.size();
            while(!maxY.empty())
            {
                int temp;
                temp = maxY.top();
                if(ry > temp)
                {
                    break;
                }
                maxY.pop();
                minY.push(-temp);
            }
        }
        if(op == 'I')
        {
            while(!minX.empty())
            {
                int temp;
                temp = -minX.top();
                if(rx <= temp)
                {
                    break;
                }
                minX.pop();
                maxX.push(temp);
            }
            resultX = resultX - minX.size() + maxX.size();
        }
        if(op == 'Z')
        {
            resultX = resultX + minX.size() - maxX.size();
            while(!maxX.empty())
            {
                int temp;
                temp = maxX.top();
                if(rx > temp)
                {
                    break;
                }
                maxX.pop();
                minX.push(-temp);
            }
        }
        printf("%lld\n", resultX + resultY);
    }
}