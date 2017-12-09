#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int x;
    int y;
    int level;
    int jump;
}Data;
int n, m, zone[105][105], chk[105][105][3];
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

bool range(int a, int b)
{
    if(a >= 0 && a < m && b >= 0 && b < n)
    {
        return 1;
    }
    return 0;
}

void BFS()
{
    queue<Data> q;
    q.push({0, 0, zone[0][0], 1});
    chk[0][0][1] = zone[0][0];
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
            next.level = max(temp.level, zone[next.y][next.x]);
            next.jump = temp.jump;
            if(range(next.x, next.y) == 1)
            {
                if(chk[next.y][next.x][next.jump] > next.level)
                {
                    chk[next.y][next.x][next.jump] = next.level;
                    q.push(next);
                }
            }
            if(next.jump == 1)
            {
                next.x += arrA[i];
                next.y += arrB[i];
                next.level = max(temp.level, zone[next.y][next.x]);
                next.jump = 0;
                if(range(next.x, next.y) == 1)
                {
                    if(chk[next.y][next.x][next.jump] > next.level)
                    {
                        chk[next.y][next.x][next.jump] = next.level;
                        q.push(next);
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &zone[i][j]);
        }
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 101; j++)
        {
            for(int k = 0; k < 101; k++)
            {
                chk[j][k][i] = 1234567890;
            }
        }
    }
    BFS();
    printf("%d", min(chk[n - 1][m - 1][0], chk[n - 1][m - 1][1]));
}