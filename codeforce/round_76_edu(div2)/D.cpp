#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
pii piiArr[200005];
int n, arr[200005], m, result, maxArr[200005], maxMonster;

/*
주어진 몬스터들을 다 잡는데 있어서 필요한 날을 최소화 시켜야 한다.
우선 i번째 몬스터를 잡기 위해서는 해당 몬스터의 파워 이상인 영웅을 투입 시켜야 한다.
이러한 영웅을 찾는데 O(N)의 시간 복잡도가 필요하지만 주어진 영웅을 파워 순으로 정렬 시킨다면
이분탐색을 이용하여 O(log N)만에 쉽게 찾을 수 있다. 하지만 주어진 영웅의 체력도 고려 해야한다.
해당 몬스터 파워 이상인 영웅들 중에서 체력이 가장 높은 영웅을 선택해야 일 수를 최소화 시킬 수 있다.
체력까지 고려 했을 경우 O(N)의 시간 복잡도가 필요 하지만 미리 최대 체력을 저장 해놓으면 O(1)만에
찾을 수 있다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        maxMonster = 0;
        result = 1;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            //가장 파워가 높은 몬스터 찾기
            maxMonster = max(maxMonster, arr[i]);
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &piiArr[i].first, &piiArr[i].second);
        }
        sort(piiArr, piiArr + m);
        maxArr[m] = 0;
        for(int i = m - 1; i >= 0; i--)
        {
            //영웅들 최대 체력 저장
            maxArr[i] = max(maxArr[i + 1], piiArr[i].second);
        }
        //영웅 최대 파워보다 높은 몬스터가 있는 경우
        if(maxMonster > piiArr[m - 1].first)
            result = -987654321;
        int count = 1, maxPower = 0;
        for(int i = 0; i < n; i++)
        {
            pii temp;
            //연속으로 몬스터를 잡는 경우 가장 쌘 몬스터의 파워 저장
            maxPower = max(maxPower, arr[i]);
            temp.first = maxPower;
            temp.second = 0;
            //가장 쌘 몬스터의 파워 이상인 영웅 찾기
            pii *it = lower_bound(piiArr, piiArr + m, temp);
            //그러한 영웅의 체력으로 count만큼의 몬스터를 연속으로 못잡는 경우
            if(maxArr[it - piiArr] < count)
            {
                maxPower = arr[i];
                count = 1;
                result++;
            }
            count++;
        }
        if(result < 0)
            result = -1;
        printf("%d\n", result);
    }
}