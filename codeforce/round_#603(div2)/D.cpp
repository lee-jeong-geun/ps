#include <bits/stdc++.h>
using namespace std;
int n, chk[30], parent[30], result[30], resultCount;
string word;

/*
문자열 a와 문자열 b 사이에서 같은 문자가 한개라도 존재시 같은 그룹이 된다.
따라서 문자열의 순서는 필요없고 문자의 존재 여부만 필요하게 된다.
문자열을 입력 받으면서 각각의 문자에 대해서 같은 그룹으로 맺어 주고 몇개의 그룹이 나왔는지
확인하면 된다.
*/

int find(int node)
{
    if(parent[node] == node)
        return node;
    return parent[node] = find(parent[node]);
}

void uni(int node1, int node2)
{
    node1 = find(node1);
    node2 = find(node2);
    if(node1 != node2)
        parent[node2] = node1;
}

int main()
{
    for(int i = 0; i < 26; i++)
    {
        parent[i] = i;
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        cin >> word;
        for(int j = 0; j < word.size(); j++)
        {
            //해당 문자 존재 체크
            chk[word[j] - 'a'] = 1;
        }
        for(int j = 0; j < word.size() - 1; j++)
        {
            //같은 그룹으로 묶어줌
            uni(word[j] - 'a', word[j + 1] - 'a');
        }
    }
    for(int i = 0; i < 26; i++)
    {
        //해당 문자가 존재하는 문자라면 그 문자의 그룹을 체크
        if(chk[i] == 1)
            result[find(i)] = 1;
    }
    for(int i = 0; i < 26; i++)
    {
        //체크된 그룹이 몇개있는지 확인
        if(result[i] == 1)
            resultCount++;
    }
    printf("%d", resultCount);
}