#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef struct _data
{
    int s;
    int e;
}Data;
Data cow[20005];
int C, N, result;
multiset<int> s;

/*
소들을 끝점을 기준으로 내림차순 정렬후 끝점이 같으면 시작점으로 내림차순 정렬한다.
이제 각각의 소들이 닭을 선택 해야 하는데 시작점 끝점 사이에 있는 닭들중 가장 작은 닭을 선택 해야한다.
소들을 정렬 했기 떄문에 다음 소들이 닭을 선택 하려면 현재 소가 작은 닭을 골라야 다음 소들도 선택을 할 수 있기 때문이다.
선택한 닭은 지워 주어야 하는데 닭이 최대 20000마리 이기 때문에 탐색을 logN에 할 수 있고 
삭제를 해도 탐색을 계속 logN으로 하려면 set이나 map을 이용 하면 된다. 같은 값들이 여러개가 있을 수 있기
때문에 multiset을 이용해야 한다.
*/

//정렬 방법
bool comp(Data t, Data u)
{
    if(t.e == u.e)
    {
        return t.s < u.s;
    }
    return t.e < u.e;
}

int main()
{
    multiset<int> :: iterator it;
    scanf("%d %d", &C, &N);
    for(int i = 0; i < C; i++)
    {
        int num;
        scanf("%d", &num);
        s.insert(num);
    }
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &cow[i].s, &cow[i].e);
    }
    sort(cow, cow + N, comp);
    for(int i = 0; i < N; i++)
    {
        //소의 시작점 이상인 닭들중 가장 작은 값
        it = s.lower_bound(cow[i].s);
        //값이 존재하고 소의 끝점보다 이하인 닭일 경우
        if(it != s.end() && *it <= cow[i].e)
        {
            result++;
            //해당 닭 삭제
            s.erase(it);
        }
    }
    printf("%d", result);
}