#include <cstdio>
#include <iostream>
using namespace std;
int n, inorder[100005], postorder[100005];

/*
postorder의 맨끝이 루트 노드라는것을 이용해서
inorder에서 루트 노드를 찾고 그 인덱스를 기준으로 양쪽 서브트리로 쪼개면서 탐색하면 된다.
inorder에서 루트 노드를 찾을때 반복문을 돌리면 시간이 오래 걸리므로 중복이 없는것을 이용해서
inorder배열에 인덱스를 저장하면 된다.
*/

void func(int start, int end, int node)
{
    if(start > end)
    {
        return;
    }
    printf("%d ", postorder[node]);
    //왼쪽 서브트리
    func(start, inorder[postorder[node]] - 1, node - (end - inorder[postorder[node]]) - 1);
    //오른쪽 서브트리
    func(inorder[postorder[node]] + 1, end, node - 1);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int node;
        scanf("%d", &node);
        inorder[node] = i;
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &postorder[i]);
    }
    func(0, n - 1, n - 1);
}