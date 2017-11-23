//Kosaraju's
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> Forward[10005];
vector<int> Backward[10005];
vector<int> result[10005];
int V, E, chk[10005], rcount;

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

stack<int> s;

void DFS(int node)
{
    for(int i = 0; i < Forward[node].size(); i++)
    {
        if(chk[Forward[node][i]] == 0)
        {
            chk[Forward[node][i]] = 1;
            DFS(Forward[node][i]);
        }
    }
    s.push(node);
}

void DFS2(int node)
{
    for(int i = 0; i < Backward[node].size(); i++)
    {
        if(chk[Backward[node][i]] == 0)
        {
            chk[Backward[node][i]] = 1;
            DFS2(Backward[node][i]);
        }
    }
    result[rcount].push_back(node);
}

int main()
{
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        Forward[s].push_back(e);
        Backward[e].push_back(s);
    }
    for(int i = 1; i <= V; i++)
    {
        if(chk[i] == 0)
        {
            chk[i] = 1;
            DFS(i);
        }
    }
    memset(chk, 0, sizeof chk);
    while(!s.empty())
    {
        if(chk[s.top()] == 0)
        {
            chk[s.top()] = 1;
            DFS2(s.top());
            rcount++;
        }
        s.pop();
    }
    for(int i = 0; i < rcount; i++)
    {
        sort(result[i].begin(), result[i].end());
    }
    sort(result, result + rcount);
    printf("%d\n", rcount);
    for(int i = 0; i < rcount; i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("-1\n");
    }
}




//Tarjan's
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> vec[10005];
vector<int> result[10005];
int V, E, dfsdepth[10005], scc[10005], rcount, depth;

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

stack<int> s;

int DFS(int node)
{
    s.push(node);
    dfsdepth[node] = ++depth;
    int ret = dfsdepth[node];
    for(int i = 0; i < vec[node].size(); i++)
    {
        int next;
        next = vec[node][i];
        if(dfsdepth[next] == 0)
        {
            ret = min(ret, DFS(next));
        }
        else if(scc[next] == 0)
        {
            ret = min(ret, dfsdepth[next]);
        }
    }
    if(ret == dfsdepth[node])
    {
        rcount++;
        while(!s.empty())
        {
            int temp;
            temp = s.top();
            s.pop();
            scc[temp] = rcount;
            result[rcount].push_back(temp);
            if(temp == node)
            {
                break;
            }
        }
    }
    return ret;    
}

int main()
{
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        vec[s].push_back(e);
    }
    for(int i = 1; i <= V; i++)
    {
        if(dfsdepth[i] == 0)
        {
            DFS(i);
        }
    }
    for(int i = 1; i <= rcount; i++)
    {
        sort(result[i].begin(), result[i].end());
    }
    sort(result + 1, result + rcount + 1);
    printf("%d\n", rcount);
    for(int i = 1; i <= rcount; i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("-1\n");
    }
}