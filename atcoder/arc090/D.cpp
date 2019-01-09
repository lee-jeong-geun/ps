#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef struct _data
{
    int node;
    int weight;
}Data;
vector<Data> vec[100005];
int N, M, chk[100005], dist[100005], result;

/*
Li와 Ri에 대해서 Li -> Ri 가중치 D 이런식으로 간선을 만들어주면 그래프화 시킬수 있다.
처음에 생각했던건 이런식으로 연결하면 어떤 노드에 대해서 들어오는 간선이 하나도 없을수 있다.
물론 이러한 간선이 하나도 없는 경우는 모순이 되는 경우이다. ex (a -> b, b -> c, c -> a)
이런 노드를 찾아서 위상정렬을 이용하여 가중치를 계속 더해가는 방식으로 하였다.
다음 노드를 이미 방문한 상태일때 현재 노드까지 가중치 합과 다음 노드의 가중치 합이
다음 노드에 저장된 합이랑 다른 경우는 모순이 되는 경우이다. 그리고 다 돌면 가중치들을 초기화 시키고
들어오는 간선이 없는 다른 노드를 찾아서 이 방식을 계속 수행한다. 이렇게 할 경우 가까스로 통과된다.
이제 좀더 최적인 방법은 아까 Li -> Ri 가중치 D에다 Ri -> Li 가중치 -D인 간선을 추가하는 방법이다.
이 방식은 기존의 들어오는 간선이 없는 노드를 찾아 다돌고 가중치를 초기화 시키는 방식을 없앨 수 있다.
음의 가중치를 추가 함으로써 사이클을 발생시켜 해당 사이클을 한번 다 돌았을때 가중치 합이 0으로 되는지 안되는지
판단이 가능해진다. 여기서 0이 된다는것은 다시 처음 시점으로 되돌아 온다는 것이다.
만약 0이 되지 않는다면 모순이 발생한 경우이다.
*/

void BFS()
{
    queue<Data> q;
    for(int j = 1; j <= N; j++)
    {
        //한번도 방문 하지 않는 점
        if(chk[j] == 0)
        {
            chk[j] = 1;
            q.push({j, 0});
        }
        while(!q.empty())
        {
            Data temp;
            temp = q.front();
            q.pop();
            for(int i = 0; i < vec[temp.node].size(); i++)
            {
                Data next;
                next.node = vec[temp.node][i].node;
                next.weight = temp.weight + vec[temp.node][i].weight;
                //다음 노드를 한번도 방문 하지 않음
                if(chk[next.node] == 0)
                {
                    chk[next.node] = 1;
                    dist[next.node] = next.weight;
                    q.push(next);
                }
                //한번이라도 방문
                else
                {
                    //가중치 합이 다르면 모순
                    if(dist[next.node] != next.weight)
                    {
                        result = 1;
                        return;
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        int l, r, d;
        scanf("%d %d %d", &l, &r, &d);
        vec[l].push_back({r, d});
        vec[r].push_back({l, -d});
    }
    BFS();
    result == 0 ? printf("Yes") : printf("No");
}