#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec;
pair<int, int> arr[200005];
int n, resultA, resultB;

/*
각각의 사탕을 {개수, 1의 개수}로 나타내고 정렬을 한다.
그리고 제일 개수가 많은것부터 우선순위큐에 넣는데 이때 비교 조건은
1의개수가 많은것들이 위쪽으로 가게 한다. 그 이유는 어차피 x개를 고를 때 
x보다 개수가 많은 것들이 큐 안에 있는데 당연히 x를 만족하는 수들 중에서 골라야할 수는
1의개수가 많은 수이기 때문이다.
*/

//우선순위 큐 연산자 오버로딩
class comp
{
public:
    bool operator() (const pair<int, int>& l, const pair<int, int>& r) const
    {
        if(l.second == r.second)
            return l.first < r.first;
        return l.second < r.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

int main()
{
    int q;
    scanf("%d", &q);
    for(int tc = 0; tc < q; tc++)
    {
        vec.clear();
        resultA = 0;
        resultB = 0;
        for(int i = 1; i <= n; i++)
        {
            arr[i].first = 0;
            arr[i].second = 0;
        }
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            int a, f;
            scanf("%d %d", &a, &f);
            //사탕의 개수
            arr[a].first++;
            //1의 개수
            arr[a].second += f;
        }
        for(int i = 1; i <= n; i++)
        {
            //사탕이 하나라도 존재할 경우
            if(arr[i].first > 0)
                vec.push_back({arr[i].first, arr[i].second});
        }
        sort(vec.begin(), vec.end(), greater<pair<int, int>>());
        int before = vec[0].first, idx = 0;
        while(idx != vec.size())
        {
            //이전 수 이상이라면 큐에 삽입
            if(before <= vec[idx].first)
            {
                pq.push({vec[idx].first, vec[idx].second});
                idx++;
            }
            else
            {
                //큐에 값이 존재할 경우에만 삭제
                if(pq.size() > 0)
                {
                    resultA += before;
                    resultB += min(before, pq.top().second);
                    pq.pop();
                }
                before--;
            }
        }
        while(!pq.empty())
        {
            if(before > 0)
            {
                resultA += before;
                resultB += min(before, pq.top().second);
            }
            pq.pop();
            before--;
        }
        printf("%d %d\n", resultA, resultB);
    }
}