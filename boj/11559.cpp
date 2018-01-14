#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, y;
}Data;
int blockflag, chk[15][10], result;
char zone[15][10];
int arrA[4] = {0, 0, 1, -1};
int arrB[4] = {1, -1, 0, 0};

/*
맵 전체를 탐색해서 블록이 있을경우 BFS를 돌린다.
BFS돌릴때 같은 블록이 4개 이상이라면 해당 블록들을 .으로 바꿔준다.
그리고 맵 전체 BFS가 끝날경우 공중에 붕 떠있는 블록들을 다시 땅으로 내려준다.
맵 전체를 BFS 돌렸을때 같은 블록이 4개이상이 안나올때까지 프로그램을 돌린다.
*/

// 큐 구현
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

//맵 범위 확인
bool range(int a, int b)
{
    if(a >= 0 && a < 6 && b >= 0 && b < 12)
    {
        return 1;
    }
    return 0;
}

void BFS(int x, int y)
{
    //같은 블록이 몇개 인지 카운트 하는 변수
    int blockcount = 1;
    //BFSq는 BFS돌릴때 쓰는 q
    //clearq는 블록들을 .으로 바꿀때 사용하는 q
    queue<Data>BFSq, clearq;
    chk[y][x] = 1;
    BFSq.push({x, y});
    clearq.push({x, y});
    while(!BFSq.empty())
    {
        Data temp;
        temp = BFSq.front();
        BFSq.pop();
        for(int i = 0; i < 4; i++)
        {
            Data next;
            next.x = temp.x + arrA[i];
            next.y = temp.y + arrB[i];
            //같은 블록이고 체크가 안됐을때 큐에 넣어줌
            if(range(next.x, next.y) == 1 && zone[next.y][next.x] == zone[y][x] && chk[next.y][next.x] == 0)
            {
                blockcount++;
                chk[next.y][next.x] = 1;
                BFSq.push(next);
                clearq.push(next);
            }
        }
    }
    //같은 블록이 4개 이상일 경우
    if(blockcount >= 4)
    {
        blockflag = 1;
        //clearq에 있는 모든 블록들을 다 .으로 바꿔줌
        while(!clearq.empty())
        {
            Data temp;
            temp = clearq.front();
            clearq.pop();
            zone[temp.y][temp.x] = '.';
        }
    }
    else
    {
        //4개 이상이 아니라면 clearq를 비워줌
        while(!clearq.empty())
        {
            clearq.pop();
        }
    }
}

//공중에 붕 떠있는 블록들을 내려줌
void blockdown()
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 10; j >= 0; j--)
        {
            //블록일 경우
            if(zone[j][i] != '.')
            {
                int blockx, blocky;
                blockx = i;
                blocky = j;
                //바로 아래가 .이면 블록이 붕 떠있는 경우니까 붕 안 떠있을 때까지 내림
                while(blocky + 1 < 12 && zone[blocky + 1][blockx] == '.')
                {
                    zone[blocky + 1][blockx] = zone[blocky][blockx];
                    zone[blocky][blockx] = '.';
                    blocky++;
                }
            }
        }
    }
}

void clearchk()
{
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            chk[i][j] = 0;
        }
    }
}

int main()
{
    for(int i = 0; i < 12; i++)
    {
        scanf("%s", zone[i]);
    }
    while(1)
    {
        blockflag = 0;
        clearchk();
        for(int i = 0; i < 12; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                //블록이고 한번도 탐색을 안했을 경우
                if(zone[i][j] != '.' && chk[i][j] == 0)
                {
                    BFS(j, i);
                }
            }
        }
        //한번이라도 같은 블록이 4개이상이 나온 경우
        if(blockflag == 1)
        {
            result++;
            blockdown();
        }
        //그게 아니라면 종료
        else
        {
            break;
        }
    }
    printf("%d", result);
}