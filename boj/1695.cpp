#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, Number[5005], memo[5000][5000];

/*
이 문제는 수열 사이 사이에 수를 끼워 넣을 수 있다.
왼쪽 끝 커서와 오른쪽 끝 커서 2개를 이용해서 비교를 한다.
왼쪽 커서가 가르키는 수와 오른쪽 커서가 가르키는 수가 같으면 두 커서 모두 가운데로 한칸 이동 시키고
다를 경우 왼쪽을 이동 시키거나 오른쪽을 이동 시킨다. 가운데로 모였을때 종료 시키면 된다.
*/

int func(int left, int right)
{
    if(left >= right)
    {
        return 0;
    }
    int &ret = memo[left][right];
    if(ret != -1)
    {
        return ret;
    }
    ret = 987654321;
    //같으면 두 커서 모두 이동
    if(Number[left] == Number[right])
    {
        ret = min(ret, func(left + 1, right - 1));
    }
    //다를 경우 한쪽만 이동
    ret = min(ret, func(left + 1, right) + 1);
    ret = min(ret, func(left, right - 1) + 1);
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Number[i]);
    }
    memset(memo, -1, sizeof memo);
    printf("%d", func(0, N - 1));
}