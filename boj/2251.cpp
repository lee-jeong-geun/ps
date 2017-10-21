#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int a, b, c;
}Data;
int A, B, C, result[205], chk[205][205][205];

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
queue<Data>q;
void chkchk(Data temp)
{
    if(chk[temp.a][temp.b][temp.c] == 0)
    {
        chk[temp.a][temp.b][temp.c] = 1;
        q.push(temp);
    }
}

void BFS()
{
    Data First = {0, 0, C};
    chkchk(First);
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        if(temp.a == 0)
        {
            result[temp.c] = 1;
        }
        if(temp.a != 0)
        {
            if(temp.a + temp.b > B)
            {
                Data next = {temp.a - B + temp.b, B, temp.c};
                chkchk(next);
                if(temp.a - B + temp.b + temp.c > C)
                {
                    Data next2 = {temp.a - B + temp.b - C + temp.c, B, C};
                    chkchk(next2);
                }
                else
                {
                    Data next2 = {0, B, temp.a - B + temp.b + temp.c};
                    chkchk(next2);
                }
            }
            else
            {
                Data next = {0, temp.a + temp.b, temp.c};
                chkchk(next);
            }
            if(temp.a + temp.c > C)
            {
                Data next = {temp.a - C + temp.c, temp.b, C};
                chkchk(next);
                if(temp.a - C + temp.c + temp.b > B)
                {
                    Data next2 = {temp.a - C + temp.c - B + temp.b, B, C};
                    chkchk(next2);
                }
                else
                {
                    Data next2 = {0, temp.a - C + temp.c + temp.b, C};
                    chkchk(next2);
                }
            }
            else
            {
                Data next = {0, temp.b, temp.a + temp.c};
                chkchk(next);
            }
        }
        if(temp.b != 0)
        {
            if(temp.b + temp.a > A)
            {
                Data next = {A, temp.b - A + temp.a, temp.c};
                chkchk(next);
                if(temp.b - A + temp.a + temp.c > C)
                {
                    Data next2 = {A, temp.b - A + temp.a + C - temp.c, C};
                    chkchk(next2);
                }
                else
                {
                    Data next2 = {A, 0, temp.b - A + temp.a + temp.c};
                    chkchk(next2);
                }
            }
            else
            {
                Data next = {temp.b + temp.a, 0, temp.c};
                chkchk(next);
            }
            if(temp.b + temp.c > C)
            {
                Data next = {temp.a, temp.b - C + temp.c, C};
                chkchk(next);
                if(temp.b - C + temp.c + temp.a > A)
                {
                    Data next2 = {A, temp.b - C + temp.c + A - temp.a, C};
                    chkchk(next2);
                }
                else
                {
                    Data next2 = {temp.b - C + temp.c + temp.a, 0, C};
                    chkchk(next2);
                }
            }
            else
            {
                Data next = {temp.a, 0, temp.b + temp.c};
                chkchk(next);
            }
        }
        if(temp.c != 0)
        {
            if(temp.c + temp.a > A)
            {
                Data next = {A, temp.b, temp.c - A + temp.a};
                chkchk(next);
                if(temp.c - A + temp.a + temp.b > B)
                {
                    Data next2 = {A, B, temp.c - A + temp.a - B + temp.b};
                    chkchk(next2);
                }
                else
                {
                    Data next2 = {A, temp.c - A + temp.a + temp.b, 0};
                    chkchk(next2);
                }
            }
            else
            {
                Data next = {temp.a + temp.c, temp.b, 0};
                chkchk(next);
            }
            if(temp.c + temp.b > B)
            {
                Data next = {temp.a, B, temp.c - B + temp.b};
                chkchk(next);
                if(temp.c - B + temp.b + temp.a > A)
                {
                    Data next2 = {A, B, temp.c - B + temp.b - A + temp.a};
                    chkchk(next2);
                }
                else
                {
                    Data next2 = {temp.c - B + temp.b + temp.a, B, 0};
                    chkchk(next2);
                }
            }
            else
            {
                Data next = {temp.a, temp.b + temp.c, 0};
                chkchk(next);
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &A, &B, &C);
    BFS();
    for(int i = 0; i <= 200; i++)
    {
        if(result[i] == 1)
        {
            printf("%d ", i);
        }
    }
}