#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int N;
double P[20][20], memo[17][66005];

/*
모두 중복없이 하나씩 골라야 되므로 총 가짓수는 16!이다.
16!을 완전탐색으로 풀면 무조건 시간초과가 나므로 dp를 이용해야 한다.
4567123
4657123
4765123
과 같이 뒤에 123을 더이상 탐색하지 않고 메모이제이션을 해서 리턴값만 받아오면 된다.
4567, 4657, 4765 모두 4와 5와 6과 7을 골랐으므로 메모이제이션을 할때 저 수들을 따로따로 저장을 하는게 아니라
비트연산을 통해서 (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7)의 값에 해당하는 배열 idx에 값을 저장하면 된다.
*/

double max(double a, double b)
{
    return a > b ? a : b;
}

double func(int depth, int visit)
{
    //기저 사례
    if(visit == (1 << N) - 1)
    {
        return 1;
    }
    double &ret = memo[depth][visit];
    if(ret != 0)
    {
        return ret;
    }
    ret = -1;
    for(int i = 0; i < N; i++)
    {
        //이미 방문 한 위치일 경우
        if((visit & (1 << i)) != 0)
        {
            continue;
        }
        ret = max(ret, func(depth + 1, visit | (1 << i)) * P[depth][i]);
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        memset(memo, 0, sizeof memo);
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                scanf("%lf", &P[i][j]);
                P[i][j] /= 100;
            }
        }
        printf("#%d %.6lf\n", testcase, func(0, 0) * 100);
    }
}