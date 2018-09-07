#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef struct _data
{
    int node, count;
}Data;
vector<int> vec[10505];
int chk[10005];

/*
그래프를 만들어줘서 bfs를 돌리면 된다.
*/

int BFS(int start, int end)
{
    queue<Data> q;
    q.push({start, 0});
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        if(temp.node == end)
        {
            return temp.count;
        }
        for(int i = 0; i < vec[temp.node].size(); i++)
        {
            Data next;
            next.node = vec[temp.node][i];
            next.count = temp.count + 1;
            if(chk[next.node] == 0)
            {
                chk[next.node] = 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    int count = 1;
    //그래프를 만듬
    for(int i = 1; ; i++)
    {
        if(count >= 10000)
        {
            break;
        }
        for(int j = 0; j < i; j++)
        {
            if(j != i - 1)
            {
                vec[count].push_back(count + 1);
                vec[count + 1].push_back(count);
            }
            vec[count].push_back(count + i);
            vec[count + i].push_back(count);
            vec[count].push_back(count + i + 1);
            vec[count + i + 1].push_back(count);
            count++;
            if(count >= 10000)
            {
                break;
            }
        }
    }
    for(int testcase = 1; testcase <= T; testcase++)
    {
        memset(chk, 0, sizeof chk);
        int a, b;
        scanf("%d %d", &a, &b);
        printf("#%d %d\n", testcase, BFS(a, b));
    }
}


#include <cstdio>
#include <iostream>
using namespace std;
int Height[10005], Width[10005];

/*
두 좌표간의 차이를 계산하면 된다.
왼쪽 위 대각선으로 이동하거나 오른쪽 아래 대각선으로 이동시
가로 세로가 한번에 감소되기 떄문에 조건을 나눠서 처리해 준다.
두 좌표가 위치해 있는곳이 "/" 모양이라면 두 좌표간의 가로, 세로 차이를 더해주고
"\" 모양이라면 두 좌표간의 max(가로차이, 세로차이)를 구하면 된다.
*/

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int abs(int num)
{
    return num > 0 ? num : num * -1;
}

int main()
{
    int T;
    scanf("%d", &T);
    int count = 1;
    for(int i = 1; i <= 200; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(count <= 10000)
            {
                Height[count] = i;
                Width[count++] = j;
            }
        }
    }
    for(int testcase = 1; testcase <= T; testcase++)
    {
        int a, b, result;
        scanf("%d %d", &a, &b);
        //조건문을 줄이기 위해 규칙을 정함
        if(Height[a] > Height[b])
        {
            swap(a, b);
        }
        // "/" 모양
        if(Width[a] >= Width[b])
        {
            result = abs(Width[a] - Width[b]) + abs(Height[b] - Height[a]);
        }
        // "\" 모양
        else
        {
            result = max(abs(Height[a] - Height[b]), abs(Width[a] - Width[b]));
        }
        printf("#%d %d\n", testcase, result);
    }
}