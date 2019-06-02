#include <cstdio>
#include <iostream>
using namespace std;
typedef struct _data
{
    int a, b;
}Data;
Data arr[300005];
int n, m;
int op1[4], op2[4];

/*
valid한지 안한지 확인하는 방법은 첫번째 인덱스의 a를 맞다 생각하고 그 a가 없는 인덱스의 a를 맞다고 생각
하는 방법과 첫번째 인덱스의 a를 맞다, 없는 인덱스의 b를 맞다 생각 하는 방법이랑
첫번째 인덱스의 b를 맞다, 없는 인덱스의 a를 맞다, 첫번째 인덱스의 b를 맞다, 없는 인덱스의 b를 맞다고
생각하는 경우들로 나눠서 해당 값들이 단한개라도 존재하는 쌍들의 개수를 파악하면서 개수가 m개가 되는지 확인하면 된다.
*/

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &arr[i].a, &arr[i].b);
    }
    //4가지 경우의 수들을 탐색
    op1[0] = arr[0].a;
    for(int i = 1; i < m ; i++)
    {
        if(arr[i].a != arr[0].a && arr[i].b != arr[0].a)
        {
            op2[0] = arr[i].a;
            op1[1] = arr[0].a;
            op2[1] = arr[i].b;
            break;
        }
    }
    op1[2] = arr[0].b;
    for(int i = 1; i < m; i++)
    {
        if(arr[i].a != arr[0].b && arr[i].b != arr[0].b)
        {
            op2[2] = arr[i].a;
            op1[3] = arr[0].b;
            op2[3] = arr[i].b;
            break;
        }
    }
    for(int i = 0; i < 4; i++)
    {
        int count = 0;
        for(int j = 0; j < m; j++)
        {
            //선택한 값 두개중 하나라도 있는 경우
            if(arr[j].a == op1[i] || arr[j].a == op2[i] || arr[j].b == op1[i] || arr[j].b == op2[i])
            {
                count++;
            }
        }
        //그러한 경우의 쌍의 개수가 m개인 경우
        if(count == m)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}