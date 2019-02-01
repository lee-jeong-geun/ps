#include <cstdio>
#include <iostream>
using namespace std;
int N, M, J, result;

/*
떨어지는 사과가 바구니에 포함이 되지 않는 다면 이동 시킨다.
이동 시킬때 바구니의 맨 왼쪽 좌표와 맨 오른쪽 좌표를 확인 해서 사과에 더 가까운 쪽의 좌표를 사과의
좌표에 위치 시키면 된다.
*/

int main()
{
    int l, r;
    scanf("%d %d %d", &N, &M, &J);
    l = 1;
    r = M;
    for(int i = 0; i < J; i++)
    {
        int num;
        scanf("%d", &num);
        //오른쪽이 더 가까운 경우
        if(r < num)
        {
            result += num - r;
            r = num;
            l = r - M + 1;
        }
        //왼쪽이 더 가까운 경우
        else if(l > num)
        {
            result += l - num;
            l = num;
            r = l + M - 1;
        }
    }
    printf("%d", result);
}