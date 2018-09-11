#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct _data
{
    char word[15];
    int p;
}Data;
Data Word[10005];

typedef struct node
{
    int idx;
    int flag;
    node *link[26];
    node()
    {
        idx = -1;
        flag = -1;
        for(int i = 0; i < 26; i++)
        {
            link[i] = NULL;
        }
    }
    ~node()
    {
        for(int i = 0; i < 26; i++)
        {
            delete link[i];
        }
    }
}Node;

typedef struct nodeTrie
{
    int result;
    Node *Root;
    nodeTrie()
    {
        result = 0;
        Root = new Node();
        Root->idx = -2;
    }
    void insertNode(Node *Cur, char *str, int num, int idx)
    {
        if(Cur->idx != -2)
        {
            if(Cur->idx == -1 || Word[Cur->idx].p < num)
            {
                Cur->idx = idx;
            }
            else if(Word[Cur->idx].p == num && strcmp(Word[Cur->idx].word, Word[idx].word) > 0)
            {
                Cur->idx = idx;
            }
        }
        if(*str == 0)
        {
            Cur->flag = idx;
            return;
        }
        if(Cur->link[*str - 'A'] == 0)
        {
            Cur->link[*str - 'A'] = new Node();
        }
        insertNode(Cur->link[*str - 'A'], str + 1, num, idx);
    }
    int searchNode(Node *Cur, char *str)
    {
       if(*str == 0)
       {
           return Cur->flag;
       }
       if(Cur->link[*str - 'A'] == 0)
       {
           return -1;
       }
       return searchNode(Cur->link[*str - 'A'], str + 1);
    }
    int tabNode(Node *Cur, char *str, int wordidx)
    {
        if(*str == 0)
        {
            return 0;
        }
        if(Cur->idx == wordidx)
        {
            return 1;
        }
        return tabNode(Cur->link[*str - 'A'], str + 1, wordidx) + 1;
    }
    void clear()
    {
        result = 0;
        delete Root;
        Root = new Node();
        Root->idx = -2;
    }
}Trie;
Trie trie;
int N, M;

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        trie.clear();
        scanf("%d %d", &N, &M);
        for(int i = 0; i < N; i++)
        {
            scanf("%s %d", Word[i].word, &Word[i].p);
            trie.insertNode(trie.Root, Word[i].word, Word[i].p, i);
        }
        for(int i = 0; i < M; i++)
        {
            int temp;
            char word[15];
            scanf("%s", word);
            temp = trie.searchNode(trie.Root, word);
            if(temp == -1)
            {
                trie.result += strlen(word);
            }
            else
            {
                trie.result += trie.tabNode(trie.Root, word, temp);
            }
        }
        printf("%d\n", trie.result + M - 1);
    }
}