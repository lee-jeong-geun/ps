#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, y;
}Data;
int N, zone[30][30], chk[30][30], result[1005], resultcount;
int arrA[4] = {0, 0, 1, -1};
int arrB[4] = {1, -1, 0, 0};

/*
단순 BFS 문제
맵 전체를 돌면서 1을 만나면 BFS돌아서 싹다 체크해주고 카운트를 한다.
총 단지수는 BFS를 몇번 시작했냐이고 각 단지내의 집의 수는 BFS돌면서 카운트한
횟수이다.
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

//맵 범위 확인
bool range(int a, int b)
{
    if(a >= 0 && a < N && b >= 0 && b < N)
    {
        return 1;
    }
    return 0;
}

void BFS(int x, int y)
{
    int count = 1;
    queue<Data> q;
    q.push({x, y});
    chk[y][x] = 1;
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            Data next;
            next.x = temp.x + arrA[i];
            next.y = temp.y + arrB[i];
            if(range(next.x, next.y) == 1 && zone[next.y][next.x] == 1 && chk[next.y][next.x] == 0)
            {
                chk[next.y][next.x] = 1;
                q.push(next);
                count++;
            }
        }
    }
    //오름 차순으로 정렬인데 퀵소트 구현하기 귀찮아서 카운팅 소트함
    result[count]++;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%1d", &zone[i][j]);
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            //1이고 체크가 안된것
            if(zone[i][j] == 1 && chk[i][j] == 0)
            {
                //총 단지수++
                resultcount++;
                BFS(j, i);
            }
        }
    }
    printf("%d\n", resultcount);
    //카운팅 소트
    for(int i = 0; i < 1000; i++)
    {
        for(int j = 0; j < result[i]; j++)
        {
            printf("%d\n", i);
        }
    }
}