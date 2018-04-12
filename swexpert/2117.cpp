#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int x, y;
}Data;
int N, M, zone[25][25], chk[25][25], result;
int arrA[4] = {0, 0, 1, -1};
int arrB[4] = {1, -1, 0, 0};

/*
맵 전체의 각각 좌표에서 BFS를 타면서 집 발견 될때 마다 카운트 해주고
운영 비용 이상이면 최대 집의 값을 갱신 해준다.
*/

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

//맵밖 인지 확인
int range(int a, int b)
{
    if(a >= 0 && a < N && b >= 0 && b < N)
    {
        return 1;
    }
    return 0;
}

//운영 비용과 수익 확인
bool costchk(int o, int h)
{
    int hap;
    hap = o * o + (o - 1) * (o - 1);
    if(h * M >= hap)
    {
        return 1;
    }
    return 0;
}

void BFS(int x, int y)
{
    int opcount = 0, hcount = 0, qsize;
    Data First;
    First.x = x;
    First.y = y;
    queue<Data>q;
    chk[y][x] = 1;
    q.push(First);
    while(opcount < 2 * N)
    {
        qsize = q.size();
        while(qsize > 0)
        {
            qsize--;
            Data temp;
            temp = q.front();
            q.pop();
            if(zone[temp.y][temp.x] == 1)
            {
                hcount++;
            }
            for(int i = 0; i < 4; i++)
            {
                Data next;
                next.x = temp.x + arrA[i];
                next.y = temp.y + arrB[i];
                if(range(next.x, next.y) == 1 && chk[next.y][next.x] == 0)
                {
                    chk[next.y][next.x] = 1;
                    q.push(next);
                }
            }
        }
        opcount++;
        if(costchk(opcount, hcount) == 1)
        {
            result = max(result, hcount);
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        result = 0;
        scanf("%d %d", &N, &M);
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                scanf("%d", &zone[i][j]);
            }
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                BFS(j, i);
                memset(chk, 0, sizeof chk);
            }
        }
        printf("#%d %d\n", testcase, result);
    }
}



//나중에 짠것




#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef struct _data
{
	int x, y;
}Data;
int N, M, zone[25][25], chk[25][25], result;
int arrA[4] = { 0, 0, 1, -1 };
int arrB[4] = { 1, -1, 0, 0 };

bool range(int a, int b)
{
	if (a >= 0 && a < N && b >= 0 && b < N)
	{
		return 1;
	}
	return 0;
}

void BFS(int x, int y)
{
	int hcount = 0, Kcount = 0;
	queue<Data>q;
	q.push({ x, y });
	chk[y][x] = 1;
	hcount = zone[y][x];
	while (!q.empty())
	{
		int qcount;
		qcount = q.size();
		Kcount++;
		int temp;
		temp = Kcount * Kcount + (Kcount - 1) * (Kcount - 1);
		if (temp <= hcount * M)
		{
			result = max(result, hcount);
		}
		while (qcount != 0)
		{
			qcount--;
			Data temp;
			temp = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				Data next;
				next.x = temp.x + arrA[i];
				next.y = temp.y + arrB[i];
				if (range(next.x, next.y) == 1 && chk[next.y][next.x] == 0)
				{
					if (zone[next.y][next.x] == 1)
					{
						hcount++;
					}
					chk[next.y][next.x] = 1;
					q.push(next);
				}
			}
		}
		if (Kcount == N + 1)
		{
			return;
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		result = 0;
		memset(chk, 0, sizeof chk);
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &zone[i][j]);
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				memset(chk, 0, sizeof chk);
				BFS(j, i);
			}
		}
		printf("#%d %d\n", testcase, result);
	}
}