#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int node;
    int Max;
}Data;
vector<int> vec[200005];
int n, S[200005];
long long result;

/*
각 노드들의 S는 부모 노드의 S보다 무조건 작으면 안된다.
그 이유는 노드들의 a조건이 0이상이기 때문에 음수가 나오지 않는다.
따라서 a가 최소값인 0이라면 부모의 S보다 작을 수가 없다.
S가 -1인 노드는 a가 0이라 생각하고 부모 노드의 S를 넣거나
자식노드들의 S들중 가장 작은 값의 S 둘중 하나라고 생각 할 수 있다.
최소가 되는 a들의 합을 구해야 하므로 가능하면 a값을 적게 주어야 하기 때문에
0을 생각 할 수 있지만 자식노드들의 s에 영향을 주는것이 현재 노드의 a값이기 때문에
자식노드들의 a값을 줄이기 위해서라면 현재 노드의 a값이 0이 되면 안되기 때문이다.
따라서 max(부모노드의 S, min(자식 노드들의 S))를 취해서 현재 노드의 S로 결정 하면 된다.
그리고 탐색은 리프 노드부터 루트 노드로 거슬러 올라가면 중복되는 너무 많기 때문에
루트 노드부터 리프 노드로 BFS를 이용하여 탐색하면 된다.
*/

void BFS()
{
    queue<Data> q;
    q.push({1, S[1]});
    while(!q.empty())
    {
        //자식 노드들의 최소 S저장 변수
        int Min = 1234567890;
        Data temp;
        temp = q.front();
        q.pop();
        //리프 노드일 경우 결과값에 S증가
        if(vec[temp.node].size() == 0)
        {
            result += temp.Max;
        }
        for(int i = 0; i < vec[temp.node].size(); i++)
        {
            int node;
            node = vec[temp.node][i];
            //자식 노드의 S가 정해진 상태일 경우
            if(S[node] != -1)
            {
                Min = min(Min, S[node]);
            }
        }
        //현재 노드의 S가 미정인 경우
        if(S[temp.node] == -1)
        {
            //부모노드로 부터 내려온 S와 자식노드의 S중 큰값을 현재 노드의 S로 저장
            temp.Max = max(temp.Max, Min);
        }
        for(int i = 0; i < vec[temp.node].size(); i++)
        {
            Data next;
            next.node = vec[temp.node][i];
            next.Max = max(temp.Max, S[next.node]);
            //자식 노드의 S가 정해진 상태인데 현재 노드의 S가 큰 경우는 잘못된 트리
            if(S[next.node] != -1 && temp.Max > S[next.node])
            {
                result = -1;
                return;
            }
            //S가 중복되는 경우들을 제거
            //자식 노드의 개수가 n일때 중복되는 S는 (n - 1)번 중복됨
            if(i != 0)
            {
                result -= temp.Max;
            }
            q.push(next);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
    {
        int node;
        scanf("%d", &node);
        vec[node].push_back(i);
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &S[i]);
    }
    BFS();
    printf("%lld", result);
}