#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, ta, tb, k;
long long A[200005], B[200005], result;

/*
최대한 늦게 가게 하기 위해선 A배열에 있는 작은 값들 부터 제거 하는 방식으로 해야 한다.
A배열의 작은 원소부터 제거 하는 이유는 최대한 빠른 노선을 선택하기 때문에 A배열의 작은 원소들을 삭제하지
않고 큰 원소를 삭제 해도 작은 원소를 택하기 때문이다. A배열의 값을 선택 후 B배열의 원소를 선택해야 하는데
이때 A배열에서 선택한 원소 이상인 값을 선택 해야한다. 따라서 lower bound를 이용해 해당 인덱스를 찾은 후
해당 인덱스부터 남은 k개를 건너뛴 원소가 최적이 된다. 이런 방식으로 A배열에서 원소 하나 하나씩 최대 k개만큼
지워가면서 최대한 늦게 갈수 있는 노선을 선택하면 된다.
*/

int main()
{
    scanf("%d %d %d %d %d", &n, &m, &ta, &tb, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        A[i] += ta;
    }
    for(int i = 0; i < m; i++)
        scanf("%d", &B[i]);

    //A배열의 크기보다 k가 크거나 같으면 A배열을 다 삭제 가능
    if(k >= n)
    {
        printf("-1");
        return 0;
    }
    int idx;
    for(int i = 0; i < n; i++)
    {
        idx = lower_bound(B, B + m, A[i]) - B;
        //k개만큼 삭제를 했는데 B배열의 크기 이상인 경우
        if(idx + k >= m)
        {
            printf("-1");
            return 0;
        }
        result = max(result, B[idx + k]);
        k--;
        //k개를 다 삭제 했으면 더이상 탐색 불가
        if(k < 0)
            break;
    }
    printf("%lld", result + tb);
}