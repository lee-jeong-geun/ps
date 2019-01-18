#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int start;
    int end;
    int idx;
}Data;
Data seg[100005];
int T, n, result, chk[100005];

/*
모든 세그먼트들을 두개의 그룹으로 나누는데 각각의 세그먼트들에게서 겹치는 구간이 있다면 그 세그먼트들은
한개의 그룹에 편성 되어야한다. 따라서 모든 세그먼트들의 겹치는 구간이 있는지 파악하기 위해
l좌표로 오름차순 정렬 후 l이 같다면 r로 오름차순 정렬 한다.
이렇게 되면 겹치는 구간을 금방 찾을 수 있는데 스위핑 하면서 현재 세그먼트와 다음 세그먼트가 겹치는 구간이
발생하면 두개의 세그먼트를 합친다. 겹치는 구간이 발생하지 않는다면 반대 그룹으로 저장 시키고
또 발생하지 않는다면 반대 그룹으로 토글 하면서 저장 하면 된다.
*/

bool comp(Data &t, Data &u)
{
    if(t.start == u.start)
    {
        return t.end < u.end;
    }
    return t.start < u.start;
}

int main()
{
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        result = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            chk[i] = 0;
            scanf("%d %d", &seg[i].start, &seg[i].end);
            seg[i].idx = i;
        }
        sort(seg, seg + n, comp);
        int start, end, flag = 1;
        start = seg[0].start;
        end = seg[0].end;
        chk[seg[0].idx] = 1;
        for(int i = 1; i < n; i++)
        {
            //두개의 세그먼트가 겹침
            if(start <= seg[i].start && seg[i].start <= end)
            {
                chk[seg[i].idx] = flag;
                //합칠때 r을 더 큰 세그먼트의 r로 교체 시킴
                end = max(end, seg[i].end);
            }
            else
            {
                //1, 2토글
                flag = 3 - flag;
                chk[seg[i].idx] = flag;
                start = seg[i].start;
                end = seg[i].end;
                result = 1;
            }
        }
        //토글이 한번도 발생하지 않음
        //이런 경우는 모든 세그먼트의 겹치는 구간이 존재
        if(result == 0)
        {
            printf("-1\n");
            continue;
        }
        for(int i = 0; i < n; i++)
        {
            printf("%d ", chk[i]);
        }
        printf("\n");
    }
}