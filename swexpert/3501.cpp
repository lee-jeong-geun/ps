#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int p, q;
int Number[100005], chk[1000005];

/*
순환소수는 나머지가 같다는것을 이용하면 된다.
p를 q로 계속 나누었을때 나머지가 이전에 이미 나왔다면 이전에 나온 나머지부터 현재의 나머지까지 순환 된다는 것이다.
p를 q로 나눈 나머지를 저장해서 어떻게 순환 되는지 확인 하면 된다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        int tp, idx = 0, oidx = -1;
        memset(chk, -1, sizeof chk);
        scanf("%d %d", &p, &q);
        tp = p;
        tp %= q;
        //나누어 떨어지면 종료
        while(tp != 0)
        {
            //나눌수 없다면 *10
            if(tp / q == 0)
            {
                tp *= 10;
            }
            //이미 저장했던 나머지
            if(chk[tp] != -1)
            {
                oidx = chk[tp];
                break;
            }
            //나머지 저장
            chk[tp] = idx;
            Number[idx++] = tp;
            tp %= q;
        }
        printf("#%d %d", testcase, p / q);
        if(p % q != 0)
        {
            printf(".");
            for(int i = 0; i < idx; i++)
            {
                if(oidx == i)
                {
                    printf("(");
                }
                printf("%d", Number[i] / q);
            }
        }
        if(oidx != -1)
        {
            printf(")");
        }
        printf("\n");
    }
}