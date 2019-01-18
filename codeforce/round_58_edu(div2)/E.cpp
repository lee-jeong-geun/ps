#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, mx, my;

/*
가장 큰 x와 y를 가지고 있으면 된다.
? 쿼리가 올때 모든 지폐들을 비교 할 필요없이 (가장 큰 x <= h && 가장 큰 y <= w)
이거나 (가장 큰 y <= h && 가장 큰 x <= w)만 보면 되는데 그 이유는 가장 큰 지폐만 지갑에 들어 갈 수
있다면 나머지 지폐들은 무조건 지갑에 들어 갈 수 있기 때문에 가장 큰 크기만 가지고 있으면 된다.
*/

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x, y;
        char op;
        scanf(" %c %d %d", &op, &x, &y);
        if(op == '+')
        {
            //3, 2 와 2, 3과 같이 회전 하면
            //같은 크기인 지폐들을 처리하기 위함
            if(x > y)
            {
                swap(x, y);
            }
            //크기 갱신
            mx = max(mx, x);
            my = max(my, y);
        }
        else
        {
            if(mx <= x && my <= y || mx <= y && my <= x)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
}