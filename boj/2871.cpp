#include <bits/stdc++.h>
using namespace std;
queue<int> q[30];
string result[5];
int N;
char word[100005];

/*
희원이는 사전 순으로 가장 빠르게 만드는 것이 중요하다. 또 상근이를 견제하기 위해
상근이가 뽑아야 할 단어 위주로 뽑도록 하면 된다. 각 단어를 26개 큐에 알파벳별로 넣는다.
넣을 때 뒤에 단어들부터 넣으면 된다. 뽑을 때는 상근이는 맨 뒤의 단어를 뽑으면 되고 희원이는
0 ~ 25까지의 큐를 차례대로 탐색하면서 원소가 존재하면 그 단어를 뽑으면 된다.
*/

int findWord(int idx)
{
    while(word[idx] == 0)
    {
        idx--;
    }
    return idx;
}

int findWord2()
{
    for(int i = 0; i < 26; i++)
    {
        if(q[i].size() > 0)
            return q[i].front();
    }
}

int main()
{
    scanf("%d %s", &N, word);
    for(int i = N - 1; i >= 0; i--)
    {
        q[word[i] - 'a'].push(i);
    }
    for(int i = 0, j = N - 1; i < N; i++)
    {
        if(i % 2 == 0)
        {
            int idx = findWord(j);
            result[1] += word[idx];
            q[word[idx] - 'a'].pop();
            j = idx - 1;
        }
        else
        {
            int idx = findWord2();
            result[0] += word[idx];
            q[word[idx] - 'a'].pop();
            word[idx] = 0;
        }
    }
    if(result[1] <= result[0])
        printf("NE\n");
    else
        printf("DA\n");
    cout << result[0];
}