#include <bits/stdc++.h>
using namespace std;
map<long long, int> m;
pair<int, int> arr[200005];
int n;

/*
등차수열이 되기 위한 조건은 주어진 배열의 인접한 값들의 차가 전부 같아야 한다.
그러기 위해 배열을 정렬 후 arr[2 ~ n]까지의 수들에 대해 자기 바로 앞의 수의 차를 맵에 저장한다.
그러면 맵에는 인접한 값들의 차들이 저장 되어있는데 이때 맵에 키가 한개라면 주어진 배열 자체가
등차수열이므로 맨 앞의 인덱스를 출력 하면 된다. 그게 아니라면 인덱스를 하나씩 제거 해야 하는데
맨 앞과 맨 뒤는 따로 예외 처리를 해주는게 편하다. 그 이유는 맨 앞과 맨 뒤는 인접한 값이 한개 밖에
안되지만 나머지 값들은 인접한 값이 2개나 되므로 편하게 코드를 짜기 위해 예외 처리를 해주었다.
하나씩 제거 하면서 제거한 인덱스 양 옆의 값들의 차가 맵에 n - 2개가 있으면 등차수열이라는 뜻이다.
전부 탐색 했는데 없으면 -1을 출력하면 된다.

*/

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i].first);
        //정렬 후 정렬 하기 전의 인덱스를 출력하기 위해 저장
        arr[i].second = i;
    }
    sort(arr + 1, arr + n + 1);
    for(int i = 2; i <= n; i++)
    {
        //인접한 값의 차를 맵에 저장
        m[arr[i].first - arr[i - 1].first]++;
    }
    //맵에 키가 한개거나 수의 개수가 3이하라면 무조건 등차수열임
    if(m.size() == 1 || n <= 3)
    {
        printf("%d", arr[1].second);
        return 0;
    }
    //1번 인덱스 지우는 경우
    m[arr[2].first - arr[1].first]--;
    if(m[arr[3].first - arr[2].first] == n - 2)
    {
        printf("%d", arr[1].second);
        return 0;
    }
    m[arr[2].first - arr[1].first]++;
    //n번 인덱스 지우는 경우
    m[arr[n].first - arr[n - 1].first]--;
    if(m[arr[n - 1].first - arr[n - 2].first] == n - 2)
    {
        printf("%d", arr[n].second);
        return 0;
    }
    m[arr[n].first - arr[n - 1].first]++;
    //2 ~ n - 1을 지우는 경우
    for(int i = 2; i < n; i++)
    {
        m[arr[i].first - arr[i - 1].first]--;
        m[arr[i + 1].first - arr[i].first]--;
        m[arr[i + 1].first - arr[i - 1].first]++;
        if(m[arr[i + 1].first - arr[i - 1].first] == n - 2)
        {
            printf("%d", arr[i].second);
            return 0;
        }
        m[arr[i].first - arr[i - 1].first]++;
        m[arr[i + 1].first - arr[i].first]++;
        m[arr[i + 1].first - arr[i - 1].first]--;
    }
    printf("-1");
}