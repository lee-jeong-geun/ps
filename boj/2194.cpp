#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x;
    int y;
    int count;
}Data;
int N, M, A, B, K, Sx, Sy, Ex, Ey, zone[505][505], chk[505][505];
int arrA[4] = {0, 0, 1, -1};
int arrB[4] = {1, -1, 0, 0};

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
            Rear= newnode;
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

bool range(int a, int b)
{
    if(a >= 1 && a <= M && b >= 1 && b <= N)
    {
        return 1;
    }
    return 0;
}

bool move(int a, int b)
{
    for(int i = b; i < b + A; i++)
    {
        for(int j = a; j < a + B; j++)
        {
            if(zone[i][j] == 1 || range(j, i) == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int BFS()
{
    queue<Data>q;
    q.push({Sx, Sy, 0});
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        if(temp.x == Ex && temp.y == Ey)
        {
            return temp.count;
        }
        for(int i = 0; i < 4; i++)
        {
            Data next;
            next.x = temp.x + arrA[i];
            next.y = temp.y + arrB[i];
            next.count = temp.count + 1;
            if(zone[next.y][next.x] == 0 && chk[next.y][next.x] == 0 && move(next.x, next.y) == 1)
            {
                chk[next.y][next.x] = 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d %d %d %d", &N, &M, &A, &B, &K);
    for(int i = 0; i < K; i++)
    {
        int x, y;
        scanf("%d %d", &y, &x);
        zone[y][x] = 1;
    }
    scanf("%d %d %d %d", &Sy, &Sx, &Ey, &Ex);
    printf("%d", BFS());
}