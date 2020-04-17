#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
pair<int, int> arr[300005];
int N, K, bag[300005], Cur;
long long result;

/*
각 가방에는 보석 한 개만 들어갈 수 있고 해당 가방의 무게 이하인 보석을 넣으면서 
동시에 가격이 높은 보석을 넣어야 한다. i번째 가방에 들어갈 수 있는 보석 중에서 
가장 가격이 높은 보석을 찾는 방법은 전체 보석을 돌면서 최댓값을 찾을 수 있지만 이렇게 하면
시간이 오래 걸린다. i번째 가방에 넣을 수 있는 보석들의 리스트를 만들고 그중에서 가장 가격이 높은 보석을
선택하면 된다. 모든 가방에 대해서 리스트를 만들 순 없으니 리스트 하나를 만들고 보석을 계속 그 리스트에
추가하는 방식으로 해야 한다. 우선 가방과 보석을 무게의 오름차순으로 정렬한다. i번째 가방에 들어갈 수 있는
보석들을 모두 리스트에 넣고 그중에서 가장 가격이 높은 것을 선택한다. 그다음은 i + 1번째 가방에 들어갈 보석들을
모두 리스트에 넣고 가격이 높은 것을 선택한다. 리스트는 우선순위 큐를 이용해서 가격이 높은 것을 빠르게 찾으면 된다.
*/

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    for(int i = 0; i < K; i++)
    {
        scanf("%d", &bag[i]);
    }
    sort(arr, arr + N);
    sort(bag, bag + K);
    for(int i = 0; i < K; i++)
    {
        while(Cur < N && bag[i] >= arr[Cur].first)
        {
            pq.push(arr[Cur++].second);
        }
        if(pq.size() > 0)
        {
            result += pq.top();
            pq.pop();
        }
    }
    printf("%lld", result);
}