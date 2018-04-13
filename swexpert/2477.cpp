#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int Time, afterTime, humanidx;
}Data;
typedef struct _data2
{
    int humanidx, receptnum;
}Data2;
Data reception[15], repair[15];
int N, M, K, A, B, Human[1005], Time = 0, result;

/*
주어진 조건에 맞게 시뮬레이션 돌리면 된다.
접수창에 도착 하면 큐에 넣어주고 접수창이 비어있으면 큐에서 빼서 접수창에 넣는다.
접수 완료하면 큐에 넣어주고 수리창이 비어있으면 큐에서 빼서 수리창에 넣는다.
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

queue<Data2>q1;
queue<Data2>q2;

void init()
{
    for(int i = 1; i <= 10; i++)
    {
        reception[i].afterTime = 0;
        reception[i].humanidx = -1;
        repair[i].afterTime = 0;
        repair[i].humanidx = -1;
    }
    result = 0;
}

//접수창 구현
void receptfunc()
{
    for(int i = 1; i <= N; i++)
    {
        //접수창 안비었을 경우
        if(reception[i].afterTime > 0)
        {
            reception[i].afterTime--;
            //작업 완료
            if(reception[i].afterTime == 0)
            {
                Data2 Push;
                Push.humanidx = reception[i].humanidx;
                Push.receptnum = i;
                reception[i].humanidx = -1;
                //수리창으로 가는 큐에 푸쉬
                q2.push(Push);
            }            
        }
        //접수창 비었을 경우
        else
        {
            //접수창으로 가는 큐에 데이터가 있을 경우
            if(q1.size() > 0)
            {
                Data2 temp;
                temp = q1.front();
                q1.pop();
                reception[i].afterTime = reception[i].Time - 1;
                reception[i].humanidx = temp.humanidx;
                if(reception[i].afterTime == 0)
                {
                    Data2 Push;
                    Push.humanidx = reception[i].humanidx;
                    Push.receptnum = i;
                    reception[i].humanidx = -1;
                    q2.push(Push);
                }
            }
        }
    }
}

//수리창 구현
void repairfunc()
{
    for(int i = 1; i <= M; i++)
    {
        if(repair[i].afterTime > 0)
        {
            repair[i].afterTime--;
        }
        else
        {
            if(q2.size() > 0)
            {
                Data2 temp;
                temp = q2.front();
                q2.pop();
                repair[i].afterTime = repair[i].Time - 1;
                repair[i].humanidx = temp.humanidx;
                if(temp.receptnum == A && i == B)
                {
                    result += temp.humanidx;
                }
            }
        }
    }
}

//시뮬레이션
void func()
{
    Time = Human[1];
    for(int i = 1; i <= K;)
    {
        for(int j = i; j <= K; j++)
        {
            //차량 정비소에 도착했을시
            if(Time == Human[j])
            {
                i = j + 1;
                Data2 Push;
                Push.humanidx = j;
                Push.receptnum = 0;
                q1.push(Push);
            }
            else
            {
                break;
            }
        }
        repairfunc();
        receptfunc();
        Time++;
    }
    while(1)
    {
        int receptflag = 0;
        for(int i = 1; i <= N; i++)
        {
            if(reception[i].humanidx != -1)
            {
                receptflag = 1;
                break;
            }
        }
        if(receptflag == 0 && q1.empty() == 1 && q2.empty() == 1)
        {
            break;
        }
        repairfunc();
        receptfunc();
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        init();
        scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &reception[i].Time);
        }
        for(int i = 1; i <= M; i++)
        {
            scanf("%d", &repair[i].Time);
        }
        for(int i = 1; i <= K; i++)
        {
            scanf("%d", &Human[i]);
        }
        func();
        if(result == 0)
        {
            result = -1;
        }
        printf("#%d %d\n", testcase, result);
    }
}


//나중에 푼것

#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef struct _data
{
	int idx;
	int before;
}Data;
typedef struct _data2
{
	int idx;
	int Time;
}Data2;
Data2 Receptarr[15], Repairarr[15];
int N, M, K, A, B, Recept[15], Repair[15], Human[1005], result;

void func()
{
	int Time, Count = 0;
	Time = -1;
	queue<int>waitq;
	queue<Data>waitq2;
	for (int i = 0; i < N; i++)
	{
		Receptarr[i].idx = -1;
	}
	for (int i = 0; i < M; i++)
	{
		Repairarr[i].idx = -1;
	}
	for (int i = 0; ;)
	{
		Time++;
		if (Count == K)
		{
			break;
		}
		for (int j = i; j < K; j++)
		{
            //차량 정비소에 도착시
			if (Human[j] == Time)
			{
				waitq.push(j);
				i++;
			}
			else
			{
				break;
			}
		}
        //수리창 작업 완료 된것들 빼줌
		for (int j = 0; j < M; j++)
		{
			if (Repairarr[j].idx != -1 && Repairarr[j].Time == Time)
			{
				Repairarr[j].idx = -1;
				Count++;
			}
		}
        //접수창 작업 완료 된것들 빼줌
		for (int j = 0; j < N; j++)
		{
			if (Receptarr[j].idx != -1 && Receptarr[j].Time == Time)
			{
                //수리창으로 가는 큐에 푸쉬
				waitq2.push({ Receptarr[j].idx, j });
				Receptarr[j].idx = -1;
			}
		}
		while (!waitq.empty())
		{
			int flag = 0;
			for (int j = 0; j < N; j++)
			{
                //접수창 비었을 경우
				if (Receptarr[j].idx == -1)
				{
					int temp;
					temp = waitq.front();
					waitq.pop();
					Receptarr[j].idx = temp;
					Receptarr[j].Time = Time + Recept[j];
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				break;
			}
		}
		while (!waitq2.empty())
		{
			int flag = 0;
			for (int j = 0; j < M; j++)
			{
                //수리창 비었을 경우
				if (Repairarr[j].idx == -1)
				{
					Data temp;
					temp = waitq2.front();
					waitq2.pop();
					Repairarr[j].idx = temp.idx;
					Repairarr[j].Time = Time + Repair[j];
					flag = 1;
					if (temp.before == A && j == B)
					{
						result += temp.idx + 1;
					}
					break;
				}
			}
			if (flag == 0)
			{
				break;
			}
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
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
		A--;
		B--;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &Recept[i]);
		}
		for (int i = 0; i < M; i++)
		{
			scanf("%d", &Repair[i]);
		}
		for (int i = 0; i < K; i++)
		{
			scanf("%d", &Human[i]);
		}
		func();
		if (result == 0)
		{
			result = -1;
		}
		printf("#%d %d\n", testcase, result);
	}
}