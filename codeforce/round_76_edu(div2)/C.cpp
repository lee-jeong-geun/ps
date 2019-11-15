#include <bits/stdc++.h>
using namespace std;
vector<int> vec[200005];
int n, arr[200005], result;

/*
동일한 두 수 사이의 가장 짧은 거리를 구하면 된다. 두 수 사이에 어떤 수의 개수가 2개 보다
많으면 안된다. 하지만 잘 생각해 보면 전체 수에 대해서 동일한 두 수 사이의 거리를 구하는 과정에서
두 수 사이에 어떤 수의 개수가 2개보다 많아도 상관이 없는게 전체 수에 대해서 구하는거니까 당연하게
두 수 사이에 어떤 수에 대해서도 똑같이 길이를 구하게 된다. 따라서 모든 수에 대해서 가장 가까이
붙어 있는 동일한 수의 거리 차중 최소를 구하면 된다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int tc = 0; tc < T; tc++)
    {
        for(int i = 1; i <= n; i++)
        {
            vec[i].clear();
        }
        result = 987654321;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            //arr[i]수의 위치를 벡터[arr[i]]에 저장
            vec[arr[i]].push_back(i);
        }
        for(int i = 1; i <= n; i++)
        {
            //맨 앞인 0은 제외
            for(int j = 1; j < vec[i].size(); j++)
            {
                //i번째와 i - 1번째는 가장 가까이 붙어있는 수
                result = min(result, vec[i][j] - vec[i][j - 1] + 1);
            }
        }
        if(result == 987654321)
            result = -1;
        printf("%d\n", result);
    }
}