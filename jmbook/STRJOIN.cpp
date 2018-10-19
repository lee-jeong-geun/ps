#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int N, result;

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        result = 0;
        priority_queue<int> q;
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            int num;
            scanf("%d", &num);
            q.push(-num);
        }
        int str1, str2;
        while(q.size() > 1)
        {
            str1 = q.top();
            q.pop();
            str2 = q.top();
            q.pop();
            result += -(str1 + str2);
            q.push(str1 + str2);
        }
        printf("%d\n", result);
    }
}