#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, L, Number[5000005];

/*
이 문제는 각 구간에서 최소값이 어떤건지 빠르게 찾아내면 된다.
구간의 최소값을 빠르게 찾는 세그먼트 트리를 이용 할 수 있지만 N이 5000000개나 되므로
세그먼트 트리말고 다른 해법을 찾아야 한다.
덱을 이용하면 O(N)만에 문제를 해결 할 수 있다.
덱에 그 구간에서 확실하게 최소일 경우만 집어 넣는다.
예제를 보면 1 5 2 3 6 2 3 7 3 5 2 6이 있는데
1은 그 구간에서 확실하게 최소라서 덱에 넣는다.
5도 그 구간에서 확실하게 최소라서 덱에 넣는다.
이제 2가 들어오면 5는 2보다 크므로 덱에서 제거 해야 한다. 제거 후 2를 넣는다.  그럼 현재 덱 상황은 1 2다.
3을 확인 할 때 1은 구간에서 아웃이 되므로 제거하고 3을 넣는다. 현재 덱 상황은 2 3이다.
6은 그 구간에서 확실하게 최소라서 덱에 넣는다. 덱 상황 2 3 6
2를 넣을때 덱 맨앞에 2는 구간에서 아웃이 되므로 제거하고 2를 덱에 넣는다.
넣을때 3 6은 2보다 크므로 3 6을 제거하고 2를 넣는다.   덱 상황 2
이런 식으로 O(N)만에 확인 가능하다.
*/

//덱 구현
template<typename T>
class deque
{
public:
    class Node
    {
    public:
        T data;
        Node *flink, *blink;
        Node()
        {
            flink = 0;
            blink = 0;
        }
    };
    int _size;
    Node *Front, *Rear;
    deque()
    {
        _size = 0;
        Front = 0;
        Rear = 0;
    }
    void push(T data)
    {
        _size++;
        Node *newnode;
        newnode = new Node();
        newnode->data = data;
        if(_size == 1)
        {
            Front = newnode;
            Rear = newnode;
        }
        else
        {
            Rear->blink = newnode;
            newnode->flink = Rear;
            Rear = newnode;
        }
    }
    void fpop()
    {
        _size--;
        Node *tnode;
        tnode = Front;
        Front = Front->blink;
        delete tnode;
    }
    void rpop()
    {
        _size--;
        Node *tnode;
        tnode = Rear;
        Rear = Rear->flink;
        delete tnode;
    }
    T front()
    {
        return Front->data;
    }
    T rear()
    {
        return Rear->data;
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

deque<int>dq;

int main()
{
    scanf("%d %d", &N, &L);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Number[i]);
    }
    for(int i = 0; i < N; i++)
    {
        //구간 아웃인걸 확인
        if(i - L >= 0 && dq.size() > 0 && Number[i - L] == dq.front())
        {
            dq.fpop();
        }
        //덱에 값을 넣기전 자기보다 큰 값들 제거
        while(!dq.empty())
        {
            int temp;
            temp = dq.rear();
            //자기보다 작으면 종료
            if(temp <= Number[i])
            {
                break;
            }
            dq.rpop();
        }
        dq.push(Number[i]);
        printf("%d ", dq.front());
    }
}