#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int n, k[5], chk[200005], memo[200005][5], result = 987654321;

/*
접두사와 접미사의 관계를 이용해서 접근 해야 한다.
예를 들어 1, 2, 3, 4, 5가 있을때 1을 접미사에 둔다면
2는 반드시 접미사에 두어야 한다. 3 또한 접미사에 둔다면 4는 반드시 접미사에 두어야 한다.
2를 중간단계에 둔다면 3은 접두사에 둘 수없다. 이러한 관계를 이용하여
접두사에 쭉 두다가 중간단계로 둔다면 그 이후는 접두사가 아닌 중간 or 접미사에 두도록 한다.
나올수 있는 상태는 현재 수를 기준으로 3가지 접두, 중간, 접미 이러한 상태가 나오게 된다.
따라서 dp[200000][3]의 테이블로 메모이제이션 하면 된다.
*/

int func(int depth, int idx)
{
    if(depth == n)
        return 0;
    int &ret = memo[depth][idx];
    if(ret != -1)
        return ret;
    ret = 987654321;
    for(int i = 0; i < 3; i++)
    {
        //앞에서 접미를 뒀으면 접두, 중간에 못둠
        if(idx > i)
            continue;
        int temp = 0;
        //이동 하는 경우 1증가
        if(chk[depth + 1] != i)
            temp = 1;
        ret = min(ret, func(depth + 1, i) + temp);
    }
    return ret;
}

int main()
{
    scanf("%d %d %d", &k[0], &k[1], &k[2]);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < k[i]; j++)
        {
            int num;
            scanf("%d", &num);
            chk[num] = i;
        }
    }
    memset(memo, -1, sizeof memo);
    n = k[0] + k[1] + k[2];
    for(int i = 0; i < 3; i++)
    {
        result = min(result, func(0, i));
    }
    printf("%d", result);
}