#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, y, count, flag;
}Data;
int R, C, chk[55][55], Dx, Dy, Sx, Sy;
char zone[55][55];
int arrA[4] = {0, 0, 1, -1};
int arrB[4] = {1, -1, 0, 0};

/*
단순 BFS 문제
고슴도치는 물이 차있는 곳이랑 물이 찰 예정인 곳은 가지를 못한다.
물이 찰 예정인 곳을 구현하는건 큐에 먼저 넣으면 된다.
큐는 선입 선출이기 때문에 물을 먼저 큐에 다 넣고 그다음에 고슴 도치를 넣는다면
당연히 고슴 도치가 이동하기전에 물은 찰 예정일 곳에 먼저 가 있게 된다.
*/

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

//맵 범위 확인
bool range(int a, int b)
{
    if(a >= 0 && a < C && b >= 0 && b < R)
    {
        return 1;
    }
    return 0;
}

void BFS()
{
    q.push({Sx, Sy, 0, 1});
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        //고슴도치가 비버의 굴에 도착했을시
        if(temp.flag == 1 && temp.x == Dx && temp.y == Dy)
        {
            printf("%d", temp.count);
            return;
        }
        for(int i = 0; i < 4; i++)
        {
            Data next;
            next.x = temp.x + arrA[i];
            next.y = temp.y + arrB[i];
            next.count = temp.count + 1;
            next.flag = temp.flag;
            //물과 고슴도치는 장애물에 못가고 물은 비버의 굴에 못감
            if(zone[next.y][next.x] == 'X' || (next.flag == 0 && zone[next.y][next.x] == 'D'))
            {
                continue;
            }
            if(range(next.x, next.y) == 1 && chk[next.y][next.x] == 0)
            {
                chk[next.y][next.x] = 1;
                q.push(next);
            }
        }
    }
    //고슴도치가 비버의 굴에 못갈 경우
    printf("KAKTUS");
}

int main()
{
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            scanf(" %c", &zone[i][j]);
            //비버의 굴 좌표
            if(zone[i][j] == 'D')
            {
                Dx = j;
                Dy = i;
            }
            //고슴도치 좌표
            else if(zone[i][j] == 'S')
            {
                Sx = j;
                Sy = i;
            }
            //물 좌표, 큐에 넣음
            else if(zone[i][j] == '*')
            {
                q.push({j, i, 0, 0});
            }
        }
    }
    BFS();
}