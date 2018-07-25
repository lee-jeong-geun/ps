#include <cstdio>
#include <iostream>
using namespace std;
int N, button[105], M;

/*
문제의 주어진 조건에 맞게 구현을 하면 된다.
N이 100이라 O(N^2)으로 해결가능
버튼 상태 바꿔주는건 XOR 연산으로 가능
*/

int main()
{
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &button[i]);
    }
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        int mode, num;
        scanf("%d %d", &mode, &num);
        if(mode == 1)
        {
            //num의 배수 인덱스들 버튼 토글
            for(int j = num; j <= N; j += num)
            {
                button[j] ^= 1;
            }
        }
        else
        {
            int count = 0;
            //좌우 대칭 확인
            while(num - count >= 1 && num + count <= N)
            {
                if(button[num - count] != button[num + count])
                {
                    break;
                }
                count++;
            }
            button[num] ^= 1;
            for(int i = 1; i < count; i++)
            {
                button[num - i] ^= 1;
                button[num + i] ^= 1;
            }
        }
    }
    for(int i = 1; i <= N; i++)
    {
        printf("%d ", button[i]);
        if(i % 20 == 0)
        {
            printf("\n");
        }
    }
}