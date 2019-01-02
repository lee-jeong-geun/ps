#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int num;
    int idx;
}Data;
Data Num[200005];
int N, result[200005];

/*
규칙을 잘 찾다 보면 중간값은 정렬한 수열에서의 중간 인덱스만 가리키게 된다.
따라서 수열을 정렬 하고 해당 인덱스를 제거 했을때 중간값을 정렬 전 인덱스에 저장 후 출력하면 된다.
*/

bool comp(Data t, Data u)
{
    return t.num < u.num;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Num[i].num);
        Num[i].idx = i;
    }
    sort(Num, Num + N, comp);
    for(int i = 0; i < N; i++)
    {
        int temp;
        //중간값은 수열의 정중앙 2개중 하나다
        //중간보다 작은 인덱스는 정중앙 두번째 인덱스
        //중간보다 큰 인덱스는 정중앙 첫번째 인덱스
        temp = Num[N / 2].num;
        if(i >= N / 2)
        {
            temp = Num[N / 2 - 1].num;
        }
        //정렬 전 인덱스에 저장
        result[Num[i].idx] = temp;
    }
    for(int i = 0; i < N; i++)
    {
        printf("%d\n", result[i]);
    }
}