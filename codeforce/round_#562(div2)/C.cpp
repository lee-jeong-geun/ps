#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, arr[300005], result;

/*
a 배열에 아무거나 k개를 골라서 값을 (ai + 1) % m을 해서 오름 차순으로 만들어야 한다.
연산 한번에 a의 배열중 임의로 k개의 값을 증가시킨다. 이 연산을 최소화 시키는 방법은
우선 잘보면 값들을 최대한 증가시키지 않는게 이득이다. 어떤 뜻이냐면 
a1, a2, a3이 있을때 a1을 증가시키면 a2와 a3은 증가 시켜야 할 가능성이 높아진다.
즉 a1을 증가시키지 않고 그대로 냅두면 a2와 a3도 굳이 건들 필요가 없어진다.
하지만 증가시켜야 하는 경우가 생기는게 바로 앞 원소의 값이 현재 인덱스의 값보다 크다면
그때 증가 시켜야 한다. 이런 조건들을 만족시키면서 최대한 적게 연산을 이용하는 것이다.
하지만 이렇게 한다면 최대 k번의 연산을 이용해야 될 수 있다. k를 하나씩 증가시키면서 조건이 만족하는지
확인 하는 작업은 O(N * K)의 시간복잡도가 걸린다. 잘 보면 연산 5번을 사용해서 조건을 만족시키는 것은
10번을 해도 만족하게 되고 20번을 해도 만족하게 된다. 이러한 규칙을 이용하여 이분탐색으로 최소값을 찾으면 된다.
*/

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int l, r, mid, before, flag;
    l = 0;
    r = m - 1;
    while(l <= r)
    {
        mid = (l + r) / 2;
        before = arr[0];
        flag = 0;
        for(int i = 0; i < n; i++)
        {
            //첫번째 값은 0 or arr[0]
            if(i == 0)
            {
                if(arr[i] + mid >= m)
                    before = 0;
            }
            else
            {
                //현재 인덱스 값이 앞의 값보다 크고 m보다 작고 (현재 인덱스 값 + mid가 m보다 작거나 그값 % m 값이 before보다 작은경우) 갱신
                if(before < arr[i] && arr[i] < m && (arr[i] + mid < m || (arr[i] + mid) % m < before))
                    before = arr[i];
                //현재 인덱스 값에 mid를 더 했는데도 앞의 값보다 작으면 mid번 연산으로 조건 불만족
                else if(arr[i] + mid < before)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0)
        {
            result = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    printf("%d", result);
}