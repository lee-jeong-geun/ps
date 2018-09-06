#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int N, score[105], chk[10005], result, stack[10005], idx;

/*
전체를 완전탐색하면 O(2^N)의 시간복잡도가 나오게 된다. N은 최대 100이므로
최대로 나올수 있는 수의 개수는 10000개정도이다. 10000은 2^100에 비해 매우 작기 때문에
10000개의 수를 찾기위해 2^100을 탐색하는건 매우 비효율적이다.
따라서 완전탐색을 하지 않고 배열을 이용해서 순차적으로 탐색하면 된다.
배열에는 지금까지 탐색했던 수들을 중복 제거 하고 넣어준다. 배열에 0을 넣어주면 숫자 하나만 고르는것을 간단하게
해결 할 수 있다. 예제 2, 3, 5를 보면 처음에 배열에 0이 있으니까 0 + 2를 배열에 넣어주면 배열에는 0, 2가있다.
그다음 3을 0 + 3, 2 + 3하고 배열에 넣으주면 0, 2, 3, 5가 들어가게 된다. 그다음 5를 0 + 5, 2 + 5, 3 + 5, 5 + 5를 하고
중복을 제거해주면 배열에는 0, 2, 3, 5, 7, 8, 10이 들어가게 된다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        idx = 1;
        result = 1;
        memset(chk, 0, sizeof chk);
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &score[i]);
        }
        for(int i = 0; i < N; i++)
        {
            int temp;
            temp = idx;
            for(int j = 0; j < temp; j++)
            {
                //없으면 배열에 넣어줌
                if(chk[stack[j] + score[i]] == 0)
                {
                    chk[stack[j] + score[i]] = 1;
                    stack[idx++] = stack[j] + score[i];
                    result++;
                }
            }
        }
        printf("#%d %d\n", testcase, result);
    }
}