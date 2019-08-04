#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec;
int n, prime[2005];

/*
우선 주어진 노드들을 둥글게 연결 시킨다. (1, n), (1, 2), (2, 3), .... (n-1, n)이랑 연결을 한다.
연결한 간선이 소수가 아니라면 (1, n-1), (2, n-2), ... 이러한 연산을 소수가 될 때까지 계속 하면 된다.
*/

int main()
{
    //에라토스 테네스 체
    for(int i = 2; i < 2005; i++)
    {
        if(prime[i] == 1)
            continue;
        for(int j = i + i; j < 2005; j += i)
        {
            prime[j] = 1;
        }
    }
    scanf("%d", &n);
    //1과n을 연결
    vec.push_back({1, n});
    for(int i = 2; i <= n; i++)
    {
        //자신보다 작은 노드와 연결
        vec.push_back({i - 1, i});
    }
    int start, end;
    start = 1;
    end = n - 1;
    //소수가 아니라면 계속 연결
    while(prime[n] == 1)
    {
        n++;
        vec.push_back({start, end});
        start++;
        end--;
    }
    printf("%d\n", vec.size());
    for(int i = 0; i < vec.size(); i++)
    {
        printf("%d %d\n", vec[i].first, vec[i].second);
    }
}