#include <bits/stdc++.h>
using namespace std;
deque<int> dq;
int N, K, arr[1000005], result = 987654321;

/*
주어진 수열을 정렬했을 때 M은 마지막 원소 - 첫 번째 원소이다. m은 인접한 원소들의 차이 중 최소이다.
앞, 뒤 상관없이 K개를 항상 제거해야 하므로 N-K-1의 크기를 항상 유지하면서 0부터 N까지 슬라이딩 윈도우 방식으로
최소 M+m을 찾으면 된다. 이때 M은 바로 구할 수 있지만, m은 윈도우 사이를 돌면서 구해야 한다.
이때 m을 찾는 시간복잡도는 O(N)가 나오게 되는데 N이 10^6이므로 시간이 오래 걸린다.
따라서 덱을 이용하여 m의 후보들을 저장한다. m의 후보란 윈도우 안에서 인접한 원소들의 차이이고
안 봐도 될 값들을 제거한 값이다. 예를 들어 원소들의 차이가 4, 5, 10, 8, 6이라면
10, 8은 뒤의 6 때문에 m이 절대 될 수 없다. m의 후보는 4, 5, 6이 되게 된다.
이렇게 하면 m 값도 O(1)로 구할 수 있게 되는데 덱의 맨 앞 값이 그 윈도우에서 m이 되게 된다.
*/

int main()
{
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    for(int i = 0; i < N - K - 1; i++)
    {
        int temp = arr[i + 1] - arr[i];
        while(dq.size() > 0 && dq.back() > temp)
        {
            dq.pop_back();
        }
        dq.push_back(temp);
    }
    int l, r;
    l = 0;
    r = N - K - 1;
    while(r < N)
    {
        result = min(result, arr[r] - arr[l] + dq.front());
        if(arr[l + 1] - arr[l] == dq.front())
            dq.pop_front();
        int temp = arr[r + 1] - arr[r];
        while(dq.size() > 0 && dq.back() > temp)
        {
            dq.pop_back();
        }
        dq.push_back(temp);
        l++;
        r++;
    }   
    printf("%d", result);
}