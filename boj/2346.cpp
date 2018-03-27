#include <cstdio>
#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    int idx;
    node *flink, *blink;
    node()
    {
        flink = 0;
        blink = 0;
    }
}Node;
Node *Head;
int N;

/*
원을 만들기 위해서 원형 리스트를 사용하였다.
각각의 수에 따라 왼쪽 오른쪽으로 이동후 삭제 시키면 된다.
*/

void init()
{
    Head = new Node();
    Head->flink = Head;
    Head->blink = Head;
    Head->data = 0;
}

int main()
{
    init();
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        Node *newnode = new Node();
        newnode->data = num;
        newnode->idx = i + 1;
        //처음 연결 할 경우
        if(Head->blink == Head)
        {
            //Head와 새로운 노드 연결
            Head->blink = newnode;
            newnode->flink = Head;
            newnode->blink = Head;
            Head->flink = newnode;
        }
        else
        {
            Node *tnode;
            tnode = Head;
            //끝에 연결 하기 위해 끝까지 이동
            while(tnode->blink != Head)
            {
                tnode = tnode->blink;
            }
            //맨 뒤의 노드와 새로운 노드 연결
            tnode->blink = newnode;
            newnode->flink = tnode;
            //노드의 뒤를 Head와 연결
            newnode->blink = Head;
            Head->flink = newnode;
        }
    }
    int count = 0;
    Node *Cur;
    Cur = Head->blink;
    while(1)
    {
        Node *tnode;
        int tdata, tidx;
        tnode = Cur;
        tdata = Cur->data;
        tidx = Cur->idx;
        count++;
        printf("%d\n", tidx);
        //N개를 다 출력했다면 종료
        if(count == N)
        {
            break;
        }
        //해당 노드의 양옆을 연결
        Cur->flink->blink = Cur->blink;
        Cur->blink->flink = Cur->flink;
        //다음 노드로 이동
        if(tdata > 0)
        {
            Cur = Cur->blink;
            for(int i = 0; i < tdata - 1; i++)
            {
                if(Cur->data == 0)
                {
                    i--;
                }
                Cur = Cur->blink;
            }
            if(Cur->data == 0)
            {
                Cur = Cur->blink;
            }
        }
        else
        {
            Cur = Cur->flink;
            tdata *= -1;
            for(int i = 0; i < tdata - 1; i++)
            {
                if(Cur->data == 0)
                {
                    i--;
                }
                Cur = Cur->flink;
            }
            if(Cur->data == 0)
            {
                Cur = Cur->flink;
            }
        }
        delete tnode;
    }
}