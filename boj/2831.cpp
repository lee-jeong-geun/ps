#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, man[2][100005], woman[2][100005], manIdx[5], womanIdx[5], result;

/*
우선 모든 그룹에 대해 내림 차순으로 정렬 후
키작은 여자를 선호하는 남자와 키큰 남자를 선호하는 여자를 매칭 시킨다. 반대의 경우도 같은 방법으로 매칭.
수가 많으므로 O(N^2)이 아닌 라인 스위핑을 이용하여 O(N)으로 매칭 시킨다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        //음수 양수들 그룹 분리
        if(num < 0)
        {
            man[0][manIdx[0]++] = -num;
        }
        else
        {
            man[1][manIdx[1]++] = num;
        }
    }
    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        if(num < 0)
        {
            woman[0][womanIdx[0]++] = -num;
        }
        else
        {
            woman[1][womanIdx[1]++] = num;
        }
    }
    //내림 차순으로 정렬
    sort(man[0], man[0] + manIdx[0], greater<int>());
    sort(man[1], man[1] + manIdx[1], greater<int>());
    sort(woman[0], woman[0] + womanIdx[0], greater<int>());
    sort(woman[1], woman[1] + womanIdx[1], greater<int>());
    int l, r;
    l = 0;
    r = 0;
    //키작은 여자 선호, 키큰 남자 선호
    while(l < manIdx[0] && r < womanIdx[1])
    {
        //여자가 남자보다 키가 작은 경우 매칭 시킴
        if(man[0][l] > woman[1][r])
        {
            result++;
            l++;
        }
        r++;
    }
    l = 0;
    r = 0;
    //키큰 여자 선호, 키작은 남자 선호
    while(l < manIdx[1] && r < womanIdx[0])
    {
        //여자가 남자보다 키가 큰 경우 매칭 시킴
        if(man[1][l] < woman[0][r])
        {
            result++;
            r++;
        }
        l++;
    }
    printf("%d", result);
}