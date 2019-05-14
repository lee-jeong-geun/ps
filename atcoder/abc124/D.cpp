#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> vec;
int N, K, result;
char S[100005];

/*
1이 연속인 부분들과 0이 연속인 부분들을 하나로 뭉친다.
최대 K번의 연산을 통해 0을 1로 바꿔야 한다.
K번이 될때까지 1, 0이 연속인 부분들의 합을 구하고 K번이 넘어가면 맨 앞에 있는 0이 연속인
부분이 나올때까지 빼준다. 이렇게 슬라이딩 하듯이 구하면 된다.
*/

int main()
{
    scanf("%d %d %s", &N, &K, S);
    int count = 1;
    //연속인 구간을 하나로 합침
    for(int i = 0; i < N; i++)
    {
        if(S[i] != S[i + 1])
        {
            vec.push_back({count, S[i] - '0'});
            count = 0;
        }
        count++;
    }
    //0이 마지막으로 끝나는 경우를 위해 예외 처리
    vec.push_back({0, -1});
    //feedCount는 0의 구간 카운트
    int hap = 0, feedCount = 0, left = 0, right = 0;
    while(right < vec.size())
    {
        hap += vec[right++].first;
        result = max(result, hap);
        //현재까지 더한것들중 마지막이 0으로 끝나는 경우
        if(vec[right - 1].second == 0)
        {
            feedCount++;
            //0구간이 K개가 된 경우
            if(feedCount == K)
            {
                //0구간 다음에 1구간이 오므로 더해줌
                hap += vec[right++].first;
                result = max(result, hap);
                //맨앞이 1구간인 경우
                if(vec[left].second != 0)
                {
                    hap -= vec[left++].first;
                }
                //0구간을 빼줌
                hap -= vec[left++].first;
                feedCount--;
            }
        }
    }
    printf("%d", result);
}