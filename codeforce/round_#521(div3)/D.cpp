#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int num;
    int count;
}Data;
Data Num[200005];
int n, k, Count[200005], Nidx, result;

/*
배열에서 k개를 고른 후 고른 수들을 배열에서 최대한 많이 지워야 한다.
우선 배열에 존재하는 수들을 같은 수끼리 합쳐서 개수로 나타낸다.
그리고 k개를 골라야 하는데 어떤것들을 골라야 할지 경우의 수도 많고 어렵다.
따라서 순서를 강제 할 필요가 있다. 우선 개수를 기준으로 내림차순 정렬을 한다.
그 이유는 최대한 개수가 많은 수들을 선택해야 배열에서 많이 지울수 있기 때문이다.
2번 예제를 보면 3 4개, 1 2개, 7 2개, 10 1개, 12 1개가 있다.
10이나 12를 고르면 1번밖에 못지우기 때문에 당연히 개수가 많은 3, 1, 7을 위주로 선택해야 한다.
이렇게 하고 이제 몇번을 지울수 있는지 찾아야 한다. 1번 지우기 위해서는 k개를 고른 수들이 각각 1개 이상
배열에 존재 해야한다. 2번 지우기 위해서는 각각 2개 이상 존재 해야 한다. 이 방식을 이용하여
x번 지울 수 있는지 이분 탐색을 한다. x번 지우지 못한다면 x를 내리고 지울 수 있다면 x를 올린다.
*/

bool comp(Data &t, Data &u)
{
    return t.count > u.count;
}

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        //같은 수들을 합침
        if(Count[num] == 0)
        {
            Num[Nidx++].num = num;
        }
        Count[num]++;
    }
    //합친 수들의 개수를 저장
    for(int i = 0; i < Nidx; i++)
    {
        Num[i].count = Count[Num[i].num];
    }
    sort(Num, Num + Nidx, comp);
    int l, r;
    l = 1;
    r = n;
    while(l <= r)
    {
        int mid, hap = 0;
        mid = (l + r) / 2;
        for(int i = 0; i < Nidx; i++)
        {
            //x번 지우기 위해 필요한 개수
            hap += Num[i].count / mid;
            if(Num[i].count / mid == 0)
            {
                break;
            }
        }
        //개수들의 합이 k개 이상이라면 지울수 있음
        if(hap >= k)
        {
            l = mid + 1;
            result = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    int resultCount = 0;
    for(int i = 0; i < Nidx; i++)
    {
        for(int j = 0; j < Num[i].count / result; j++)
        {
            printf("%d ", Num[i].num);
            resultCount++;
            if(resultCount == k)
            {
                return 0;
            }
        }
    }
}