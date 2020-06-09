#include <bits/stdc++.h>
using namespace std;
int N, arr[100005][5], result, grade;

/*
몇개가 연속으로 나오는지 확인하면 된다.
*/

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }
    for(int i = 1; i <= 5; i++)
    {
        int count = 0;
        for(int j = 0; j < N; j++)
        {
            if(arr[j][0] != i && arr[j][1] != i)
                count = 0;
            else
                count++;
            if(result < count)
            {
                result = count;
                grade = i;
            }
        }
    }
    printf("%d %d", result, grade);
}