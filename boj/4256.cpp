#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef struct _data
{
    int left, right;
}Data;
Data node[1005];
int n, preorder[1005], inorder[1005], chk[1005];

/*
글로 적기 힘들어서 풀이과정을 예제로 나타냄
전위 순회 결과 : 3 6 5 4 8 7 1 2
중위 순회 결과 : 5 6 8 4 3 1 2 7
전위 순회 첫번째 노드인 3의 중위 순회 결과 양 옆 노드 4 1은 아직 탐색을 안했기 때문에
재귀를 탄다.
그다음 노드인 6을 보면 6의 중위 순회 결과 양 옆 노드 5 8은 아직 탐색을 안했기 때문에
재귀를 탄다.
그 다음 노드인 5를 보면 5의 중위 순회 결과 양 옆 노드 공백 6은 탐색을 했기 때문에
5를 출력후 리턴한다.
리턴 했기 때문에 다시 6으로 가서 5 다음 노드인 4의 중위 순회 결과 양 옆 노드 중 8은 탐색을 안했고
3은 했기 때문에 재귀를 탄다.
그다음 노드인 8을 보면 중위 순회 결과 양 옆 노드 6 4는 이미 탐색을 했기 때문에
8을 출력후 리턴한다.
리턴 했기 때문에 다시 4로 가면 4의 중위 순회 결과 양 옆 노드 8 3은 탐색을 했기 때문에
4를 출력후 리턴한다.
이런 방식으로 하면 후위 순회 결과를 얻을수 있다.
*/

void func(int num)
{
    //탐색 했다는 표시를 해줌
    chk[preorder[num]] = 1;
    for(int i = num + 1; i <= n; i++)
    { 
        //중위 순회 결과 양 옆노드들이 탐색 완료라면 반복문 빠져나감
        if(chk[node[preorder[num]].left] == 1 && chk[node[preorder[num]].right] == 1)
        {
            break;
        }
        //이미 탐색한 노드는 다시 탐색할 필요 없음
        if(chk[preorder[i]] == 1)
        {
            continue;
        }
        func(i);
    }
    printf("%d ", preorder[num]);
    return;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        memset(chk, 0, sizeof chk);
        scanf("%d", &n);
        chk[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &preorder[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &inorder[i]);
        }
        //중위 순회 결과의 양 옆을 배열에 저장해줌 
        //저장을 안해준다면 중위 순회 결과 배열을 처음부터 끝까지 탐색해야하는 비효율 발생
        for(int i = 1; i <= n; i++)
        {
            node[inorder[i]].left = inorder[i - 1];
            node[inorder[i]].right = inorder[i + 1];
        }
        func(1);
        printf("\n");
    }
}