#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec;
int n, M, T[200005], sortIdx[200005];
int sumFen[200005], countFen[200005];

/*
이문제는 T가 최대 100까지만 나오므로 카운트 소트 방식을 이용하여 인덱스마다 1부터 100까지만 확인하는
방법이 있다. 이 방식은 너무 쉬운 방법이라 패스하고 T를 10^5까지 나오는 문제로 변형 해서 생각해보면 좋은
문제가 된다. 이렇게 바꾼다면 매번 10만번씩 확인하게 되므로 다른 방법을 생각해야 한다.
1부터 10만 까지를 빈도수로 관리한다면 1, 3, 3, 4, 2, 7이 나올때
1, 1, 2, 3, 0, 0, 1 이라는 배열을 이용하여 관리 할 수 있다. 매 인덱스 마다 자기 앞에 어떤 수들이
존재 하는지 파악 할 수 있지만 10만이라는 크기가 한번에 탐색할 때 다 탐색 하기에는 너무 크다.
따라서 구간 트리를 이용하여 빠르게 탐색을 하면 된다. 0 ~ i - 1까지 합들과 T[i]의 합이 M 이하여야 하므로
저걸 만족하는 최대 구간을 탐색하는데 일일이 탐색하면 시간이 오래 걸리므로 이분탐색을 이용하여 빠르게
조건을 만족하는 인덱스를 찾은 후 해당 출력 해주면 된다. 하지만 이렇게 한다면 중복된 값들을 처리하기 껄끄러워 진다.
0 ~ i - 1까지의 합과 T[i]의 합이 M을 초과해도 0 ~ i - 1에서 어떤 중복된 값을 전부 선택이 아닌 일부 선택을 하면
조건이 만족 될 경우가 있을 것이다. 이러한 경우들을 쉽게 처리 하기 위해 T값들을 정렬 후 인덱싱을 해준 후
구간 트리의 각각의 인덱스에 저장을 한다면 저런 중복된 경우들을 쉽게 처리 할 수 있다.
*/

int query(int *arr, int num)
{
    int Sum = 0;
    while(num > 0)
    {
        Sum += arr[num];
        num -= (num & -num);
    }
    return Sum;
}

void update(int *arr, int num, int count)
{
    while(num <= n)
    {
        arr[num] += count;
        num += (num & -num);
    }
}

int main()
{
    scanf("%d %d", &n, &M);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &T[i]);
        vec.push_back({T[i], i});
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; i++)
    {
        //정렬 후 구간트리의 인덱스에 값을 하나만 저장 하기 위한 인덱싱
        sortIdx[vec[i].second] = i + 1;
    }
    for(int i = 0; i < n; i++)
    {
        int l = 1, r = n, idx = 0;
        while(l <= r)
        {
            int mid;
            mid = (l + r) / 2;
            if(query(sumFen, mid) + T[i] <= M)
            {
                idx = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        //저 조건을 만족하는 학생의 수를 i에서 뺌
        printf("%d ", i - query(countFen, idx));
        update(sumFen, sortIdx[i], T[i]);
        update(countFen, sortIdx[i], 1);
    }
}