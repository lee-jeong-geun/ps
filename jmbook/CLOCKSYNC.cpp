#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec[15];
int Clock[20], result;

void func(int depth, int count)
{
    if(count >= result)
    {
        return;
    }
    if(depth == 10)
    {
        int clockCount = 0;
        for(int i = 0; i < 16; i++)
        {
            if(Clock[i] == 0)
            {
                clockCount++;
            }
            else
            {
                break;
            }
        }
        if(clockCount == 16)
        {
            result = min(result, count);
        }
        return;
    }
    func(depth + 1, count);
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 0; j < vec[depth].size(); j++)
        {
            Clock[vec[depth][j]] = (Clock[vec[depth][j]] + 3) % 12;
        }
        func(depth + 1, count + i);
    }
    for(int i = 0; i < vec[depth].size(); i++)
    {
        Clock[vec[depth][i]] = (Clock[vec[depth][i]] + 3) % 12;
    }
}

int main()
{
    vec[0] = {0, 1, 2};
    vec[1] = {3, 7, 9, 11};
    vec[2] = {4, 10, 14, 15};
    vec[3] = {0, 4, 5, 6, 7};
    vec[4] = {6, 7, 8, 10, 12};
    vec[5] = {0, 2, 14, 15};
    vec[6] = {3, 14, 15};
    vec[7] = {4, 5, 7, 14, 15};
    vec[8] = {1, 2, 3, 4, 5};
    vec[9] = {3, 4, 5, 9, 13};
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        result = 987654321;
        for(int i = 0; i < 16; i++)
        {
            scanf("%d", &Clock[i]);
            if(Clock[i] == 12)
            {
                Clock[i] = 0;
            }
        }
        func(0, 0);
        if(result == 987654321)
        {
            result = -1;
        }
        printf("%d\n", result);
    }
}