#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<int> vec[3005], result;
int N, route[3005], memo[3005], Count[3001][3001];

/*
각각의 구간들을 나누고 그 구간의 분할 점수를 메모이제이션 하면 된다.
그리고 각 구간들의 연결 개수를 누적합을 이용하여 빠르게 구하면 된다.
모둠을 나누는 방법은 해당 구간이 최소값을 가질때 그 구간의 시작점에 구간의 끝점을 저장 하면 된다.
이렇게 하면 1로 시작하는 구간의 끝점으로 이동하고 또 그 끝점에서 또 끝점으로 이동 ....
가장 마지막 구간의 끝점으로 이동 가능 하다.
*/

int func(int idx)
{
    if(idx == N + 1)
        return 0;
    int &ret = memo[idx];
    if(ret != -1)
        return ret;
    ret = 987654321;
    int rightSum = 0, sum = 0;
    for(int i = idx; i <= N; i++)
    {
        //구간의 끝점과 연결된 정점의 개수
        rightSum += (int)vec[i].size();
        //내부 구간의 비 연결 정점 개수 + 구간의 끝점 연결 정점 개수
        sum = rightSum + (i - idx) * (i - idx + 1) / 2 - Count[idx][i] * 2;
        //최소값이라면 구간의 끝점 저장
        if(ret > func(i + 1) + sum)
            route[idx] = i + 1;
        ret = min(ret, func(i + 1) + sum);
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        int num;
        while(1)
        {
            scanf("%d", &num);
            if(num == 0)
                break;
            if(num > i)
            {
                vec[i].push_back(num);
                Count[i][num]++;
            }
        }
    }
    //1 ~ N, 2 ~ N, 3 ~ N ... 구간을 키웠을 때 연결된 정점의 개수 누적합
    for(int i = 1; i <= N; i++)
    {
        for(int j = i; j <= N; j++)
        {
            Count[i][j] += Count[i][j - 1];
        }
    }
    //N ~ N은 N - 1 ~ N 구간에 포함
    //N - 1 ~ N은 N - 2 ~ N 구간에 포함
    //이러한 구간들의 누적합 계산
    for(int i = N; i > 1; i--)
    {
        for(int j = i; j <= N; j++)
        {
            Count[i - 1][j] += Count[i][j];
        }
    }
    memset(memo, -1, sizeof memo);
    printf("%d\n", func(1));
    //분할된 구간들 추적
    int temp = 1;
    while(temp != N + 1)
    {
        result.push_back(route[temp] - temp);
        temp = route[temp];
    }
    printf("%d ", result.size());
    for(int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
}