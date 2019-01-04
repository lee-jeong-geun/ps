#include <cstdio>
#include <iostream>
using namespace std;
int N, M, arr[100005], parent[100005], result;

/*
규칙을 잘 찾아보면 연산들끼리 연결 될 경우 해당 인덱스들은 연결된 모든 위치로 이동 가능하다.
연산이 1-3, 1-4일 경우 1, 3, 4 인덱스에 위치한 수들은 1, 3, 4 모두 이동이 가능 하다.
1-3-4 이렇게 연결 되어있는 집합에 5-6을 연결 시킬 경우 1-3-4-5-6 모두 이동이 가능하다.
모든 연산들을 그룹화 시켜서 연결 가능한 그룹들을 계속해서 연결 시킨다. 그룹들을 관리하기 쉬운 
알고리즘인 유니온 파인드를 이용하였다. 연결을 다 시킨 후 p배열에 수 pi에 대하여 i에 이동 가능한지
판별하는 것은 해당 pi가 위치해 있는 인덱스와 i인덱스가 연결 되어 있는지 확인하면 된다.
*/

int find(int node)
{
    if(node == parent[node])
    {
        return node;
    }
    return parent[node] = find(parent[node]);
}

void uni(int node1, int node2)
{
    int p1, p2;
    p1 = find(node1);
    p2 = find(node2);
    if(p1 != p2)
    {
        parent[p2] = p1;
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
    {
        parent[i] = i;
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < M; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        //이동 가능한 관계들을 하나로 묶음
        uni(x, y);
    }
    for(int i = 1; i <= N; i++)
    {
        if(find(i) == find(arr[i]) || arr[i] == i)
        {
            result++;
        }
    }
    printf("%d", result);
}