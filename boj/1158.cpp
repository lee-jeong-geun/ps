#include <cstdio>
#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    node *flink;
    node *blink;
    node()
    {
        flink = 0;
        blink = 0;
    }
}Node;
Node pool[5005];
int poolIdx;

/*
원형 리스트에 수들을 순서대로 넣고 카운트 하면서 출력하고 제거하면 된다.
*/

Node* alloc()
{
    return &pool[poolIdx++];
}

typedef struct listNode
{
    Node *Head;
    Node *Tail;
    Node *Cur;
    //Head, Tail 더미 노드 생성
    //예외 처리 용이
    listNode()
    {
        Head = alloc();
        Tail = alloc();
        Head->flink = Tail;
        Head->blink = Tail;
        Tail->flink = Head;
        Tail->blink = Head;
        Cur = Head;
    }
    void insertNode(int data)
    {
        Node *newnode;
        newnode = alloc();
        newnode->data = data;
        newnode->blink = Cur->blink;
        newnode->flink = Cur;
        Cur->blink->flink = newnode;
        Cur->blink = newnode;
        Cur = newnode;
    }
    void deleteNode()
    {
        Cur->blink->flink = Cur->flink;
        Cur->flink->blink = Cur->blink;
        Cur = Cur->blink;
        if(Cur == Tail)
        {
            Cur = Head->blink;
        }
    }
    void moveCur()
    {
        Cur = Cur->blink;
        if(Cur == Tail)
        {
            Cur = Head->blink;
        }
    }
    bool empty()
    {
        return Head->blink == Tail;
    }
}List;
List list;
int N, M;

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        list.insertNode(i);
    }
    int count = 1, rcount = 0;
    printf("<");
    list.Cur = list.Head->blink;
    while(!list.empty())
    {
        if(count == M)
        {
            rcount++;
            if(rcount == N)
            {
                printf("%d", list.Cur->data);
            }
            else
            {
                printf("%d, ", list.Cur->data);
            }
            list.deleteNode();
            count = 1;
        }
        else
        {
            count++;
            list.moveCur();
        }
    }
    printf(">");
}