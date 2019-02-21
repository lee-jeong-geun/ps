#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, Sum[3][200005], result;

/*
홀수 짝수 인덱스를 나눠서 누적합을 구한 후 어떤 지점을 끊었을때 앞부분은 
홀수 짝수 그대로인데 끊은 지점 부터는 홀수 짝수 반대로 생각하면 된다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);
        Sum[0][i] = Sum[0][i - 1];
        Sum[1][i] = Sum[1][i - 1];
        //누적합
        if(i % 2 == 0)
        {
            Sum[0][i] += num;
        }
        else
        {
            Sum[1][i] += num;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int odd, even;
        //끊은 지점까지의 누적합 + 끊은 지점 이후의 홀짝 반대 누적합
        odd = Sum[1][i - 1] + Sum[0][n] - Sum[0][i];
        even = Sum[0][i - 1] + Sum[1][n] - Sum[1][i];
        if(odd == even)
        {
            result++;
        }
    }
    printf("%d", result);
}