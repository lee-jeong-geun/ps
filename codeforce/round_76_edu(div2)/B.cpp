#include <bits/stdc++.h>
using namespace std;
int x, y;

/*
규칙을 잘 보면 3*x/2는 x가 특정한 경우를 제외하고는 무조건 커지게 되어있다.
특정한 경우란 x가 1, 2, 3일때 이다. 따라서 이 경우들을 잘 처리해 주면 된다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int tc = 0; tc < T; tc++)
    {
        scanf("%d %d", &x, &y);
        //x를 y가 될때까지 1씩 감소시키면 됨
        if(x >= y)
            printf("YES\n");
        //x가 4이상이라면 무조건 y이상의 수로 만들수 있음
        else if(x >= 4)
            printf("YES\n");
        else if(x == 2 && y == 3)
            printf("YES\n");
        else
            printf("NO\n");
    }
}