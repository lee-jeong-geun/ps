#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
int N, P, result;

stack<int> s[7];

int main()
{
    scanf("%d %d", &N, &P);
    for(int i = 1; i <= 6; i++)
    {
        s[i].push(0);
    }
    for(int i = 0; i < N; i++)
    {
        int l, p;
        scanf("%d %d", &l, &p);
        if(s[l].top() < p)
        {
            result++;
            s[l].push(p);
        }
        else if(s[l].top() > p)
        {
            while(1)
            {
                if(s[l].top() <= p)
                {
                    if(s[l].top() < p)
                    {
                        result++;
                        s[l].push(p);
                    }
                    break;
                }
                else
                {
                    result++;
                    s[l].pop();
                }
            }
        }
    }
    printf("%d", result);
}