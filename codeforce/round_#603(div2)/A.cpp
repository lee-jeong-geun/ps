#include <bits/stdc++.h>
using namespace std;
int arr[5], result;

/*
개수가 제일 많은것과 그다음으로 많은것의 차이를 개수가 제일 작은것으로 최대한 줄여준다.
그리고 개수가 제일 작은것을 이등분해서 나머지에 이등분하고 그다음으로 개수가 2번째로 많은것을
개수가 제일 많은것에 할당하면 된다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        result = 0;
        for(int i = 0; i < 3; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + 3);
        int temp, div;
        //개수가 제일 많은것과 2번째로 많은것의 간격을 최대한 줄임
        temp = min(arr[2] - arr[1], arr[0]);
        result += temp;
        arr[2] -= temp;
        arr[0] -= temp;
        div = arr[0] / 2;
        result += div * 2 + arr[1] - div;
        printf("%d\n", result);
    }
}