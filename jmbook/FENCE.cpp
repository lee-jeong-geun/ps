#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int N, fence[20005], result;
stack<int> s;

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        result = 0;
        scanf("%d", &N);
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &fence[i]);
        }
        fence[N + 1] = 0;
        s.push(0);
        for(int i = 1; i <= N + 1; i++)
        {
            while(s.top() != 0 && fence[s.top()] >= fence[i])
            {
                int temp;
                temp = s.top();
                s.pop();
                result = max(result, (i - 1 - s.top()) * fence[temp]);
            }
            s.push(i);
        }
        printf("%d\n", result);
    }
}