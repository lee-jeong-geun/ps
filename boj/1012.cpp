#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, y;
}Data;
int M, N, K, zone[55][55], chk[55][55], result;
int arrA[4] = {0, 0, 1, -1};
int arrB[4] = {1, -1, 0, 0};

/*
단순 BFS 문제
맵 전체를 돌면서 1이 있으면 BFS돌려서 싹다 체크해준다.
BFS시작 할때마다 카운트 해주면 된다.
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
            Rear = Rear->link;
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

void init()
{
    for(int i = 0; i < 55; i++)
    {
        for(int j = 0; j < 55; j++)
        {
            zone[i][j] = 0;
            chk[i][j] = 0;
        }
    }
    result = 0;
}

//맵 범위 확인
bool range(int a, int b)
{
    if(a >= 0 && a < M && b >= 0 && b < N)
    {
        return 1;
    }
    return 0;
}

void BFS(int x, int y)
{
    queue<Data>q;
    q.push({x, y});
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            Data next;
            next.x = temp.x + arrA[i];
            next.y = temp.y + arrB[i];
            //1이면 큐에 넣음
            if(range(next.x, next.y) == 1 && zone[next.y][next.x] == 1 && chk[next.y][next.x] == 0)
            {
                chk[next.y][next.x] = 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        init();
        scanf("%d %d %d", &M, &N, &K);
        for(int i = 0; i < K; i++)
        {
            int X, Y;
            scanf("%d %d", &X, &Y);
            zone[Y][X] = 1;
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                //한번도 안들어갔으면 BFS돌림
                if(zone[i][j] == 1 && chk[i][j] == 0)
                {
                    result++;
                    BFS(j, i);
                }
            }
        }
        printf("%d\n", result);
    }
}