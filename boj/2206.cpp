#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, y, flag, count;
}Data;
int N, M, zone[1005][1005], chk[1005][1005][3];
int arrA[4] = {1, 0, -1, 0};
int arrB[4] = {0, 1, 0, -1};

/*
단순 BFS 문제
벽을 부쉈냐 안부쉈냐를 나눠서 생각을 하면 된다.
그래서 체크배열도 3차원으로 했다. 2차원으로 할경우 부숴서 온경우랑 안부숴서 온경우가
겹치기 때문이다.
*/

//큐 구현
template<typename T>
class queue
{
public:
    class Node
    {
    public:
        T data;
        Node *link;
    };
    int _size;
    Node *Front, *Rear;
    queue()
    {
        _size = 0;
        Front = NULL;
        Rear = NULL;
    }
    void push(T data)
    {
        _size++;
        Node *newnode = new Node();
        newnode->data = data;
        newnode->link = NULL;
        if(_size == 1)
        {
            Front = newnode;
            Rear = newnode;
        }
        else
        {
            Rear->link = newnode;
            Rear = newnode;
        }
    }
    void pop()
    {
        _size--;
        Node *tnode;
        tnode = Front;
        Front = Front->link;
        delete tnode;
    }
    T front()
    {
        return Front->data;
    }
    int size()
    {
        return _size;
    }
    bool empty()
    {
        return _size == 0;
    }
};

//맵 범위 확인
bool range(int a, int b)
{
    if(a >= 1 && a <= M && b >= 1 && b <= N)
    {
        return 1;
    }
    return 0;
}

int BFS()
{
    queue<Data> q;
    q.push({1, 1, 1, 1});
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        if(temp.x == M && temp.y == N)
        {
            return temp.count;
        }
        for(int i = 0; i < 4; i++)
        {
            Data next;
            next.x = temp.x + arrA[i];
            next.y = temp.y + arrB[i];
            //부숴서 온경우, 안부숴서 온경우 확인 변수
            next.flag = temp.flag;
            next.count = temp.count + 1;
            if(range(next.x, next.y) == 1)
            {
                //벽인 경우
                if(zone[next.y][next.x] == 1)
                {
                    //지금 까지 벽을 한번도 안 부숨
                    if(next.flag == 1 && chk[next.y][next.x][next.flag] == 0)
                    {
                        chk[next.y][next.x][next.flag] = 1;
                        next.flag = 0;
                        q.push(next);
                    }
                }
                else
                {
                    if(chk[next.y][next.x][next.flag] == 0)
                    {
                        chk[next.y][next.x][next.flag] = 1;
                        q.push(next);
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            scanf("%1d", &zone[i][j]);
        }
    }
    printf("%d", BFS());
}