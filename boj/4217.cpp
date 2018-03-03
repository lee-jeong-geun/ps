#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int x, y;
}Data;
int H, W, chk[205][215], result[30], shape[6] = {'W' - 'A', 'A' - 'A', 'K' - 'A', 'J' - 'A', 'S' - 'A', 'D' - 'A'};
char zone[205][215];
char img[16][5] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
int arrA[4] = {0, 0, 1, -1};
int arrB[4] = {1, -1, 0, 0};

/*
이 문제의 규칙은 각각의 문양들 안에 있는 빈 공간의 개수를 파악하는 것이다.
우선 입력 받은 모든 16진수를 2진수로 바꿔 주고 맵 전체를 탐색하면서 문양을 찾으면 된다.
탐색을 할때 flood fill(BFS) 알고리즘을 이용하면 된다.
문양을 찾는 방법은 1을 만날시 방문 체크가 되어있지 않으면 탐색을 시작한다.
탐색을 하다가 0을 만나면 빈 공간이므로 0만 flood fill로 다 탐색을 한다.
그런 식으로 0을 만난 카운트만 세주면 어떤 문양인지 파악 할 수 있게 된다.
문양이 맵 끝에 붙어서 나올수 있으므로 기존 맵의 가로 한칸 세로 한칸씩 늘려서 
문양 밖의 빈공간에서 0을 flood fill 해버리면 문양만 남기 때문에 탐색하기 쉬워진다.
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
        newnode->link = 0;
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
    for(int i = 0; i < 205; i++)
    {
        for(int j = 0; j < 210; j++)
        {
            chk[i][j] = 0;
        }
    }
    for(int i = 0; i < 30; i++)
    {
        result[i] = 0;
    }
}


//0을 만날시 flood fill
void BFS1(int x, int y)
{
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
            //맵 벗어 났는지 확인
            if(next.x < 0 || next.x > 4 * W + 1 || next.y < 0 || next.y > H + 1)
            {
                continue;
            }
            if(zone[next.y][next.x] == '0' && chk[next.y][next.x] == 0)
            {
                chk[next.y][next.x] = 1;
                q.push(next);
            }
        }
    }
}

//1을 만날시 flood fill
void BFS2(int x, int y)
{
    //빈 곳 카운트 변수
    int count = 0;
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
            //맵 벗어 났는지 확인
            if(next.x < 1 || next.x > 4 * W || next.y < 1 || next.y > H)
            {
                continue;
            }
            if(chk[next.y][next.x] == 0)
            {
                //빈 곳 카운트
                if(zone[next.y][next.x] == '0')
                {
                    count++;
                    BFS1(next.x, next.y);
                }
                else
                {
                    q.push(next);
                }
                chk[next.y][next.x] = 1;
            }
        }
    }
    result[shape[count]]++;
}

int main()
{
    int tc = 0;
    while(1)
    {
        tc++;
        init();
        scanf("%d %d", &H, &W);
        if(H == 0 && W == 0)
        {
            break;
        }
        //0으로 초기화, 맵 가로 1칸 세로 1칸 늘려줌
        for(int i = 0; i <= H + 1; i++)
        {
            for(int j = 0; j <= W * 4 + 1; j++)
            {
                zone[i][j] = '0';
            }
        }
        //16진수를 2진수로 바꿈
        for(int i = 1; i <= H; i++)
        {
            int idx = 1;
            for(int j = 1; j <= W; j++)
            {
                char a;
                scanf(" %c", &a);
                for(int k = 0; k < 4; k++)
                {
                    if(a <= '9')
                    {
                        zone[i][idx++] = img[a - '0'][k];
                    }
                    else
                    {
                        zone[i][idx++] = img[a - 'a' + 10][k];
                    }
                }
            }
        }
        //문양 밖의 0들 방문 체크
        BFS1(0, 0);
        //맵 전체 확인
        for(int i = 1; i <= H; i++)
        {
            for(int j = 1; j <= W * 4; j++)
            {
                //1이면 탐색
                if(zone[i][j] == '1' && chk[i][j] == 0)
                {
                    BFS2(j, i);
                }
            }
        }
        printf("Case %d: ", tc);
        for(int i = 0; i < 30; i++)
        {
            for(int j = 0; j < result[i]; j++)
            {
                printf("%c", (char)i + 'A');
            }
        }
        printf("\n");
    }
}