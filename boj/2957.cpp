#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int N;
long long depth[300005], result;
set<int> s;
set<int> :: iterator lbound;
set<int> :: iterator ubound;

int main()
{
    scanf("%d", &N);
    depth[0] = -1;
    depth[N + 1] = -1;
    s.insert(0);
    s.insert(N + 1);
    for(int i = 0; i < N; i++)
    {
        int a;
        scanf("%d", &a);
        s.insert(a);
        lbound = s.lower_bound(a);
        ubound = s.upper_bound(a);
        depth[a] = max(depth[*--lbound], depth[*ubound]) + 1;
        result += depth[a];
        printf("%ld\n", result);
    }
}