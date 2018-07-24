#include <cstdio>
#include <iostream>
using namespace std;
typedef struct node
{
    int num;
    node *left;
    node *right;
    node()
    {
        left = 0;
        right = 0;
    }
}Node;
Node *Root;
int N;

Node* createNode(int n)
{
    Node *newnode = new Node();
    newnode->num = n;
    return newnode;
}

void insertNode(Node *Cur, Node *newnode)
{
    Node *next;
    if(newnode->num < Cur->num)
    {
        next = Cur->left;
        if(next == 0)
        {
            Cur->left = newnode;
            return;
        }
    }
    else
    {
        next = Cur->right;
        if(next == 0)
        {
            Cur->right = newnode;
            return;
        }
    }
    insertNode(next, newnode);
}

void deleteNode(Node *parent, Node *Cur, int n)
{
    int flag = 0;
    if(Cur == 0)
    {
        return;
    }
    if(Cur->num == n)
    {
        Node *tnode;
        if(Cur->left != 0 && Cur->right != 0)
        {
            tnode = Cur->left;
            flag = 1;
        }
        else if(Cur->left != 0)
        {
            tnode = Cur->left;
        }
        else
        {
            tnode = Cur->right;
        }
        if(parent->left == Cur)
        {
            parent->left = tnode;
        }
        else
        {
            parent->right = tnode;
        }
        if(flag == 1)
        {
            insertNode(Cur->right, tnode->right);
            tnode->right = Cur->right;
        }
        delete Cur;
        return;
    }
    if(n < Cur->num)
    {
        deleteNode(Cur, Cur->left, n);
    }
    else
    {
        deleteNode(Cur, Cur->right, n);
    }
}

int main()
{
    Root = createNode(-1);
}