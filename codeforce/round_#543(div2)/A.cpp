#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k, power[105], school[105], maxPower[105], result;

/*
출전 시키고 싶은 학생이 학교의 1등이 아니라면 결과값을 + 1 시켜준다.
*/

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &power[i]);
    }
    for(int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        school[i] = num;
        //해당 학교에 큰값을 저장
        maxPower[num] = max(maxPower[num], power[i]);
    }
    for(int i = 0; i < k; i++)
    {
        int num;
        scanf("%d", &num);
        num--;
        //1등이 아니라면 결과 + 1
        if(maxPower[school[num]] != power[num])
        {
            result++;
        }
    }
    printf("%d", result);
}