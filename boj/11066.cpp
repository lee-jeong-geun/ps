//top-down

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int K, Number[505], memo[505][505], Sum[505];

/*
구간을 두군데로 나누어서 해결하면 된다.
나뉜 구간은 재귀를 타면서 또 나뉜다.
이렇게 나뉘어 가다가 구간의 요소가 1개 또는 2개일때 리턴해주면 되는데
1개를 합칠때 비용은 0이고 2개를 합칠때 비용은 2개의 합이다.
따라서 각각의 비용을 리턴해주면 된다.
그리고 나뉜 구간의 전체 비용을 계산해야 하는데 구간 left부터 right까지의 합은
배열 left 인덱스부터 right인덱스 까지의 합이다.
누적합을 이용하여 O(1)만에 구해주면 된다.
*/

int func(int left, int right)
{
    if(left == right)
    {
        return 0;
    }
    if(left == right - 1)
    {
        return Number[left] + Number[right];
    }
    int &ret = memo[left][right];
    if(ret != -1)
    {
        return ret;
    }
    ret = 987654321;
    for(int i = left; i < right; i++)
    {
        int temp1, temp2;
        temp1 = func(left, i);
        temp2 = func(i + 1, right);
        //점화식
        ret = min(ret, temp1 + temp2 + Sum[right] - Sum[left - 1]);
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        memset(memo, -1, sizeof memo);
        memset(Sum, 0, sizeof Sum);
        scanf("%d", &K);
        for(int i = 1; i <= K; i++)
        {
            scanf("%d", &Number[i]);
            Sum[i] = Sum[i - 1] + Number[i];
        }
        printf("%d\n", func(1, K));
    }
}

//bottom-up

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int K, Number[505], memo[505][505], Sum[505];

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        memset(memo, 0x3f, sizeof memo);
        memset(Sum, 0, sizeof Sum);
        scanf("%d", &K);
        for(int i = 1; i <= K; i++)
        {
            scanf("%d", &Number[i]);
            Sum[i] = Sum[i - 1] + Number[i];
            memo[i][i] = 0;
        }
        for(int i = 1; i < K; i++)
        {
            for(int j = 1; j + i <= K; j++)
            {
                int next;
                next = j + i;
                for(int k = j; k < next; k++)
                {
                    memo[j][next] = min(memo[j][next], memo[j][k] + memo[k + 1][next] + Sum[next] - Sum[j - 1]);
                }
            }
        }
        printf("%d\n", memo[1][K]);
    }
}