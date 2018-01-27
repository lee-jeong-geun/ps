#include <cstdio>
#include <iostream>
using namespace std;

//트라이 노드
typedef struct node
{
    int branchflag;
    int lastflag;
    node *link[30];
    ~node()
    {
        for(int i = 0; i < 27; i++)
        {
            delete link[i];
            link[i] = NULL;
        }
    }
}Node;

/*
처음에 문자열을 입력받을때 트라이에 다 저장하고
그다음에 문자열을 각각 트라이에서 탐색한다.
탐색할때 분기가 있거나 현재 탐색하는 문자열에 다른 문자열이 속해 있을때
카운트를 1씩 더해준다.
예를 들어 hello와 hell의 경우 분기는 없지만 hello를 탐색할때 hell이 hello에 속해있으므로
카운트 해준다.
*/

char str[100005][85];
int N, length, result;

Node *Root;

//노드 생성
Node* createNode()
{
    Node *newnode = new Node();
    newnode->branchflag = 0;
    newnode->lastflag = 0;
    for(int i = 0; i < 27; i++)
    {
        newnode->link[i] = NULL;
    }
    return newnode;
}

void init()
{
    if(Root == NULL)
    {
        Root = createNode();
        return;
    }
    for(int i = 0; i < 27; i++)
    {
        if(Root->link[i] != NULL)
        {
            delete Root->link[i];
            Root->link[i] = NULL;
        }
    }
    result = 0;
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

//트라이에 푸쉬
void push(Node *Cur, char *Str, int depth)
{
    //문자열이 마지막이라면 체크
    if(Str[depth] == NULL)
    {
        Cur->lastflag = 1;
        return;
    }
    //트라이에 없는 문자라면 생성
    if(Cur->link[Str[depth] - 'a'] == NULL)
    {
        Cur->branchflag++;
        Cur->link[Str[depth] - 'a'] = createNode();
    }
    //다음 노드로 이동
    push(Cur->link[Str[depth] - 'a'], Str, depth + 1);
}

//트라이에서 탐색
void searchNode(Node *Cur, char *Str, int depth)
{
    //마지막이라면 리턴
    if(Str[depth] == NULL)
    {
        return;
    }
    //분기가 있거나 다른 문자열이 해당 문자열에 속해 있다면 카운트 증가
    if((Cur->branchflag > 1 || Cur->lastflag == 1))
    {
        result++;
    }
    //다음 노드로 이동
    searchNode(Cur->link[Str[depth] - 'a'], Str, depth + 1);
}

int main()
{
    while(scanf("%d", &N) != -1)
    {
        init();
        for(int i = 0; i < N; i++)
        {
            scanf("%s", str[i]);
            length = strlen(str[i]);
            push(Root, str[i], 0);
        }
        for(int i = 0; i < N; i++)
        {
            searchNode(Root, str[i], 0);
        }
        printf("%0.2f\n", (double)result / N);
    }
}