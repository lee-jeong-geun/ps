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

Node* insertNode(Node *Cur, Node *newnode)
{
    if(Cur == 0)
    {
        return newnode;
    }
    if(newnode->num < Cur->num)
    {
        Cur->left = insertNode(Cur->left, newnode);
    }
    else
    {
        Cur->right = insertNode(Cur->right, newnode);
    }
    return Cur;
}

Node* deleteNode(Node *Cur, int n)
{
    int flag = 0;
    if(Cur == 0)
    {
        return Cur;
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
        if(flag == 1)
        {
            tnode->right = insertNode(tnode->right, Cur->right);
        }
        delete Cur;
        return tnode;
    }
    if(n < Cur->num)
    {
        Cur->left = deleteNode(Cur->left, n);
    }
    else
    {
        Cur->right = deleteNode(Cur->right, n);
    }
    return Cur;
}

int main()
{
    Root = createNode(-1);
}