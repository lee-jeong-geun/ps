#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec[1005];
int N, Left[1005], Right[1005], memo[1005][1005];

/*
왼쪽의 i번째 소와 오른쪽의 j번째 소를 매칭 시킨것으로 메모이제이션 하면 된다.
dp[i][j] = 왼쪽의 i번째 소와 오른쪽 j번째 소를 매칭 시켰을때 횡단 보도 최대 개수이다.
단순하게 완전탐색과 메모이제이션을 하면 시간이 오래걸린다.
잘보면 절대값이 4이하인 경우만 매칭시키도록 되어있다.
따라서 왼쪽 소와 차이가 4이하인 오른쪽 소들을 벡터에 넣고 탐색을 할 때 벡터 안에 있는 값들만 해주면
훨씬 빨라진다.
*/

int abs(int num)
{
    return num > 0 ? num : num * - 1;
}

int func(int left, int right)
{
    if(left == N - 1 || right == N - 1)
    {
        return 0;
    }
    int &ret = memo[left + 1][right + 1];
    if(ret != -1)
    {
        return ret;
    }
    //오른쪽 소들을 매칭 안시킨 경우
    ret = func(left + 1, right);
    //왼쪽소와 차이가 4이하인 오른쪽 소들의 모음
    for(int i = 0; i < vec[left + 1].size(); i++)
    {
        //횡단 보도가 겹치면 안되므로 right보다 뒤 인덱스들을 선택
        if(right < vec[left + 1][i])
        {
            ret = max(ret, func(left + 1, vec[left + 1][i]) + 1);
        }
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Left[i]);
    }
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Right[i]);
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            //차이가 4이하인 소들을 고름
            if(abs(Left[i] - Right[j]) <= 4)
            {
                vec[i].push_back(j);
            }
        }
    }
    memset(memo, -1, sizeof memo);
    printf("%d", func(-1, -1));
}