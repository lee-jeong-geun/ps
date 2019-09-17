#include <bits/stdc++.h>
using namespace std;
int n, x, result, Max, MaxD;

/*
x를 0으로 만들 수 있는지 확인 하려면 2가지만 보면 된다.
첫번째는 x - d로 0을 만들 수 있는지 보면 되고
두번째는 그게 안된다면 x를 계속 감소 시켜서 0으로 만들 수 있는지 확인 하는것이다.
계속 감소 시켜서 0으로 만드는건 결국 d - h가 하나라도 양수로 존재 한다는 것이다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        Max = -1234567890;
        MaxD = 0;
        result = 1;
        scanf("%d %d", &n, &x);
        for(int i = 0; i < n; i++)
        {
            int d, h;
            scanf("%d %d", &d, &h);
            //가장 큰 d값
            MaxD = max(MaxD, d);
            //가장 차이가 큰 값
            Max = max(Max, d - h);
        }
        x -= MaxD;
        if(x > 0)
        {
            //가장 큰 d - h가 양수가 아닌 경우
            if(Max <= 0)
                result = -1;
            else
            {
                //x를 d - h로 나눴을때 나머지가 존재 하는 경우
                if(x % Max != 0)
                    result++;
                //몇번만에 0으로 만드는지 확인
                result += x / Max;
            }
        }
        printf("%d\n", result);
    }
}