#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int x, y;
}Data;
Data zone[105];
int n, chk[105], flag;
char result[2][7] = {"sad", "happy"};

/*
단순 BFS탐색
시작점에서 갈수있는 곳은 편의점 or 도착지점이다.
편의점에 가면 맥주를 20개 다 채울수 있기 때문에 맥주의 남은 갯수를 큐에 넣는건 사실상 무의미하다.
현 위치에서 다음 위치를 갈때 맥주 20개로 갈수있으면 큐에 넣는다.
편의점에서 편의점으로 계속 이동 가능하기 때문에 한번 갔던 곳은 다시 못가게 chk해주면 된다.
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

//절대값 함수
int abs(int num)
{
    return num > 0 ? num : num * - 1;
}

//초기화
void init()
{
    memset(chk, 0, sizeof chk);
    flag = 0;
}

void BFS()
{
    queue<Data> q;
    q.push({zone[0].x, zone[0].y});
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        //도착 지점일시 리턴
        if(temp.x == zone[n + 1].x && temp.y == zone[n + 1].y)
        {
            flag = 1;
            return;
        }
        for(int i = 1; i < n + 2; i++)
        {
            int distance;
            //다음 위치 거리를 계산
            distance = abs(zone[i].x - temp.x) + abs(zone[i].y - temp.y);
            //distance가 0이라는건 자기 자신을 의미함
            //chk[i] == 1은 이미 왔던곳
            //distance > 20 * 50 맥주 20개로 다음 위치 못감
            if(distance != 0 && distance <= 20 * 50 && chk[i] == 0)
            {
                chk[i] = 1;
                q.push({zone[i].x, zone[i].y});
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++)
    {
        init();
        scanf("%d", &n);
        for(int i = 0; i < n + 2; i++)
        {
            scanf("%d %d", &zone[i].x, &zone[i].y);
        }
        BFS();
        printf("%s\n", result[flag]);
    }
}