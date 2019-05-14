#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
set<int> s;
int n, arr[305];
long long result;

/*
최소 x는 주어진 약수들중에서 가장 작은값과 가장 큰값의 곱이다.
x를 구한 후 주어진 약수들이 x의 약수인지 확인 하고 x의 모든 약수들이 존재 하는지 확인하면 된다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++)
    {
        s.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            s.insert(arr[i]);
        }
        sort(arr, arr + n);
        //최소 x
        result = (long long)arr[0] * arr[n - 1];
        for(int i = 0; i < n; i++)
        {
            //x의 약수인지 확인
            if(result % arr[i] != 0)
            {
                result = -1;
                break;
            }
        }
        int Sqrt = sqrt(result);
        for(int i = 2; i <= Sqrt; i++)
        {
            //i가 x의 약수이고 i와 x / i가 약수로 주어졌는지 확인
            if(result % i == 0 && (s.find(i) == s.end() || s.find(result / i) == s.end()))
            {
                result = -1;
                break;
            }
        }
        printf("%lld\n", result);
    }
}