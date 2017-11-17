#include <cstdio>
#include <iostream>
using namespace std;
int plength, n, dir, result;
char p[100005];

template<typename T>
class deque
{
public:
    class Node
    {
    public:
        T data;
        Node *flink, *blink;
        Node()
        {
            flink = NULL;
            blink = NULL;
        }
    };
    int _size;
    Node *Front, *Rear;
    deque()
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
        if(_size == 1)
        {
            Front = newnode;
            Rear = newnode;
        }
        else
        {
            Rear->blink = newnode;
            newnode->flink = Rear;
            Rear = newnode;
        }
    }
    void pop(int flag)
    {
        _size--;
        Node *tnode;
        tnode = Front;
        if(flag == 0)
        {
            Front = Front->blink;
        }
        else
        {
            Front = Front->flink;
        }
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
    void change()
    {
        Node *temp;
        temp = Front;
        Front = Rear;
        Rear = temp;
    }
};

int strlen(char *str)
{
    int len = 0;
    while(*str != 0)
    {
        len++;
        str++;
    }
    return len;
};

int main()
{
    
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        deque<int>dq;
        result = 0;
        dir = 0;
        scanf("%s %d", p, &n);
        getchar();
        getchar();
        plength = strlen(p);
        for(int i = 0; i < n; i++)
        {
            int num;
            scanf("%d", &num);
            if(i != n - 1)
            {
                getchar();
            }
            dq.push(num);
        }
        getchar();
        for(int i = 0; i < plength; i++)
        {
            if(p[i] == 'R')
            {
                dir = !dir;
                dq.change();
            }
            else
            {
                if(dq.empty() == 1)
                {
                    result = 1;
                    break;
                }
                dq.pop(dir);
            }
        }
        if(result == 1)
        {
            printf("error\n");
        }
        else
        {
            int resultsize;
            resultsize = dq.size();
            printf("[");
            for(int i = 0; i < resultsize; i++)
            {
                if(i == 0)
                {
                    printf("%d", dq.front());
                }
                else
                {
                    printf(",%d", dq.front());
                }
                dq.pop(dir);
            }
            printf("]\n");
        }
    }
}