#include <cstdio>
#include <iostream>
using namespace std;
int N, preorder[105], inorder[105];

void func(int start, int end, int root)
{
    int node;
    if(start > end)
    {
        return;
    }
    for(int i = start; i <= end; i++)
    {
        if(inorder[i] == preorder[root])
        {
            node = i;
            break;
        }
    }
    func(start, node - 1, root + 1);
    func(node + 1, end, root + 1 + node - start);
    printf("%d ", inorder[node]);
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &preorder[i]);
        }
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &inorder[i]);
        }
        func(0, N - 1, 0);
        printf("\n");
    }
}