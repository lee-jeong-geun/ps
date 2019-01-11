#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<int, int> m;
int n, Num[200005], result = 1;

/*
주어진 원소와 동일한 원소의 b값은 무조건 같기 때문에
동일한 원소들 사이의 수 또한 같아야 한다.
그리고 동일한 원소와 다른 원소와 구간이 겹치는 경우 그것 또한 b값이 같아야 한다.
따라서 모든 원소들의 동일한 값들을 찾아내어 구간을 형성 후 서로 겹치지 않는 구간들의 개수를 찾아내면 된다.
n은 최대 20만 이므로 수를 일일이 찾아내긴 힘들고 map을 이용하여 해당 값의 끝점을 빠르게 갱신후
스위핑 하면서 중복되지 않은 구간들을 찾아내면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Num[i]);
        m[Num[i]] = i;
    }
    int l, r;
    l = 0;
    r = m[Num[0]];
    for(int i = 1; i < n; i++)
    {
        //시작점이 현재 구간의 끝점보다 큰 경우
        if(r < i)
        {
            result = (result * 2) % 998244353;
            l = i;
        }
        //끝점이 현재 구간보다 큰 경우
        if(r < m[Num[i]])
        {
            r = m[Num[i]];
        }
    }
    printf("%d", result);
}