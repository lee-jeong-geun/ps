#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int q;

/*
첫번째 구간에 속한 값 a와 두번째 구간에 속한 값 b를 찾아야 하는데
a와 b는 달라야 한다. 단순하게 첫번째 구간의 시작점과 두번째 구간의 시작점을 a와b로 두면 되는데
시작점이 같은 경우도 있으므로 같을 경우 b값을 1증가 시키면 된다.
*/

int main()
{
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        int l1, r1, l2, r2;
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        if(l1 == l2)
        {
            l2++;
        }
        printf("%d %d\n", l1, l2);
    }
}