#include <bits/stdc++.h>
using namespace std;
vector<int> result;
int n, arr[105], Sum;

/*
첫번째 숫자가 전체 합의 절반을 초과하는지 확인하고 안된다면
첫번째 수 / 2 이하인 수들을 추가시켜서 합의 절반을 초과하는지 확인하면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        Sum += arr[i];
    }
    result.push_back(1);
    int temp = arr[1];
    for(int i = 2; i <= n; i++)
    {
        if(arr[i] * 2 > arr[1])
            continue;
        result.push_back(i);
        temp += arr[i];
    }
    if(temp <= Sum / 2)
    {
        printf("0");
        return 0;
    }
    printf("%d\n", result.size());
    for(int i = 0; i < result.size(); i++)
    {
        printf("%d ", result[i]);
    }
}