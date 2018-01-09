#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, C, LAN[200005], result;

/*
범위가 크기때문에 brute force로 접근하면 시간 초과가 난다.
각각의 집에서 x미터 간격으로 공유기 C개를 설치할수 있으면 간격을 늘리고
설치를 못한다면 간격을 줄인다.
집 i에서 i + 1에 x미터 간격으로 공유기를 설치 한다면 갯수를 카운터 해주고 
i + 1에서 i + 2에 x미터 간격으로 설치 하면 갯수를 카운터 해준다.
카운터가 C개 이상이면 x미터를 늘린다. C개가 안된다면 x미터를 줄인다.
x미터를 1씩 줄이거나 1씩 늘리면 시간 초과 이므로 이분탐색을 이용한다.
*/

int main()
{
    scanf("%d %d", &N, &C);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &LAN[i]);
    }
    int l, r;
    l = 0;
    r = 1234567890;
    sort(LAN, LAN + N);
    while(l <= r)
    {
        int mid, count = 1, Left = 0, Right = 1;
        mid = (l + r) / 2;
        //공유기 C개 이상 설치 가능 한지 확인
        while(Right < N)
        {
            //두 집 사이의 거리가 x미터 이상일시
            if(LAN[Right] - LAN[Left] >= mid)
            {
                //카운터 해줌
                count++;
                Left = Right;
                Right++;
            }
            //x미터 이상이 아니라면 그 다음 집을 선택
            else
            {
                Right++;
            }
        }
        //C개 이상 설치 가능시 x미터를 늘림
        if(count >= C)
        {
            result = max(result, mid);
            l = mid + 1;
        }
        //안될시 x미터를 줄임
        else
        {
            r = mid - 1;
        }
    }
    printf("%d", result);
}