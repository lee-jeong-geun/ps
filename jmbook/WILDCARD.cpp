#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<string> vec;
int N, memo[105][105], wlength, flength;
char Wild[105], File[105];

int func(int depth, int idx)
{
    if(idx == flength && depth == wlength)
    {
        return 1;
    }
    if(depth == wlength || idx > flength)
    {
        return 0;
    }
    int &ret = memo[depth][idx];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    if(Wild[depth] != '*')
    {
        if(Wild[depth] == File[idx] || Wild[depth] == '?')
        {
            ret = max(ret, func(depth + 1, idx + 1));
        }
    }
    else
    {
        ret = max(ret, func(depth, idx + 1));
        ret = max(ret, func(depth + 1, idx));
    }
    return ret;
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        vec.clear();
        scanf("%s %d", Wild, &N);
        wlength = strlen(Wild);
        for(int i = 0; i < N; i++)
        {
            memset(memo, -1, sizeof memo);
            scanf("%s", File);
            flength = strlen(File);
            if(func(0, 0) == 1)
            {
                vec.push_back(File);
            }
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < vec.size(); i++)
        {
            printf("%s\n", vec[i].c_str());
        }
    }
}