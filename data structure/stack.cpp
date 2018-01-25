#include <cstdio>
#include <iostream>
using namespace std;

/*
linked list stack(template)
*/
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


/*
array stack(template)
*/
template<typename T>
class stack
{
public:
    T _stack[105];
    int Top;
    stack()
    {
        Top = 0;
    }
    void push(T data)
    {
        _stack[++Top] = data;
    }
    void pop()
    {
        Top--;
    }
    T top()
    {
        return _stack[Top];
    }
    int size()
    {
        return Top;
    }
    bool empty()
    {
        return Top == 0;
    }
};



int main()
{
    
}