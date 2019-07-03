#include <bits/stdc++.h>
using namespace std;
int n;
double arr[100005];
long long Sum, arr2[100005];

/*
잘 보면 양수는 자기 자신에서 + 1, 음수는 자기 자신에서 - 1을 할 수 있다.
x.00000을 제외한 수들은 모두 내림이나 올림이 가능 하다.
따라서 모든 수들의 합을 구하고 그 합이 양수라면 음수쪽 수들을 합이 0이 될 때까지 -1을 해주고
합이 음수라면 양수쪽 수들을 합이 0이 될 때까지 +1을 해준다.
*/

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &arr[i]);
        arr[i] *= 100000;
        //double형은 나머지 연산 사용 못하므로 long long형 배열을 하나 만들어줌
        arr2[i] = (long long)arr[i];
        Sum += arr2[i] / 100000;
    }
    for(int i = 0; i < n; i++)
    {
        //x.00000인 수들은 올림, 내림이 안되므로 그냥 출력
        if(arr2[i] % 100000 == 0)
            printf("%d\n", arr2[i] / 100000);
        //합이 양수이면서 해당 수가 음수인 경우 -1
        else if(Sum > 0 && arr[i] < 0)
        {
            printf("%d\n", arr2[i] / 100000 - 1);
            Sum--;
        }
        else if(Sum < 0 && arr2[i] > 0)
        {
            printf("%d\n", arr2[i] / 100000 + 1);
            Sum++;
        }
        else
            printf("%d\n", arr2[i] / 100000);
    }
}