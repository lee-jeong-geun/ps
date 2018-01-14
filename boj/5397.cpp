#include <cstdio>
#include <iostream>
using namespace std;
char L[1000005], result[1000005];
int idx;

/*
스택 두개를 이용해서 < 입력을 받으면 첫번째 스택 top에 있는 값을 두번째 스택에 푸쉬 하였고
> 입력을 받으면 두번째 스택 top에 있는 값을 첫 번째 스택에 푸쉬 하는 방식으로 풀었다.
- 입력은 첫 번째 스택에서 pop을 하였다.
<, >, - 입력 모두 스택에서 값을 넣고 빼기 때문에 스택에 데이터 존재 여부를 확인 해야한다.
*/

//스택 구현
template<typename T>
class stack
{
public:
    class Node
    {
    public:
        T data;
        Node *link;
    };
    int _size;
    Node *Top;
    stack()
    {
        _size = 0;
        Top = NULL;
    }
    void push(T data)
    {
        _size++;
        Node *newnode = new Node();
        newnode->data = data;
        newnode->link = Top;
        Top = newnode;
    }
    void pop()
    {
        _size--;
        Node *tnode;
        tnode = Top;
        Top = Top->link;
        delete tnode;
    }
    T top()
    {
        return Top->data;
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
stack<char> s1, s2;

void init()
{
    while(!s1.empty())
    {
        s1.pop();
    }
    while(!s2.empty())
    {
        s2.pop();
    }
    idx = 0;
}

int strlen(char *str)
{
    int len = 0;
    while(*str != 0)
    {
        len++;
        str++;
    }
    return len;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        init();
        scanf("%s", L);
        int length;
        length = strlen(L);
        for(int i = 0; i < length; i++)
        {
            if(L[i] == '<')
            {
                //첫번째 스택에 데이터가 있을 경우
                if(s1.size() != 0)
                {
                    //첫번째 스택 top에 있는 값을 두번째 스택에 push
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            else if(L[i] == '>')
            {
                //두번째 스택에 데이터가 있을 경우
                if(s2.size() != 0)
                {
                    //두번째 스택 top에 있는 값을 첫번째 스택에 push
                    s1.push(s2.top());
                    s2.pop();
                }
            }
            else if(L[i] == '-')
            {
                //첫번째 스택에 데이터가 있을 경우 pop 해줌
                if(s1.size() != 0)
                {
                    s1.pop();
                }
            }
            else
            {
                //나머지 데이터는 첫번째 스택에 푸쉬
                s1.push(L[i]);
            }
        }
        //스택은 후입 선출이기 때문에 데이터를 바로 출력하면 역순으로 출력 됨
        while(!s1.empty())
        {
            //임시 배열에다가 데이터를 넣음
            result[idx++] = s1.top();
            s1.pop();
        }
        //임시 배열의 역순으로 출력
        for(int i = idx - 1; i >= 0; i--)
        {
            printf("%c", result[i]);
        }
        //두번째 스택은 데이터를 역순으로 push했기 때문에 바로 출력 하면 됨
        while(!s2.empty())
        {
            printf("%c", s2.top());
            s2.pop();
        }
        printf("\n");
    }
}