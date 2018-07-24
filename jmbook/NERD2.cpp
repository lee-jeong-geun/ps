#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
int N, result;
map<int, int> m;

int RightSearch(int p, int r)
{
    map<int, int>::iterator it = m.lower_bound(p);
    if(it == m.end() || r > it->second)
    {
        return 1;
    }
    return 0;
}

void LeftSearch(int p, int r)
{
    map<int, int>::iterator it = m.lower_bound(p);
    if(it == m.begin())
    {
        return;
    }
    --it;
    while(1)
    {
        if(it->second > r)
        {
            break;
        }
        if(it == m.begin())
        {
            m.erase(it->first);
            break;
        }
        m.erase(it->first);
        it = m.lower_bound(p);
        --it;
    }
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        result = 0;
        m.clear();
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            int p, r;
            scanf("%d %d", &p, &r);
            if(RightSearch(p, r) == 1)
            {
                LeftSearch(p, r);
                m[p] = r;
            }
            result += m.size();
        }
        printf("%d\n", result);
    }
}