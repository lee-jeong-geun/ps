#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, Num[200005], Max[5], result, resultNum[200005];
long long Sum;

/*
모든 수들의 합을 저장하고 배열에 있는 수들을 하나씩 지우면서 합이 남은 수들중 최대값의 * 2가 되는지
확인한다. 
*/

int main()
{
    scanf("%d", &n);
    //첫번째 큰수랑 2번째 큰수
    Max[0] = n;
    Max[1] = n;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Num[i]);
        Sum += Num[i];
        //첫번째 큰 수 보다 큰 경우
        if(Num[Max[0]] < Num[i])
        {
            //첫번째 큰 수를 두번째 큰 수로 저장
            Max[1] = Max[0];
            Max[0] = i;
        }
        //두번째 큰 수 보다 큰 경우
        else if(Num[Max[1]] < Num[i])
        {
            Max[1] = i;
        }
    }
    for(int i = 0; i < n; i++)
    {
        long long tempSum;
        //하나씩 지워봄
        tempSum = Sum - Num[i];
        //지운 수가 첫번째 큰 수
        if(Max[0] == i)
        {
            //두번째 큰 수랑 합이랑 비교
            if(tempSum == Num[Max[1]] * 2)
            {
                resultNum[result++] = i;
            }
        }
        else
        {
            if(tempSum == Num[Max[0]] * 2)
            {
                resultNum[result++] = i;
            }
        }
    }
    printf("%d\n", result);
    for(int i = 0; i < result; i++)
    {
        printf("%d ", resultNum[i] + 1);
    }
}