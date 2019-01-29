#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, k, memo[2005][2][2005], Mod = 998244353;

/*
일반적으로 생각하면 [i번째 벽돌][색깔][다른 벽돌 개수]로 메모이제이션 할 수 있다.
하지만 이렇게 하면 [2000][2000][2000]이므로 메모리가 부족해진다.
잘 생각 해보면 현재 상황에서 다음 상황으로 갈 때 필요한 것은 현재 벽돌과 다음 벽돌의 일치 여부이다.
무슨뜻이냐면 현재 벽돌의 색깔이 빨강색이고 다음 벽돌로 올 수 있는 색깔이 빨강색 파랑색 초록색이라면
빨강 - 파랑, 빨강 - 초록은 색깔이 다르므로 다른 벽돌 개수가 1증가하지만 빨강 - 빨강은 색깔이 같아서
증가하지 않는다. 이 다음 상황들도 똑같이 적용 된다. 즉 빨강 - 파랑, 빨강 - 초록을 합칠 수 있다.
합치고 개수는 다른 색깔이 n - 1개 이므로 개수는 n - 1개로 한번에 처리하면 된다.
따라서 테이블을 [2000][2][2000]으로 줄일 수 있다.
*/

int func(int depth, int color, int count)
{
    if(depth == n - 1)
    {
        if(count == k)
        {
            return 1;
        }
        return 0;
    }
    int &ret = memo[depth][color][count];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    //다른 벽돌인 경우
    ret = (ret + (long long)func(depth + 1, !color, count + 1) * (m - 1)) % Mod;
    //같은 벽돌인 경우
    ret = (ret + (long long)func(depth + 1, color, count)) % Mod;
    return ret;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    memset(memo, -1, sizeof memo);
    //처음에 시작 할 때 총 m개의 색깔로 시작
    printf("%d", (long long)func(0, 0, 0) * m % Mod);
}