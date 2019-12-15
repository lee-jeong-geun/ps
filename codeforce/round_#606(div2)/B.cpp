#include <bits/stdc++.h>
using namespace std;
set<int> s;
int t, n, result;

/*
짝수를 홀수로 만들수 있냐라는 문제라서 애초에 홀수인 수들은 안봐도 된다.
큰 수들부터 홀수로 만들어가면 된다.
*/

int main()
{
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        s.clear();
        result = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            int num;
            scanf("%d", &num);
            if(num % 2 == 0)
                s.insert(num);
        }
        while(s.size() > 0)
        {
            int temp;
            //큰 수부터 확인
            temp = *s.rbegin();
            s.erase(temp);
            temp /= 2;
            //짝수면 set에 넣음
            if(temp % 2 == 0)
                s.insert(temp);
            result++;
        }
        printf("%d\n", result);
    }
}