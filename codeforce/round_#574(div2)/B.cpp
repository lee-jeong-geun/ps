#include <bits/stdc++.h>
using namespace std;
long long n, k, result;

/*
잘 보면 n번의 연산을 하는데 있어서 더하기와 빼기만 있으므로 순서가 중요하지 않다는 것을 알 수 있다.
따라서 빼기 연산의 횟수를 mid값으로 잡고 1 ~ (n - mid)까지 더했을 때 값이 k보다 작다면 
빼기 연산을 줄이고 k보다 크다면 빼기 연산을 늘리는 파라매트릭 서치를 이용하면 된다.
*/

int main()
{
    scanf("%lld %lld", &n, &k);
    int l, r;
    l = 0;
    r = n;
    while(l <= r)
    {
        long long mid = (l + r) / 2, temp;
        //1 ~ (n - mid)까지의 합
        temp = (n - mid) * (n - mid + 1) / 2;
        if(temp - mid == k)
        {
            result = mid;
            break;
        }
        else if(temp - mid < k)
            r = mid - 1;
        else
            l = mid + 1;
        
    }
    printf("%lld", result);
}