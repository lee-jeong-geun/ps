#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int num;
    int idx;
}Data;
Data Num[100005];
int n, result[100005], resultIdx = 1;

/*
자기가 썼던 모자의 종류와 다른 모자들의 개수가 배열로 주어진다.
곧 자기가 썼던 같은 모자의 개수는 n - arr[i]개 이다.
따라서 정렬 후 현재 인덱스에서 같은 종류의 모자 개수만큼 인덱스를 건너 뛰면서
건너 뛴 곳의 모자 종류가 건너 뛰기 전 모자 종류와 같은지 확인한다. 다르면 Impossible이다.
*/

bool comp(Data &t, Data &u)
{
    if(t.num == u.num)
    {
        return t.idx < u.idx;
    }
    return t.num < u.num;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Num[i].num);
        Num[i].idx = i;
    }
    sort(Num, Num + n, comp);
    for(int i = 0; i < n; i++)
    {
        int nextIdx;
        //같은 종류의 모자 개수
        nextIdx = i + n - Num[i].num - 1;
        //같은 종류의 모자 개수가 부족한 경우
        if(Num[i].num != Num[nextIdx].num)
        {
            printf("Impossible");
            return 0;
        }
        //모자 종류 배정
        for(int j = i; j <= nextIdx; j++)
        {
            result[Num[j].idx] = resultIdx;
        }
        resultIdx++;
        i = nextIdx;
    }
    printf("Possible\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }
}