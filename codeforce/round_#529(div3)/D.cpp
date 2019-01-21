#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int first;
    int second;
}Data;
Data Num[200005];
int n, result[200005], idx;

/*
모든 수들의 뒤와 뒤뒤의 정보들이 주어진다.
어떤 수 x를 기준으로 x뒤에 올 수 있는 숫자는 주어진 정보의 첫번째 수와 두번째 수중 하나다.
어떤것이 뒤인지 모르는데 첫번째 수가 뒤일 경우 첫번째 수의 정보에서 두번째 수가 반드시 나와야 한다.
나오지 않는다면 두번째 수가 뒤이다. 이런식으로 끝까지 순회하면서 결정 하면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &Num[i].first, &Num[i].second);
    }
    //n이 3일 경우는 1 2 3or 1 3 2이다.
    //어떤 것을 출력해도 상관없으므로 1 2 3으로 출력
    if(n == 3)
    {
        printf("1 2 3");
        return 0;
    }
    result[0] = 1;
    idx = 1;
    for(int i = 1; i < n; i++)
    {
        int first, second;
        first = Num[idx].first;
        second = Num[idx].second;
        idx = second;
        //첫번째 수의 (첫번째 or 두번째)에 두번째 수가 있다면 첫번째 수가 바로 뒤임
        if(Num[first].first == second || Num[first].second == second)
        {
            idx = first;
        }
        result[i] = idx;
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }
}