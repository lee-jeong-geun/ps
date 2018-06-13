#include <cstdio>
#include <iostream>
using namespace std;
int plength, n, dir, result;
char p[100005];

/*
덱을 이용하였다. R명령어는 덱의 front와 rear를 스왑시켜주면 되고 d는 front의 데이터를 지우면 된다.
처음에 제출 했을 때는 ac를 맞았지만 재채점 이후 큰 데이터가 들어오는 것 같아서 약간의 최적화를 해주니 시간안에 겨우 들어왔다.
최적화는 연결리스트의 노드를 생성 할 때 매번 동적 할당 하지 않고 미리 노드 배열을 만들어서 그 배열들을 할당해 주었다.
*/

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

    //미리 배열을 만들어 놓음
    Node *pool = (Node*)malloc(sizeof (Node) * 200001);

    int _size, idx;
    Node *Front, *Rear;
    deque()
    {
        idx = 0;
        _size = 0;
        Front = NULL;
        Rear = NULL;
    }

    void init()
    {
        idx = 0;
        Front = NULL;
        Rear = NULL;
        _size = 0;
    }

    //만들어 놓은 배열을 할당
    Node* alloc()
    {
        pool[idx].flink = 0;
        pool[idx].blink = 0;
        return &pool[idx++];
    }

    void push(T data)
    {
        _size++;
        Node *newnode = alloc();
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
    deque<int>dq;

    for(int testcase = 0; testcase < T; testcase++)
    {
        dq.init();
        result = 0;
        dir = 0;
        scanf("%s %d", p, &n);
        getchar();
        getchar();
        plength = strlen(p);
        //덱에 삽입
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
            //뒤집음(front와 rear 스왑)
            if(p[i] == 'R')
            {
                dir = !dir;
                dq.change();
            }
            else
            {
                //비어있으면 종료
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