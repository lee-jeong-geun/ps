#include <cstdio>
#include <iostream>
using namespace std;
int N, Number[500005], chk[8005], hap, Max, Maxnum, flag;

void sort(int left, int right)
{
    int leftidx, rightidx, pivot;
    pivot = Number[(left + right) / 2];
    leftidx = left;
    rightidx = right;
    while(leftidx <= rightidx)
    {
        while(Number[leftidx] < pivot)
        {
            leftidx++;
        }
        while(pivot < Number[rightidx])
        {
            rightidx--;
        }
        if(leftidx <= rightidx)
        {
            int temp;
            temp = Number[leftidx];
            Number[leftidx] = Number[rightidx];
            Number[rightidx] = temp;
            leftidx++;
            rightidx--;
        }
    }
    if(left < rightidx)
    {
        sort(left, rightidx);
    }
    if(leftidx < right)
    {
        sort(leftidx, right);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &Number[i]);
        hap += Number[i];
        chk[Number[i] + 4000]++;
    }
    for(int i = 0; i <= 8000; i++)
    {
        if(Max < chk[i])
        {
            Max = chk[i];
            Maxnum = i;
            flag = 0;
        }
        else if(Max == chk[i] && flag == 0)
        {
            Maxnum = i;
            flag = 1;
        }
    }
    sort(0, N - 1);
    printf("%.0f\n", (double)hap / N);
    printf("%d\n", Number[N / 2]);
    printf("%d\n", Maxnum - 4000);
    printf("%d\n", abs(Number[N - 1] - Number[0]));
}