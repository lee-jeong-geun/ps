#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<int, int> m;
int N, result;

/*
단순하게 해당 수의 개수가 수보다 작은지 큰지 확인 하고 개수를 세면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        m[num]++;
    }
    map<int, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++)
    {
        if(it->first > it->second)
        {
            result += it->second;
        }
        else if(it->first < it->second)
        {
            result += it->second - it->first;
        }
    }
    printf("%d", result);
}