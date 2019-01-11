#include <cstdio>
#include <iostream>
using namespace std;
int n, Num[300005], Count[5];

/*
주어진 수들의 개수를 맞춰야 하는데 사전순으로 가장 빠른 결과로 맞춰야 한다.
사전순으로는 0, 1, 2 순서다. 따라서 각각의 원소들의 개수를 파악 후
0이 모자란 경우는 앞에서부터 접근하여 개수가 많은 원소를 0으로 교체해 주고
2가 모자란 경우는 뒤에서부터 접근하여 개수가 많은 원소를 2로 교체해 준다.
1은 우선 앞에서 부터 접근해서 2가 개수가 많을 경우 2를 1로 교체해 준다.
다 교체 했으면 뒤에서 부터 접근해서 0이 개수가 많을 경우 0을 1로 교체하면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%1d", &Num[i]);
        Count[Num[i]]++;
    }
    
    //개수가 다 맞을 경우
    if(Count[0] == Count[1] && Count[0] == Count[2])
    {
        for(int i = 0; i < n; i++)
        {
            printf("%d", Num[i]);
        }
        return 0;
    }
    //0이 모자란 경우
    if(Count[0] < n / 3)
    {
        for(int i = 0; i < n; i++)
        {
            if(Count[0] == n / 3)
            {
                break;
            }
            //0은 제일 빠르기 때문에 아무거나 교체함
            if(Num[i] != 0 && Count[Num[i]] > n / 3)
            {
                Count[0]++;
                Count[Num[i]]--;
                Num[i] = 0;
            }
        }
    }
    //2가 모자란 경우
    if(Count[2] < n / 3)
    {
        for(int i = n - 1; i >= 0; i--)
        {
            if(Count[2] == n / 3)
            {
                break;
            }
            //2는 제일 느리기 때문에 아무거나 교체함
            if(Num[i] != 2 && Count[Num[i]] > n / 3)
            {
                Count[2]++;
                Count[Num[i]]--;
                Num[i] = 2;
            }
        }
    }
    //1이 모자란 경우
    if(Count[1] < n / 3)
    {
        for(int i = 0; i < n; i++)
        {
            if(Count[1] == n / 3)
            {
                break;
            }
            //1은 2보다 빠르기 떄문에 2가 개수가 많으면 2를 교체
            if(Num[i] == 2 && Count[2] > n / 3)
            {
                Count[2]--;
                Count[1]++;
                Num[i] = 1;               
            }
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(Count[1] == n / 3)
            {
                break;
            }
            //위와 동일
            if(Num[i] == 0 && Count[0] > n / 3)
            {
                Count[0]--;
                Count[1]++;
                Num[i] = 1;               
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d", Num[i]);
    }
}