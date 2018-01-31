#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int node;
    int count;
}Data;
int N, M, chk[50005], depth[50005], parent[50005];

/*
LCA를 구하면 되는 문제이다.
벡터를 쓰면 훨씬 간단해 지지만 벡터를 쓰지 않고 리스트를 이용해서 해결하였다.
간선 리스트를 만들고 BFS를 1번 노드부터 돌려서 각 노드의 깊이와 부모를 저장 하였다.
*/

//리스트 구현
class Node
{
public:
    int data;
    Node *link;
};
Node *List[50005];

//큐 구현
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
    int  _size;
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

void init()
{
    for(int i = 1; i < 50005; i++)
    {
        Node *newnode = new Node();
        newnode->data = -1;
        newnode->link = NULL;
        List[i] = newnode;
    }
}

//노드 생성
Node* createNode(int num)
{
    Node *newnode = new Node();
    newnode->data = num;
    newnode->link = NULL;
    return newnode;
}

//리스트에 노드 삽입
void insertNode(int idx, Node *node)
{
    Node *tnode, *ttnode;
    tnode = List[idx];
    ttnode = tnode;
    while(tnode != NULL)
    {
        ttnode = tnode;
        tnode = tnode->link;
    }
    ttnode->link = node;
}

void BFS()
{
    queue<Data> q;
    q.push({1, 0});
    chk[1] = 1;
    parent[1] = 0;
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        Node *tnode;
        tnode = List[temp.node];
        //모든 연결 요소 확인
        while(tnode != NULL)
        {
            if(tnode->data == -1)
            {
                tnode = tnode->link;
                continue;
            }
            Data next;
            next.node = tnode->data;
            //깊이 + 1
            next.count = temp.count + 1;
            tnode = tnode->link;
            //방문 하지 않았다면
            if(chk[next.node] == 0)
            {
                //깊이 갱신
                depth[next.node] = next.count;
                //다음 노드의 부모노드에 현재 노드를 저장
                parent[next.node] = temp.node;
                chk[next.node] = 1;
                q.push(next);
            }            
        }
    }
}

//LCA탐색
int searchLCA(int n1, int n2)
{
    //항상 n2를 n1보다 깊게 만듬
    if(depth[n1] > depth[n2])
    {
        int temp;
        temp = n1;
        n1 = n2;
        n2 = temp;
    }
    //깊이가 다르면 맞춰줌
    while(depth[n1] < depth[n2])
    {
        n2 = parent[n2];
    }
    //n1과 n2가 다르다면 같을때까지 부모 노드로 이동
    while(n1 != n2)
    {
        n1 = parent[n1];
        n2 = parent[n2];
    }
    return n1;
}


int main()
{
    init();
    scanf("%d", &N);
    for(int i = 0; i < N - 1; i++)
    {
        Node *snode, *enode;
        int s, e;
        scanf("%d %d", &s, &e);
        snode = createNode(s);
        enode = createNode(e);
        insertNode(s, enode);
        insertNode(e, snode);
    }
    BFS();
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        printf("%d\n", searchLCA(node1, node2));
    }
}