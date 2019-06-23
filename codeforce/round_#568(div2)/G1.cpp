#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[20];
int n, T, memo[1 << 16][230][4];

/*
총 가짓수는 15!개가 나오기 때문에 시간안에 구할 수 없다.
따라서 비트마스크 dp를 이용해 dp[고른 것들][음악의 길이][이전에 고른 장르]로 메모이제이션 하면 된다.
*/

int func(int state, int Count, int before)
{
    if(Count == T)
        return 1;
    int &ret = memo[state][Count][before];
    if(ret != -1)
        return ret;
    ret = 0;
    for(int i = 0; i < n; i++)
    {
        //한번도 안고르고 이전 장르와 안겹치고 길이의 합이 T이하여야 함
        if((state & (1 << i)) != 0 || before == arr[i].second || Count + arr[i].first > T)
            continue;
        ret = (ret + func(state | (1 << i), Count + arr[i].first, arr[i].second)) % 1000000007;
    }
    return ret;
}

int main()
{
    scanf("%d %d", &n, &T);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    memset(memo, -1, sizeof memo);
    printf("%d", func(0, 0, 0) % 1000000007);
}