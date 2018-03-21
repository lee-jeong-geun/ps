#include <cstdio>
#include <iostream>
using namespace std;
long long N;
int K, Q;

/*
LCA개념으로 접근하면된다.
K진 트리는 자식의 개수가 K개라는 뜻이므로 어떤 노드에서 자식으로 간다는 것은 
노드의 번호 * K를 하면 된다. 그리고 어떤 노드에서 부모 노드로 간다는 것은 노드의 번호 / K를 하면된다.
노드 x와 y의 거리는 x와 y의 부모노드가 같을때까지 부모 노드로 이동하면된다.
부모노드로 이동할때는 현재 노드를 K로 나누면 된다.
K가 1인 트리는 자식이 하나밖에 없는 선형 구조로 되어 있으므로 두 노드 사이의 거리를 구하는 것은
시간복잡도가 O(N)이 되고 N은 10의 ^ 15이므로 시간 초과가 나게 된다.
하지만 선형 구조로 되어 있을때는 두 노드 사이의 거리는 곧 두 노드의 차를 의미하므로
깊이를 맞추지말고 바로 차를 구하면 된다.
*/

int main()
{
    scanf("%d %d %d", &N, &K, &Q);
    for(int i = 0; i < Q; i++)
    {
        int result = 0;
        long long x, y;
        scanf("%lld %lld", &x, &y);
        //노드 / K가 항상 부모노드가 되게 하도록 -1을 함
        x--;
        y--;
        if(K == 1)
        {
            //두 노드의 차가 곧 거리
            printf("%lld\n", x > y ? x - y : y - x);
            continue;
        }
        //x랑 y가 같은 노드일때까지 깊이를 맞춤
        while(x != y)
        {
            //x가 y보다 더 깊은 노드일 경우
            while(x > y)
            {
                x--;
                //부모 노드로 이동
                x /= K;
                result++;
            }
            while(y > x)
            {
                y--;
                y /= K;
                result++;
            }
        }
        printf("%d\n", result);
    }
}