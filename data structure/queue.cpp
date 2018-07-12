#include <cstdio>
#include <iostream>
using namespace std;

/*
linked list queue(template)
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

/*
array queue(template)
*/

template<typename T>
class queue
{
public:
    T *arr;
    int Front, Rear, _size;
    queue()
    {
        _size = 0;
        Front = 0;
        Rear = 0;
        arr = new T[100];
    }
    void push(T data)
    {
        _size++;
        Rear = (Rear + 1) % 100;
        arr[Rear] = data;
    }
    void pop()
    {
        _size--;
        Front = (Front + 1) % 100;
    }
    T front()
    {
        return arr[(Front + 1) % 100];
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

int main()
{
    
}