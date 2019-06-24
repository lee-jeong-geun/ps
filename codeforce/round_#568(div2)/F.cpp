#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec[1030];
int n, m, Count[1030], memo[1030], Max, result = 2100000000, A, B;

/*
가장 단순하게 하는 방법은 최대 10만 개의 피자에 대해서 2개의 쌍을 고르고 고른 피자의 재료를
선호하는 사람들이 얼마나 있는지 탐색하는 방법이다. 이렇게 하면 시간복잡도는 대략 O(N*M^2)정도가 나오게 되는데
N이 10만이고 M이 10만이라서 시간 안에 돌지 못한다. 잘 보면 재료는 1~9까지이다.
우선 저 재료를 비트로 생각했을 때 각 사람은 2부터 2^10 -1까지의 범위 안에 있는 수를 가지게 된다.
이렇게 한다면 각 사람에게서 선호하는 재료를 탐색할 때 최대 9번 봐야 될 것을 1번으로 줄일 수 있다.
여기서 더 줄일 수 있는 방법은 N 전체를 다 볼 필요 없이 2 ~ 2^10짜리 배열을 만들어서 이 배열에 개수를
저장하는 것이다. 그렇게 한다면 N을 대략 1000정도로 줄일 수 있다. 그리고 피자도 마찬가지로
2 ~ 2^10짜리 배열로 압축해서 개수만 저장한다. 이렇게 되면 O(1000^3)정도로 줄여진다.
잘 보면 피자 쌍을 구했을 때 사람들 배열을 매번 확인할 필요가 없다. 미리 선호 재료마다 몇명의 사람이 있는지
전처리를 해주면 O(1000^2) 정도로 줄게 된다. 따라서 피자 쌍을 구하고 그 재료에 몇명의 사람이 매칭 되는지 확인하면 된다.
*/

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        int f, num, hap = 0;
        scanf("%d", &f);
        for(int j = 0; j < f; j++)
        {
            scanf("%d", &num);
            hap |= (1 << num);
        }
        //해당 선호 재료 조합 카운트
        Count[hap]++;
    }
    //각 선호 재료 조합마다 매칭되는 사람들 수
    for(int i = 1; i < 1030; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if((i & j) == j)
                memo[i] += Count[j];
        }
    }
    for(int i = 0; i < m; i++)
    {
        int c, r, num, hap = 0;
        scanf("%d %d", &c, &r);
        for(int j = 0; j < r; j++)
        {
            scanf("%d", &num);
            hap |= (1 << num);
        }
        vec[hap].push_back({c, i + 1});
    }
    //정렬하는 이유는 피자 가격 최소화
    for(int i = 1; i < 1024; i++)
    {
        sort(vec[i].begin(), vec[i].end());
    }
    for(int i = 1; i < 1024; i++)
    {
        if(vec[i].size() == 0)
            continue;
        for(int j = 1; j < 1024; j++)
        {
            if(i == j || vec[j].size() == 0)
                continue;
            if(Max < memo[i | j])
            {
                Max = memo[i | j];
                result = vec[i][0].first + vec[j][0].first;
                A = vec[i][0].second;
                B = vec[j][0].second;
            }
            else if(Max == memo[i | j])
            {
                if(result > vec[i][0].first + vec[j][0].first)
                {
                    result = vec[i][0].first + vec[j][0].first;
                    A = vec[i][0].second;
                    B = vec[j][0].second;
                }
            }
        }
    }
    //한가지의 종류의 피자만 고른 경우
    for(int i = 1; i < 1024; i++)
    {
        if(vec[i].size() > 1)
        {
            if(Max < memo[i])
            {
                Max = memo[i];
                result = vec[i][0].first + vec[i][1].first;
                A = vec[i][0].second;
                B = vec[i][1].second;
            }
            if(Max == memo[i] && result > vec[i][0].first + vec[i][1].first)
            {
                result = vec[i][0].first + vec[i][1].first;
                A = vec[i][0].second;
                B = vec[i][1].second;
            }
        }
    }
    printf("%d %d", A, B);
}