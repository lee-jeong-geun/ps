//divide and conquer

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, fence[20005];

int func(int left, int right)
{
    if(left == right)
    {
        return fence[left];
    }
    int mid, ret = 0, lidx, ridx, minheight = 987654321;
    mid = (left + right) / 2;
    lidx = mid;
    ridx = mid;
    ret = max(func(left, mid), func(mid + 1, right));
    while(left <= lidx && ridx <= right)
    {
        if(fence[lidx - 1] < fence[ridx + 1])
        {
            ridx++;
        }
        else
        {
            lidx--;
        }
        minheight = min(minheight, min(fence[lidx], fence[ridx]));
        ret = max(ret, (ridx - lidx + 1) * minheight);
    }
    return ret;
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        scanf("%d", &N);
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &fence[i]);
        }
        fence[0] = -1;
        fence[N + 1] = -1;
        printf("%d\n", func(1, N));
    }
}

//stack

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