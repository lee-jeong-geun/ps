#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int Time, afterTime, humanidx;
}Data;
typedef struct _data2
{
    int humanidx, receptnum;
}Data2;
Data reception[15], repair[15];
int N, M, K, A, B, Human[1005], Time = 0, result;

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

queue<Data2>q1;
queue<Data2>q2;

void init()
{
    for(int i = 1; i <= 10; i++)
    {
        reception[i].afterTime = 0;
        reception[i].humanidx = -1;
        repair[i].afterTime = 0;
        repair[i].humanidx = -1;
    }
    result = 0;
}

void receptfunc()
{
    for(int i = 1; i <= N; i++)
    {
        if(reception[i].afterTime > 0)
        {
            reception[i].afterTime--;
            if(reception[i].afterTime == 0)
            {
                Data2 Push;
                Push.humanidx = reception[i].humanidx;
                Push.receptnum = i;
                reception[i].humanidx = -1;
                q2.push(Push);
            }            
        }
        else
        {
            if(q1.size() > 0)
            {
                Data2 temp;
                temp = q1.front();
                q1.pop();
                reception[i].afterTime = reception[i].Time - 1;
                reception[i].humanidx = temp.humanidx;
                if(reception[i].afterTime == 0)
                {
                    Data2 Push;
                    Push.humanidx = reception[i].humanidx;
                    Push.receptnum = i;
                    reception[i].humanidx = -1;
                    q2.push(Push);
                }
            }
        }
    }
}

void repairfunc()
{
    for(int i = 1; i <= M; i++)
    {
        if(repair[i].afterTime > 0)
        {
            repair[i].afterTime--;
        }
        else
        {
            if(q2.size() > 0)
            {
                Data2 temp;
                temp = q2.front();
                q2.pop();
                repair[i].afterTime = repair[i].Time - 1;
                repair[i].humanidx = temp.humanidx;
                if(temp.receptnum == A && i == B)
                {
                    result += temp.humanidx;
                }
            }
        }
    }
}

void func()
{
    Time = Human[1];
    for(int i = 1; i <= K;)
    {
        for(int j = i; j <= K; j++)
        {
            if(Time == Human[j])
            {
                i = j + 1;
                Data2 Push;
                Push.humanidx = j;
                Push.receptnum = 0;
                q1.push(Push);
            }
            else
            {
                break;
            }
        }
        repairfunc();
        receptfunc();
        Time++;
    }
    while(1)
    {
        int receptflag = 0;
        for(int i = 1; i <= N; i++)
        {
            if(reception[i].humanidx != -1)
            {
                receptflag = 1;
                break;
            }
        }
        if(receptflag == 0 && q1.empty() == 1 && q2.empty() == 1)
        {
            break;
        }
        repairfunc();
        receptfunc();
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        init();
        scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &reception[i].Time);
        }
        for(int i = 1; i <= M; i++)
        {
            scanf("%d", &repair[i].Time);
        }
        for(int i = 1; i <= K; i++)
        {
            scanf("%d", &Human[i]);
        }
        func();
        if(result == 0)
        {
            result = -1;
        }
        printf("#%d %d\n", testcase, result);
    }
}