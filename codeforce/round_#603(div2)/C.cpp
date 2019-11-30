#include <bits/stdc++.h>
using namespace std;
set<int> s;
int n;

/*
규칙을 잘 보면 n의 루트 n까지만 확인하면 다 확인 가능하다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        s.clear();
        scanf("%d", &n);
        int Sqrt = sqrt(n);
        for(int i = 1; i <= Sqrt; i++)
        {
            s.insert(n / i);
            s.insert(i);
        }
        s.insert(0);
        set<int>::iterator it;
        printf("%d\n", s.size());
        for(it = s.begin(); it != s.end(); it++)
        {
            printf("%d ", *it);
        }
        printf("\n");
    }
}