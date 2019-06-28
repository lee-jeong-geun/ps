#include <bits/stdc++.h>
using namespace std;
set<long long> s;
int n, d, result;
long long arr[105];

/*
배열의 각 요소에서 +d, -d를 했을때 다음 요소와의 차이가 d이상이 몇개 있는지 탐색하면 된다.
*/

int main()
{
    scanf("%d %d", &n, &d);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    arr[0] = -12345678900;
    arr[n + 1] = 12345678900;
    for(int i = 1; i <= n; i++)
    {
        //+d를 했을때 다음 요소와의 차이가 d이상이고 그 값이 셋에 없는 경우
        if(arr[i] + d <= arr[i + 1] - d && s.find(arr[i] + d) == s.end())
        {
            s.insert(arr[i] + d);
            result++;
        }
        if(arr[i] - d >= arr[i - 1] + d && s.find(arr[i] - d) == s.end())
        {
            s.insert(arr[i] - d);
            result++;
        }
    }
    printf("%d", result);
}