#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef struct _data
{
    int dzone[3][3];
    int zx, zy;
    int count;
}Data;
int zone[5][5], endzone[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
int arrA[4] = {0, 0, 1, -1};
int arrB[4] = {1, -1, 0, 0};
map<int, int> chk;

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
        Front = 0;
        Rear = 0;
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

int range(int a, int b)
{
    if(a >= 0 && a < 3 && b >= 0 && b < 3)
    {
        return 1;
    }
    return 0;
}

int zonechk(Data *t)
{
    int hap = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            hap *= 10;
            hap += t->dzone[i][j];
        }
    }
    if(chk[hap] == 0)
    {
        chk[hap] = 1;
        return 0;
    }
    return 1;
}

int BFS()
{
    queue<Data>q;
    Data First;
    First.count = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(zone[i][j] == 0)
            {
                First.zx = j;
                First.zy = i;
            }
            First.dzone[i][j] = zone[i][j];
        }
    }
    zonechk(&First);
    q.push(First);
    while(!q.empty())
    {
        int count = 0;
        Data temp;
        temp = q.front();
        q.pop();
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(temp.dzone[i][j] == endzone[i][j])
                {
                    count++;
                }
            }
        }
        if(count == 9)
        {
            return temp.count;
        }
        for(int i = 0; i < 4; i++)
        {
            Data next;
            next = temp;
            next.zx = next.zx + arrA[i];
            next.zy = next.zy + arrB[i];
            next.count++;
            if(range(next.zx, next.zy) == 1)
            {
                int swapdata;
                swapdata = next.dzone[temp.zy][temp.zx];
                next.dzone[temp.zy][temp.zx] = next.dzone[next.zy][next.zx];
                next.dzone[next.zy][next.zx] = swapdata;
                if(zonechk(&next) == 0)
                {
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int main()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &zone[i][j]);
        }
    }
    printf("%d", BFS());
}