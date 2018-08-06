#include <cstdio>
#include <iostream>
using namespace std;
int N, A[50005], result[50005];

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
        Node(T Data)
        {
            data = Data;
            priority = rand();
            size = 1;
            left = NULL;
            right = NULL;
        }
        void setLeft(Node *newnode)
        {
            left = newnode;
            calcSize();
        }
        void setRight(Node *newnode)
        {
            right = newnode;
            calcSize();
        }
        void calcSize()
        {
            size = 1;
            if(left != 0)
            {
                size += left->size;
            }
            if(right != 0)
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
        Node *newnode;
        newnode = new Node(data);
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
    Node* insert(Node *cur, Node *node)
    {
        if(cur == NULL)
        {
            return node;
        }
        if(cur->priority < node->priority)
        {
            NodePair temp = split(cur, node->data);
            node->setLeft(temp.first);
            node->setRight(temp.second);
            return node;
        }
        else if(cur->data < node->data)
        {
            cur->setRight(insert(cur->right, node));
        }
        else
        {
            cur->setLeft(insert(cur->left, node));
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
        if(a->priority < b->priority)
        {
            b->setLeft(merge(a, b->left));
            return b;
        }
        a->setRight(merge(a->right, b));
        return a;
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
        if(cur->data < data)
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

Treap<int> treap;

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        treap.clear(treap.root);
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &A[i]);
            treap.root = treap.insert(treap.root, treap.createNode(i + 1));
        }
        for(int i = N - 1; i >= 0; i--)
        {
            int idx;
            idx = i - A[i];
            result[i] = treap.kth(treap.root, idx + 1)->data;
            treap.root = treap.erase(treap.root, result[i]);
        }
        for(int i = 0; i < N; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
}