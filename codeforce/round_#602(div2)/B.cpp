#include <bits/stdc++.h>
using namespace std;
set<int> s;
int n, arr[100005], result[100005], idx, flag;

/*
남아있는 수를 set에 넣어서 관리하고 q[i]가 주어질 때 q[i - 1]보다 크면
결과 배열에 바로 q[i]를 넣고 set에서 q[i]를 지워준다.
q[i - 1]이랑 q[i]가 같다면 set에서 q[i]보다 작은 수 하나를 결과 배열에 넣는데
이때 set에서 q[i]보다 작은 수가 없다면 -1을 출력 시키면 된다.
*/

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++)
    {
        s.clear();
        flag = 0;
        idx = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            s.insert(i + 1);
        }
        result[idx++] = arr[0];
        s.erase(arr[0]);
        for(int i = 1; i < n; i++)
        {
            //q[i]보다 q[i - 1]이 큰 경우
            if(arr[i] > arr[i - 1])
            {
                //바로 결과 배열에 값을 넣어줌
                result[idx++] = arr[i];
                s.erase(arr[i]);
            }
            else
            {
                int temp;
                temp = *s.begin();
                //set에서 제일 작은수가 q[i]보다 큰 경우는 -1
                if(temp > arr[i])
                    flag = 1;
                result[idx++] = temp;
                s.erase(temp);
            }
        }
        if(flag == 1)
            printf("-1\n");
        else
        {
            for(int i = 0; i < idx; i++)
            {
                printf("%d ", result[i]);
            }
            printf("\n");
        }
    }
}