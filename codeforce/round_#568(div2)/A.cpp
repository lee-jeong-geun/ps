#include <bits/stdc++.h>
using namespace std;
int a[5], d, result;

/*
정렬을 후 첫번째와 두번째의 거리가 d이상이고 두번째와 세번째가 d 미만이라면
세번째를 이동시키는게 정답이고 두번째, 세번째의 거리가 d이상이고 첫번째, 두번째가 d미만이라면
첫번째를 옮기는게 정답이다. 1, 2, 3전부 거리 d미만이라면 1, 3을 옮기는게 정답이다.
*/

int main()
{
    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &d);
    sort(a, a + 3);
    if(abs(a[0] - a[1]) >= d)
    {
        if(abs(a[1] - a[2]) < d)
            result = a[1] + d - a[2];
    }
    else if(abs(a[1] - a[2]) >= d)
    {
        if(abs(a[0] - a[1]) < d)
            result = a[0] - a[1] + d;
    }
    else
    {
        result = a[1] + d - a[2] + a[0] - a[1] + d;
    }
    printf("%d", result);
}