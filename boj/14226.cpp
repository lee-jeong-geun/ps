#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int count, copy, weight;
}Data;
int S, chk[1105][505], result = 987654321;

/*
각각의 상태에서 할 수 있는것은 클립보드에 저장, 붙여넣기, 삭제이다.
최소 연산을 구하기 위해 BFS를 이용하면 된다.
chk[이모티콘 개수][클립보드 저장된 개수]를 이용하여 방문체크를 하면 된다.
*/

void BFS()
{
    queue<Data>q;
    q.push({1, 0, 0});
    chk[0][0] = 1;
    chk[1][0] = 1;
    while(!q.empty())
    {
        Data temp;
        temp = q.front();
        q.pop();
        if(temp.count >= S)
        {
            result = min(result, temp.weight + temp.count - S);
            continue;
        }
        //최적화
        if(temp.weight + 1 >= result)
        {
            continue;
        }
        //클립보드에 저장
        if(chk[temp.count][temp.count] == 0)
        {
            chk[temp.count][temp.count] = 1;
            q.push({temp.count, temp.count, temp.weight + 1});
        }
        //붙여넣기
        if(temp.count + temp.copy <= 1100 && chk[temp.count + temp.copy][temp.copy] == 0)
        {
            chk[temp.count + temp.copy][temp.copy] = 1;
            q.push({temp.count + temp.copy, temp.copy, temp.weight + 1});
        }
        //삭제
        if(temp.count - 1 >= 0 && chk[temp.count - 1][temp.copy] == 0)
        {
            chk[temp.count - 1][temp.copy] = 1;
            q.push({temp.count - 1, temp.copy, temp.weight + 1});
        }
    }
}

int main()
{
    scanf("%d", &S);
    BFS();
    printf("%d", result);
}