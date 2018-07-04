#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct _data
{
    int d, t;
}Data;
Data report[1000005];
int n, result;

/*
최대한 오늘로부터 멀게 과제 시작지점을 잡아야 하므로
뒤에서 부터 접근하면 훨씬 간단해 진다.
정렬 후 마감일이 가장 늦은 것부터 마감일에 근접하게 잡아주면서 탐색을 하면 된다.
*/

//마감일 기준 내림차순 정렬
bool operator < (Data t, Data u)
{
    return t.t > u.t;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &report[i].d, &report[i].t);
    }
    sort(report, report + n);
    result = report[0].t + 1;
    for(int i = 0; i < n; i++)
    {
        //과제 시작 지점이 마감일 보다 클 경우
        if(result > report[i].t)
        {
            //과제 끝 지점을 마감일로 맞춤
            result = report[i].t + 1;
        }
        //과제 진행일을 빼줌
        result -= report[i].d;
    }
    printf("%d", result - 1);
}