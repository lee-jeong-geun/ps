#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef struct _data
{
    int idx;
    int num;
}Data;
Data Num[5005];
int n, k, result[5005], Count[5005], chk[5005];

/*
1부터 k번째까지의 인덱스에는 무조건 1부터 k가 하나이상은 존재 해야하고
주어진 배열의 원소에 대해서 원소값이 같은 것은 색칠한 값이 동일해서는 안된다.
같은 원소값에 대해서 색칠한 값이 같아지려면 동일한 원소 개수가 k보다 커야된다.
그게 아니라면 동일한 원소에 대해서 색칠한 값이 두번이상 나올수가 없다.
따라서 원소를 받으면서 개수를 카운트 한 다음 원소 하나라도 k보다 큰값이 나오면 NO다.
이제 각각의 원소에 대해서 색칠을 해야 하는데 동일한 원소에 대해서만 색칠값이 중복 안되게 하면 되기 때문에
정렬을 해서 동일한 원소들 끼리 모여있게 한 다음 인덱스가 작은것부터 색칠을 하는데 각각의 인덱스들이
k이하라면 그 인덱스들로 색칠을 해준다. 그게 아닐 경우 쓰지 않은 색깔들로 색칠을 하면 된다.
*/

bool comp(Data t, Data u)
{
    if(t.num == u.num)
    {
        return t.idx < u.idx;
    }
    return t.num < u.num;
}

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &Num[i].num);
        Num[i].idx = i;
        Count[Num[i].num]++;
        if(Num[i].idx <= k)
        {
            result[i] = i;
        }
    }
    //같은 값에 대해 색칠한 값이 2번 이상 나올 경우
    for(int i = 1; i <= 5000; i++)
    {
        if(Count[i] > k)
        {
            printf("NO");
            return 0;
        }
    }
    sort(Num, Num + n + 1, comp);
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        //인덱스가 k이하일 경우
        if(Num[i].idx <= k)
        {
            //체크 배열에 1이아닌 색칠 값을 저장
            //저장된값이랑 현재 원소값이 같으면 패스
            chk[Num[i].idx] = Num[i].num;
            result[Num[i].idx] = Num[i].idx;
        }
        else
        {
            count++;
            if(count > k)
            {
                count = 1;
            }
            //다른 원소값에 대한 색칠 값
            if(chk[count] != Num[i].num)
            {
                result[Num[i].idx] = count;
            }
            //같은 원소값에 대한 색칠 값
            else
            {
                i--;
            }
            chk[count] = 0;
        }
    }
    printf("YES\n");
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", result[i]);
    }
}