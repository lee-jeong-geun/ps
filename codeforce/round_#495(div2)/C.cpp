#include <bits/stdc++.h>
using namespace std;
int n, arr[100005], chk[100005], chk2[100005], Count[100005];
long long result;

/*
누적합 배열을 만든 다음 주어진 배열을 앞에서 뒤로 탐색하면서 앞에서 나온 수가 아닌 경우는
누적합 배열에서 이전값에 1을 더하고 저장 한다. 이미 나온 값이라면 이전 값만 더해준다.
다 탐색 했으면 주어진 배열의 뒤에서부터 앞으로 이동하면서 뒤에서 나온 수가 아닌 경우에
누적합 배열에 저장되어있는 값을 더해주고 중복 표시를 한다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        //이전값을 저장
        Count[i] = Count[i - 1];
        //한번도 나온 수가 아닌경우 1을 더함
        if(chk[arr[i]] == 0)
        {
            Count[i]++;
            chk[arr[i]] = i;
        }
    }
    for(int i = n; i >= 2; i--)
    {
        //한번도 나온 수가 아닌 경우 누적합에 있는 값 더함
        if(chk2[arr[i]] == 0)
        {
            chk2[arr[i]] = i;
            result += Count[i];
            //같은 인덱스는 제외
            if(chk[arr[i]] == i)
                result--;
        }
    }
    printf("%lld", result);
}