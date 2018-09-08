#include <cstdio>
#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    node *flink, *blink;
    node()
    {
        flink = NULL;
        blink = NULL;
    }
}Node;

typedef struct nodelist
{
    Node *Head, *Tail, *Cur;
    nodelist()
    {
        Head = new Node();
        Tail = new Node();
        Head->data = -1;
        Tail->data = -2;
        Head->blink = Tail;
        Tail->flink = Head;
        Cur = Head;
    }
    void insertNode(int data)
    {
        Node *newnode = new Node();
        newnode->data = data;
        newnode->blink = Cur->blink;
        newnode->flink = Cur;
        Cur->blink->flink = newnode;
        Cur->blink = newnode;
        Cur = newnode;
    }
    void deleteNode()
    {
        Node *tnode;
        tnode = Cur;
        Cur->blink->flink = Cur->flink;
        Cur->flink->blink = Cur->blink;
        Cur = Cur->flink;
        delete tnode;
    }
    void printNode()
    {
        Node *tnode;
        tnode = Head->blink;
        while(tnode->data != -2)
        {
            printf("%d", tnode->data);
            tnode = tnode->blink;
        }
    }
}List;