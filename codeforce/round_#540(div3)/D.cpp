#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, Num[200005], result = 987654321;

/*
x일을 걸려서 m이상을 만들 수 있는지 확인 하는 방법은 각각의 날 마다 가장 큰 커피를 첫번째로 배치
하는것이다. 그러기 위해선 카페인으로 내림차순 정렬 후 가장 큰 수들을 첫번째 커피에 배치 후 나머지 커피들을
나머지에 계속 배치 하는 것이다.
그 전에 m이상을 만들기 위해 필요한 날들은 최대 n일 이다. 그리고 n은 최대 200000이라서 완전탐색으로는
불가능하고 x일동안 m이상을 만들 수 있는지 이분탐색을 하면 된다.
*/

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Num[i]);
    }
    //내림차순 정렬
    sort(Num, Num + n, greater<int>());
    int l, r;
    l = 1;
    r = n;
    while(l <= r)
    {
        long long Sum = 0;
        int mid;
        mid = (l + r) / 2;
        //mid일 동안 최대로 만들 수 있는 coursework
        for(int i = 0; i < n; i++)
        {
            Sum += max(0, Num[i] - i / mid);
        }
        //만들수 있다면 줄임
        if(Sum >= m)
        {
            result = min(result, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if(result == 987654321)
    {
        result = -1;
    }
    printf("%d", result);
}