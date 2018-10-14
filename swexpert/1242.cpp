#include <cstdio>
#include <iostream>
using namespace std;
int N, pos[15], weight[15];
double INF = 0.00000000000001;

/*
어떤 좌표 x에 대해서 해당 좌표가 균형점이 될수 있냐 없냐로 이분탐색을 돌리면 된다.
x의 왼쪽 자성체들의 힘이 오른쪽 보다 크면 x를 오른쪽으로 이동 시키고 그 반대면 왼쪽으로 이동 시킨다.
이러한 과정들을 N - 1번 반복 한다.
어떤 좌표 x값이 10 ^ -12 오차 범위 이내로 계속 같게 되면 균형점이 된다.
*/

//10 ^ -12 이내로 같은지 확인
bool chk(double a, double b)
{
    long long aa, bb;
    aa = a * 1000000000000;
    bb = b * 1000000000000;
    if(aa == bb)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 1; testcase <= C; testcase++)
    {
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &pos[i]);
        }
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &weight[i]);
        }
        printf("#%d ", testcase);
        //N - 1번 균형점 탐색
        for(int k = 0; k < N - 1; k++)
        {
            double l, r, left, right, d, mid = -1, bmid = -1;
            l = pos[k] + INF;
            r = pos[k + 1] - INF;
            while(l <= r)
            {
                left = 0;
                right = 0;
                //bmid는 이전 좌표값
                bmid = mid;
                mid = (l + r) / 2;
                for(int i = 0; i < N; i++)
                {
                    //왼쪽 자성체
                    if((double)pos[i] < mid)
                    {
                        d = mid - pos[i];
                        left += (double)weight[i] / (d * d);
                    }
                    //오른쪽 자성체
                    else if((double)pos[i] > mid)
                    {
                        d = mid - pos[i];
                        right += (double)weight[i] / (d * d);
                    }
                }
                //왼쪽 오른쪽이 같거나 오차 범위 이내로 균형점 값이 같은 경우
                if(left == right || chk(bmid, mid) == 1)
                {
                    printf("%.10lf ", mid);
                    break;
                }
                //왼쪽 자성체가 더 큰경우 균형점을 오른쪽으로 이동
                if(left > right)
                {
                    l = mid + INF;
                }
                else if(left < right)
                {
                    r = mid - INF;
                }
            }
        }
        printf("\n");
    }
}