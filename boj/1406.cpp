#include <cstdio>
#include <iostream>
using namespace std;
typedef struct node
{
    char data;
    node *flink, *blink;
    node()
    {
        flink = NULL;
        blink = NULL;
    }
}Node;
Node pool[600005];
int poolidx;

/*
연결리스트를 이용하여 주어진대로 구현 하면 된다.
현재 커서의 오른쪽에 삽입 하도록 했고
현재 커서가 가리키는곳을 삭제하도록 하였다.
Head노드와 Tail노드를 만들어서 예외처리를 안하도록 구현했다.
동적 할당하면 시간이 꽤 걸리므로 미리 배열을 할당해서 새 노드를 생성 할 때
배열의 인덱스를 리턴하도록 하였다.
*/

//동적 할당x
Node* alloc()
{
    return &pool[poolidx++];
}

typedef struct Nodelist
{
    Node *Head, *Tail, *Cur;
    Nodelist()
    {
        Head = alloc();
        Head->data = '1';
        Tail = alloc();
        Tail->data = '2';
        Head->blink = Tail;
        Tail->flink = Head;
        Cur = Head;
    }
    void insertNode(char word)
    {
        Node *newnode = alloc();
        newnode->data = word;
        newnode->flink = Cur;
        newnode->blink = Cur->blink;
        Cur->blink->flink = newnode;
        Cur->blink = newnode;
        Cur = newnode;
    }
    void deleteNode()
    {
        if(Cur->data == '1')
        {
            return;
        }
        Cur->blink->flink = Cur->flink;
        Cur->flink->blink = Cur->blink;
        Cur = Cur->flink;
    }
    void moveCurLeft()
    {
        if(Cur->data == '1')
        {
            return;
        }
        Cur = Cur->flink;
    }
    void moveCurRight()
    {
        if(Cur->blink->data == '2')
        {
            return;
        }
        Cur = Cur->blink;
    }
    void printNode()
    {
        Node *tnode;
        tnode = Head->blink;
        while(tnode->data != '2')
        {
            printf("%c", tnode->data);
            tnode = tnode->blink;
        }
    }
}List;
List list;

char Str[100005];
int N;

int strlen(char *str)
{
    int len = 0;
    while(*str != 0)
    {
        len++;
        str++;
    }
    return len;
}

int main()
{
    int Slength;
    scanf("%s %d", Str, &N);
    Slength = strlen(Str);
    for(int i = 0; i < Slength; i++)
    {
        list.insertNode(Str[i]);
    }
    for(int i = 0; i < N; i++)
    {
        char op;
        scanf(" %c", &op);
        if(op == 'L')
        {
            list.moveCurLeft();
        }
        else if(op == 'D')
        {
            list.moveCurRight();
        }
        else if(op == 'B')
        {
            list.deleteNode();
        }
        else
        {
            char word;
            scanf(" %c", &word);
            list.insertNode(word);
        }
    }
    list.printNode();
}