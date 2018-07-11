#include <cstdio>
#include <iostream>
using namespace std;
typedef struct node
{
    int num;
    node *flink;
    node *blink;
}Node;
Node *Head, *Cur;
int N, K;

Node* createNode(int num)
{
    Node *newnode;
    newnode = new Node();
    newnode->num = num;
    newnode->flink = NULL;
    newnode->blink = NULL;
    return newnode;
}

void init()
{
    Head = createNode(-1);
    Head->flink = Head;
    Head->blink = Head;
}

void push(int num)
{
    Node *tnode, *newnode;
    tnode = Head->blink;
    while(tnode->blink != Head)
    {
        tnode = tnode->blink;
    }
    newnode = createNode(num);
    tnode->blink = newnode;
    newnode->flink = tnode;
    newnode->blink = Head;
}

void pop()
{
    Node *tnode;
    tnode = Cur;
    Cur->flink->blink = Cur->blink;
    Cur->blink->flink = Cur->flink;
    Cur = Cur->blink;
    delete tnode;
    if(Cur == Head)
    {
        Cur = Cur->blink;
    }
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        int Num;
        init();
        scanf("%d %d", &N, &K);
        Num = N;
        for(int i = 1; i <= N; i++)
        {
            push(i);
        }
        Cur = Head->blink;
        while(Num != 2)
        {
            pop();
            Num--;
            for(int i = 0; i < K - 1; i++)
            {
                Cur = Cur->blink;
                if(Cur == Head)
                {
                    Cur = Cur->blink;
                }
            }
        }
        printf("%d %d\n", Head->blink->num, Head->blink->blink->num);
    }
}