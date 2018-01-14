#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, y;
}Data;
int w, h, zone[55][55], chk[55][55], result;
int arrA[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int arrB[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

/*
단순 BFS 문제
맵 전체를 탐색하다가 1을 만나면 BFS를 돈다.
BFS 시작 할 때 마다 카운트를 해주면 된다.
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

void init()
{
    for(int i = 0; i < 55; i++)
    {
        for(int j = 0; j < 55; j++)
        {
            chk[i][j] = 0;
        }
    }
    result = 0;
}

//맵 범위 확인
bool range(int a, int b)
{
    if(a >= 0 && a < w && b >= 0 && b < h)
    {
        return 1;
    }
    return 0;
}

void BFS(int x, int y)
{
    queue<Data>q;
    q.push({x, y});
    chk[y][x] = 1;
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            Data next;
            next.x = temp.x + arrA[i];
            next.y = temp.y + arrB[i];
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
    while(1)
    {
        init();
        scanf("%d %d", &w, &h);
        if(w == 0 && h == 0)
        {
            break;
        }
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                scanf("%d", &zone[i][j]);
            }
        }
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                //1이고 한번도 탐색 안했을 경우
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