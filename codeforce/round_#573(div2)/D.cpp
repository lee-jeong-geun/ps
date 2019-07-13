#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int n, arr[100005];
long long Sum;

/*
규칙을 잘 보면 최대한 같은 수가 나오지 않도록 수를 줄여야 한다. 이때 수를 제일 많이 줄일 수 있는 방법은
정렬을 하고 작은 수부터 최대한 줄이는데 이때 어디까지 줄여야 하냐면 줄였을 때
0, 1, 2, 3, 4, ... 이 순서가 되도록 줄이면 된다.
즉 2, 3, 5, 9는 줄였을 때 0, 1, 2, 3이 된다. 이렇게 줄이면서 몇번 연산을 했는지 합을 누적 시키고
해당 합이 짝수면 두번째가 이기고 홀수면 첫번째가 이긴다.
여기까지가 기본적인 방법이고 같은 수가 나오는 경우의 예외를 처리해 주어야 한다.
3, 3, 3, 5, 10처럼 첫번째 턴이 줄여도 무조건 같은 수가 나오는 경우는 두번째 턴이 이긴다.
그리고 0, 0, 1, 10 이나 1, 4, 5, 5처럼 첫번째 턴이 같은 수를 줄일 수 없는 경우도 두번째 턴이 이긴다.
이러한 예외들만 처리해 주면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        m[arr[i]]++;
    }
    int num = 0, count = 0, temp = -1, Max = -1;
    //같은 수가 몇개 나오는지 확인
    for(auto i = m.begin(); i != m.end(); i++)
    {
        //같은 수가 3개 이상이라면 두번째 턴 승리
        if(i->second > 2)
        {
            printf("cslnb");
            return 0;
        }
        if(i->second == 2)
        {
            temp = i->first;
            count++;
        }
    }
    //2, 2, 4, 4처럼 2번씩 나오는 수가 여러개인 경우 두번째 턴 승리
    if(count >= 2)
    {
        printf("cslnb");
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        //2번 나온 수보다 작은 수들중 제일 큰 값 탐색
        if(temp > arr[i])
            Max = max(Max, arr[i]);
    }
    //2번 나온 수가 0이거나 2번 나온 수보다 작은 수가 1차이 나는 경우 두번째 턴 승리
    if(temp == 0 || Max == temp - 1)
    {
        printf("cslnb");
        return 0;
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i++)
    {
        //0, 1, 2 ,3, .... 꼴로 만듬
        if(arr[i] - num >= 0)
        {
            Sum += arr[i] - num;
            num++;
        }
    }
    if(Sum % 2 == 0)
    {
        printf("cslnb");
        return 0;
    }
    printf("sjfnb");
}