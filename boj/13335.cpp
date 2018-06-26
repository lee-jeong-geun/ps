#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int n, w, L, truck[1005], result, Cur, weight, idx;

/*
트럭들이 다리에 올라간 것을 큐에 넣는것으로 생각하면 된다.
큐에는 각각의 트럭들이 몇초에 다리를 건너는지 시간을 넣어주면 된다.
큐에 넣어줄때 트럭들의 무게의 합을 계속 확인하면서 넣을수 있을때 넣으면 된다.
*/

int main()
{
    queue<int> q;
    scanf("%d %d %d", &n, &w, &L);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &truck[i]);
    }
    //맨 첫번째 트럭 푸쉬
    q.push(w + 1);
    weight = truck[0];
    idx = 1;
    for(int i = 2; ; i++)
    {
        int temp;
        temp = q.front();
        //트럭 도착 시간일 경우
        if(temp == i)
        {
            //도착한 트럭 무게 빼줌
            weight -= truck[Cur];
            q.pop();
            //다음 트럭으로 인덱스 바꿔줌
            Cur++;
            //트럭들이 다 도착했을 경우
            if(Cur == n)
            {
                printf("%d", i);
                break;
            }
        }
        //트럭을 다리에 더 올릴 수 있을 경우
        if(idx < n && weight + truck[idx] <= L)
        {
            weight += truck[idx++];
            q.push(i + w);
        }
    }
}