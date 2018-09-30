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
Data up[500005], down[500005];
int N, M, chk[500005], uidx, didx, Minstart = 1234567890, Maxend;

/*
예제를 원형에서 선형으로 풀어쓰면 각 버스 노선들의 출발점과 끝점을 한눈에 알아 볼 수 있다.
잘 보면 a < b인 경우의 노선들은 그 노선 보다 a가 작거나 같고 b가 크거나 같은 노선에 포함 된다는걸 알 수 있다.
즉 a1 <= a2 && b2 <= b1이면 노선2는 노선1에 속한다. 노선들의 포함 관계를 다 확인 하는 경우는 O(M ^ 2)의 시간 복잡도가 걸린다.
하지만 이 노선들을 정렬 a를 오름차순으로 b를 내림차순으로 정렬 한다면 O(MlogM)의 복잡도로 확인 가능하다.
정렬 후 라인 스위핑 알고리즘을 이용하여 a, b를 계속 갱신하는 방식으로 0 ~ N - 1에 있는 노선들의 포함 관계를 빠르게 파악 할 수 있다.
이제 문제는 a > b 경우인 노선들을 확인 해야한다. a > b인 경우는 0을 통과해서 b까지 가는 경우이다. 따라서 a < b인 경우는 a > b인 경우를 무조건 
포함 할 수 없다. a > b인 경우가 a < b를 포함 하는 조건은 b를 확인 하면 된다. a > b는 0 ~ b이기 때문이다.
*/

//정렬 조건
bool comp(Data t, Data u)
{
    if(t.start == u.start)
    {
        return t.end > u.end;
    }
    return t.start < u.start;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        Data temp;
        scanf("%d %d", &temp.start, &temp.end);
        temp.idx = i + 1;
        //a < b인 경우
        if(temp.start < temp.end)
        {
            up[uidx++] = temp;
        }
        //a > b인 경우
        else
        {
            down[didx++] = temp;
            //a의 최소값
            Minstart = min(Minstart, temp.start);
            //b의 최대값
            Maxend = max(Maxend, temp.end);
        }
    }
    sort(up, up + uidx, comp);
    sort(down, down + didx, comp);
    int left, right;
    left = 1234567890;
    right = 0;
    for(int i = 0; i < uidx; i++)
    {
        //포함되면 체크함
        if(left <= up[i].start && up[i].end <= right)
        {
            chk[up[i].idx] = 1;
        }
        //포함이 아니라면 start, end 갱신
        else
        {
            left = up[i].start;
            right = up[i].end;
        }
        //a > b인 경우에 포함되면 체크
        if(Minstart <= up[i].start || up[i].end <= Maxend)
        {
            chk[up[i].idx] = 1;
        }
    }
    left = down[0].start;
    right = down[0].end;
    for(int i = 1; i < didx; i++)
    {
        if(left <= down[i].start && down[i].end <= right)
        {
            chk[down[i].idx] = 1;
        }
        else
        {
            left = down[i].start;
            right = down[i].end;
        }
    }
    for(int i = 1; i <= M; i++)
    {
        if(chk[i] == 0)
        {
            printf("%d ", i);
        }
    }
}