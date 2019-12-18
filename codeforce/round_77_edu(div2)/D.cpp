#include <bits/stdc++.h>
using namespace std;
pair<pair<int, int>, int> trap[200005];
int m, n, k, t, result;
int arr[200005];

/*
m명의 병사들을 t초안에 최대한 이동시키기 위해서는 트랩들을 효율적으로 종료시켜야 하는데
트랩은 최대 200000개가 나오게 되므로 어떤 트랩을 꺼야하는지 확인하기 어렵고 병사 또한
200000명이나 되므로 완전탐색으로는 시간안에 해결할 수 없다.
잘보면 병사들의 전투력을 오름차순으로 정렬하고 i번째 병사 전투력을 기준으로 트랩을 꺼서
t초안에 병사들을 전부 이동시켰다면 i + 1부터 m번째까지의 병사 전투력을 기준으로 잡았을 경우
무조건 t초안에 병사들을 이동 시킬 수 있다. 우리는 최대한 많은 병사들을 이동 시키는게 목적
이므로 i부터 m번째까지 병사들을 이동 시켰다면 0 ~ i - 1까지의 병사들을 이동시킬 수 있는지
이분탐색으로 찾을수 있다.
이제 이동 가능한지 파악하는 방법은 i번째 병사의 전투력보다 큰 트랩들만 모아두고
트랩을 끄고 돌아왔을때의 시간 + 병사들을 이동 시키는 시간들을 전부 구한 후 t초안에 들어오는지
확인하면 된다.
*/

int func(int idx)
{
    vector<pair<int, int>> vec, vec2;
    for(int i = 0; i < k; i++)
    {
        //idx 병사보다 높은 트랩들만 모음
        if(arr[idx] < trap[i].second)
            vec.push_back({trap[i].first.first, trap[i].first.second});
    }
    //트랩들의 l, r순으로 정렬
    sort(vec.begin(), vec.end());
    vec.push_back({987654321, 987654321});
    int l = 0, r = 0;
    //연속된 트랩들을 하나로 합침
    for(int i = 0; i < vec.size(); i++)
    {
        if(r < vec[i].first)
        {
            vec2.push_back({l, r});
            l = vec[i].first;
        }
        r = max(r, vec[i].second);
    }
    int Cur = 0, count = 0;
    for(int i = 1; i < vec2.size(); i++)
    {
        //병사들의 현재 위치에서 트랩의 l - 1까지 이동하는데 걸리는 시간
        count += vec2[i].first - Cur - 1;
        //병사들의 현재 위치 갱신
        Cur = vec2[i].first - 1;
        //트랩을 끄고 돌아오는데 시간
        count += (vec2[i].second - Cur) * 2;
    }
    //마지막 위치에서 n + 1까지 이동하는 시간
    count += n + 1 - Cur;
    if(count <= t)
        return 1;
    return 0;
}

int main()
{
    scanf("%d %d %d %d", &m, &n, &k, &t);
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < k; i++)
    {
        scanf("%d %d %d", &trap[i].first.first, &trap[i].first.second, &trap[i].second);
    }
    //전투력 정렬
    sort(arr, arr + m);
    int l, r;
    l = 0;
    r = m - 1;
    result = m;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        //mid ~ m까지의 병사들을 이동 시킬수 있는 경우
        if(func(mid))
        {
            r = mid -1;
            result = mid;
        }
        else
            l = mid + 1;
    }
    printf("%d", m - result);
}