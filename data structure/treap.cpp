#include <cstdio>
#include <iostream>
using namespace std;

template<typename T>
class Treap
{
public:
    class Node
    {
    public:
        T data;
        int priority, size;
        Node *left, *right;
        Node(T _data)
        {
            data = _data;
            priority = rand();
            size = 1;
            left = NULL;
            right = NULL;
        }
        void setLeft(Node *newnode)
        {
            left = newnode;
            calcsize();
        }
        void setRight(Node *newnode)
        {
            right = newnode;
            calcsize();
        }
        void calcsize()
        {
            size = 1;
            if(left != NULL)
            {
                size += left->size;
            }
            if(right != NULL)
            {
                size += right->size;
            }
        }
    };
    Node *root;
    Treap()
    {
        root = NULL;
    }
    Node* createNode(T data)
    {
        Node *newnode = new Node(data);
        return newnode;
    }

    typedef pair<Node*, Node*> NodePair;

    NodePair split(Node *cur, T data)
    {
        if(cur == NULL)
        {
            return NodePair(NULL, NULL);
        }
        if(cur->data < data)
        {
            NodePair temp = split(cur->right, data);
            cur->setRight(temp.first);
            return NodePair(cur, temp.second);
        }
        NodePair temp = split(cur->left, data);
        cur->setLeft(temp.second);
        return NodePair(temp.first, cur);
    }

    Node* insert(Node *cur, Node *newnode)
    {
        if(cur == NULL)
        {
            return newnode;
        }
        if(cur->priority < newnode->priority)
        {
            NodePair temp = split(cur, newnode->data);
            newnode->setLeft(temp.first);
            newnode->setRight(temp.second);
            return newnode;
        }
        else if(cur->data < newnode->data)
        {
            cur->setRight(insert(cur->right, newnode));
        }
        else
        {
            cur->setLeft(insert(cur->left, newnode));
        }
        return cur;
    }

    Node* merge(Node *a, Node *b)
    {
        if(a == NULL)
        {
            return b;
        }
        if(b == NULL)
        {
            return a;
        }
        if(a->priority > b->priority)
        {
            a->setRight(merge(a->right, b));
            return a;
        }
        b->setLeft(merge(a, b->left));
        return b;
    }

    Node* erase(Node *cur, T data)
    {
        if(cur == NULL)
        {
            return cur;
        }
        if(cur->data == data)
        {
            Node *temp = merge(cur->left, cur->right);
            delete cur;
            return temp;
        }
        else if(cur->data < data)
        {
            cur->setRight(erase(cur->right, data));
        }
        else
        {
            cur->setLeft(erase(cur->left, data));
        }
        return cur;
    }

    Node* kth(Node *cur, int num)
    {
        int leftSize = 0;
        if(cur->left != NULL)
        {
            leftSize = cur->left->size;
        }
        if(num <= leftSize)
        {
            return kth(cur->left, num);
        }
        if(num == leftSize + 1)
        {
            return cur;
        }
        return kth(cur->right, num - leftSize - 1);
    }
    
    void clear(Node *cur)
    {
        if(cur == NULL)
        {
            return;
        }
        clear(cur->left);
        clear(cur->right);
        delete cur;
    }
};