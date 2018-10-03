#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int L;
    int R;
    int idx;
}Data;
Data zone[500005];
int N, Count[500005], Cidx = -1;

/*
먹이 사슬은 A(x1, x2), B(x3, x4) x1 <= x3 && x4 < x2 이거나 x1 < x3 && x4 <= x2일 경우에
B는 A에 속하게 된다.
따라서 L을 오름차순으로, R을 내림 차순으로 정렬 후에 각각의 먹이 사슬들이 최대 몇개를 포함하는지 탐색하면 된다.
정렬 후 brute force하게 찾으면 O(N ^ 2)의 시간 복잡도가 되므로 시간 초과가 나게 된다.
정렬 후의 모습을 잘 분석 해보면 각각의 먹이 사슬들을 R을 기준으로 최장 감소 부분 수열을 찾으면 된다.
이분탐색을 이용하여 O(NlogN)만에 해결 할 수 있다.
*/

//정렬 기준
bool comp(Data t, Data u)
{
    if(t.L == u.L)
    {
        if(t.R == u.R)
        {
            return t.idx < u.idx;
        }
        return t.R > u.R;
    }
    return t.L < u.L;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int num, L, R;
        scanf("%d %d %d", &num, &L, &R);
        zone[num - 1].L = L;
        zone[num - 1].R = R;
        zone[num - 1].idx = num;
    }
    sort(zone, zone + N, comp);
    for(int i = 0; i < N; i++)
    {
        int l, r;
        l = 0;
        r = Cidx;
        //현재 인덱스의 R을 이용하여 lower_bound를 찾음
        while(l <= r)
        {
            int mid;
            mid = (l + r) / 2;
            if(zone[Count[mid]].R > zone[i].R)
            {
                l = mid + 1;
            }
            else if(zone[Count[mid]].R == zone[i].R)
            {
                //L과 R이 같을 경우 제외
                if(zone[Count[mid]].L == zone[i].L)
                {
                    r = mid - 1;
                    continue;
                }
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        //lower_bound가 배열에 없을경우 추가 시켜줌
        if(l == Cidx + 1)
        {
            Cidx++;
        }
        Count[l] = i;
    }
    printf("%d", Cidx + 1);
}