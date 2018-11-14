#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int day;
    int name;
    int value;
}Data;
Data arr[105];
int N, result, flag = -1, cow[5];

/*
이전 최대 생산 소와 현재 최대 생산 소가 다르면 결과값을 1 더해주면 된다.
최대 생산이 이전과 같을 경우가 있는데 이때 이전 소의 조합과 현재 소의 조합이 다르면 다른 경우다.
B E와 B E M은 다른 경우다.
*/

bool comp(Data t, Data u)
{
    return t.day < u.day;
}

int main()
{
    cow[0] = 7;
    cow[1] = 7;
    cow[2] = 7;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        char str[15], v;
        scanf("%d %s %c %d", &arr[i].day, str, &v, &arr[i].value);
        if(str[0] == 'M')
        {
            str[0] = 'A';
        }
        else if(str[0] == 'E')
        {
            str[0] = 'C';
        }
        arr[i].name = str[0] - 'A';
        if(v == '-')
        {
            arr[i].value *= -1;
        }
    }
    //날짜 순으로 정렬
    sort(arr, arr + N, comp);
    int Max, Midx;
    for(int i = 0; i < N; i++)
    {
        Max = -1;
        Midx = -1;
        cow[arr[i].name] += arr[i].value;
        for(int j = 0; j < 3; j++)
        {
            //최대값 갱신
            if(Max < cow[j])
            {
                Max = cow[j];
                Midx = (1 << j);
            }
            //최대값이 같을 경우 집합에 포함시킴
            else if(Max == cow[j])
            {
                Midx |= (1 << j);
            }
        }
        //이전 집합과 현재 집합이 다른경우
        if(Midx != flag)
        {
            flag = Midx;
            result++;
        }
    }
    printf("%d", result);
}