#include <cstdio>
#include <iostream>
using namespace std;
typedef struct node
{
    int hcount;
    int length;
    node *link;
    node()
    {
        link = 0;
    }
}Node;
Node pool[4400005];
int poolIdx;

/*
각구간들을 순서 상관 없이 알파벳 존재 여부로 해싱 해버린다.
해시를 할 때 기존에는 해시값에 소수를 곱하고 현재 문자를 더하는 방식으로 하였지만
순서가 필요 없기 때문에 문자를 더하지 않고 해시값에 소수만 곱해준다.
이때 각각의 문자에 고유한 소수를 부여 해서 해시값에 곱 한다면
해당 문자가 구간에 존재 한다는 것을 나타 낼 수 있다.
그리고 나올 수 있는 구간의 수가 많기 때문에 중복될 확률도 높다.
따라서 이중 해싱을 해서 첫번째 해시값이 같다면 두번째 해시값을 확인해서 동일한지 아닌지 확인한다.
*/

Node* alloc()
{
    return &pool[poolIdx++];
}
int prime[65] = {10007, 10009, 10037, 10039, 10061, 10067, 10069, 10079, 
10091, 10093, 10099, 10103, 10111, 10133, 10139, 10141, 10151, 10159, 10163, 
10169, 10177, 10181, 10193, 10211, 10223, 10243, 500009, 500029, 500041, 500057, 
500069, 500083, 500107, 500111, 500113, 500119, 500153, 500167, 500173, 500177, 
500179, 500197, 500209, 500231, 500233, 500237, 500239, 500249, 500257, 500287, 
500299, 500317, 500321, 500333, 500341};
int Mod = 2000003, Mod2 = 1000000007, result;
char SA[1505], SB[1505];

int max(int a, int b)
{
    return a > b ? a : b;
}

typedef struct listnode
{
    Node *Head;
    listnode()
    {
        Head = alloc();
        Head->hcount = -1;
        Head->length = -1;
        Head->link = 0;
    }
    void insertNode(int hcount, int length)
    {
        Node *newnode;
        newnode = alloc();
        newnode->hcount = hcount;
        newnode->length = length;
        newnode->link = Head->link;
        Head->link = newnode;
    }
    int searchNode(int hcount, int length)
    {
        Node *tnode;
        tnode = Head->link;
        while(tnode != 0)
        {
            //두번째 해시값이 같다면 동일
            if(tnode->hcount == hcount && tnode->length == length)
            {
                return 1;
            }
            tnode = tnode->link;
        }
        return 0;
    }
}List;
List list[2000015];

int main()
{
    scanf("%s %s", SA, SB);
    for(int i = 0; SA[i] != 0; i++)
    {
        long long hcount = 1, hcount2 = 1;
        for(int j = i; SA[j] != 0; j++)
        {
            hcount = (hcount * prime[SA[j] - 'a']) % Mod;
            hcount2 = (hcount2 * prime[SA[j] - 'a' + 26]) % Mod2;
            //같은게 없다면 리스트에 저장
            if(list[hcount].searchNode(hcount2, j - i + 1) == 0)
            {
                list[hcount].insertNode(hcount2, j - i + 1);
            }
        }
    }
    for(int i = 0; SB[i] != 0; i++)
    {
        long long hcount = 1, hcount2 = 1;
        for(int j = i; SB[j] != 0; j++)
        {
            hcount = (hcount * prime[SB[j] - 'a']) % Mod;
            hcount2 = (hcount2 * prime[SB[j] - 'a' + 26]) % Mod2;
            if(list[hcount].searchNode(hcount2, j - i + 1) == 1)
            {
                result = max(result, j - i + 1);
            }
        }
    }
    printf("%d", result);
}