#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, y, count;
}Data;
int N, M, R, C, L, zone[55][55], chk[55][55], result, moving[5][10][10];
int arrA[4] = {0, 1, 0, -1};
int arrB[4] = {-1, 0, 1, 0};

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

void moveinit()
{
    int temp1[4] = {1, 2, 5, 6};
    for(int i = 0; i < 4; i++)
    {
        moving[0][1][temp1[i]] = 1;
        moving[0][2][temp1[i]] = 1;
        moving[0][4][temp1[i]] = 1;
        moving[0][7][temp1[i]] = 1;
    }
    int temp2[4] = {1, 3, 6, 7};
    for(int i = 0; i < 4; i++)
    {
        moving[1][1][temp2[i]] = 1;
        moving[1][3][temp2[i]] = 1;
        moving[1][4][temp2[i]] = 1;
        moving[1][5][temp2[i]] = 1;
    }
    int temp3[4] = {1, 2, 4, 7};
    for(int i = 0; i < 4; i++)
    {
        moving[2][1][temp3[i]] = 1;
        moving[2][2][temp3[i]] = 1;
        moving[2][5][temp3[i]] = 1;
        moving[2][6][temp3[i]] = 1;
    }
    int temp4[4] = {1, 3, 4, 5};
    for(int i = 0; i < 4; i++)
    {
        moving[3][1][temp4[i]] = 1;
        moving[3][3][temp4[i]] = 1;
        moving[3][6][temp4[i]] = 1;
        moving[3][7][temp4[i]] = 1;
    }
}

void init()
{
    result = 1;
    for(int i = 0; i < 55; i++)
    {
        for(int j = 0; j < 55; j++)
        {
            chk[i][j] = 0;
        }
    }
}

int range(int a, int b)
{
    if(a >= 0 && a < M && b >= 0 && b < N)
    {
        return 1;
    }
    return 0;
}

int move(int tx, int ty, int nx, int ny, int dir)
{
    return moving[dir][zone[ty][tx]][zone[ny][nx]];
}

void BFS()
{
    queue<Data>q;
    Data First;
    First.x = C;
    First.y = R;
    First.count = L - 1;
    q.push(First);
    chk[R][C] = 1;
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        if(temp.count == 0)
        {
            continue;
        }
        for(int i = 0; i < 4; i++)
        {
            Data next;
            next.x = temp.x + arrA[i];
            next.y = temp.y + arrB[i];
            next.count = temp.count - 1;
            if(range(next.x, next.y) == 1 && chk[next.y][next.x] == 0 && move(temp.x, temp.y, next.x, next.y, i) == 1)
            {
                result++;
                chk[next.y][next.x] = 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    moveinit();
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        init();
        scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                scanf("%d", &zone[i][j]);
            }
        }
        BFS();
        printf("#%d %d\n", testcase, result);
    }
}