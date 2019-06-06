#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int T, n, k, arr[200005], result, ridx;

/*
dk+1이 최소값이 되는 x를 찾아야 한다. 우선 k가 n - 1일 때 어떤 지점이 최소가 되는 x의 위치인지
찾아야 한다. 잘 보면 모든 거리차의 총합이 아닌 거리의 차를 찾는것이다. dk+1의 다음 위치들인
dk+2, dk+3, .... 들은 볼 필요가 없다. 또 dk-1, dk-2, ...들은 거리의 차이가 얼마든 간에
dK+1의 값 변동에 영향이 없다. 딱 dk+1만 보면 된다. k가 n - 1일때 dk+1은 a0을 기준으로 
an-1이 된다. 또 an-1을 기준으로 a0이 된다. 그렇다면 a0을 기준으로 dk+1을 최소 지점으로 만드는 x의
위치는 (a0 + an-1) / 2가 된다. 그 이유는 둘 사이의 가운데가 아닌 한쪽으로 쏠린 위치로 x를 잡으면
dk+1의 값이 커지기 때문이다. k가 n - 1일 때는 a0를 기준으로 a0+k를 잡았다. 같은 방식으로
ai를 기준으로 ai+k까지 잡고 가운데의 x의 위치를 찾으면 된다.
*/

int main()
{
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        result = 1234567890;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for(int i = 0; i < n - k; i++)
        {
            int l, r, mid, dis;
            //왼쪽 끝, 오른쪽 끝
            l = arr[i];
            r = arr[i + k];
            mid = (l + r) / 2;
            //x에서 왼쪽과 오른쪽 각각의 거리
            dis = max(mid - l, r - mid);
            //더 짧은 거리가 있다면 갱신
            if(result > dis)
            {
                result = dis;
                ridx = mid;
            }
        }
        printf("%d\n", ridx);
    }
}