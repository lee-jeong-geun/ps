#include <bits/stdc++.h>
using namespace std;
set<int> s, s2;
int N, result;

/*
수의 범위가 넓으므로 set을 이용한다.
1번 set에는 수 전체를 넣고 2번 set에는 한 번이라도 확인된 수를 넣는다.
1번 set에서 수를 하나씩 꺼내서 1과의 차를 구하고 꺼낸 수에서 계속 차를 더하면서 1번 set에 있으면 2번 set에 넣는다.
1번 set에서 처음 수를 꺼냈을 때 2번 set에 존재하는 수가 아닐 때만 결과값에 1을 더한다.
즉 두 번째 항인 경우에만 결과값에 1을 더한다
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        s.insert(num);
    }
    s.erase(1);
    set<int>::iterator it;
    for(it = s.begin(); it != s.end(); it++)
    {
        int num = *it, diff;
        if(s2.find(num) != s2.end())
            continue;
        diff = num - 1;
        result++;
        while(s.find(num) != s.end())
        {
            s2.insert(num);
            num += diff;
        }
    }
    printf("%d", result);
}