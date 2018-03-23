#include <cstdio>
#include <iostream>
using namespace std;
char Time[10][10] = {"O(N)", "O(N^2)", "O(N^3)", "O(2^N)", "O(N!)"};

/*
각각의 시간 복잡도를 구현하면 된다. 단 오버플로우를 주의해야 한다.
*/

int strcmp(char *str1, char *str2)
{
    while(*str1 != 0 || *str2 != 0)
    {
        if(*str1 > *str2)
        {
            return 1;
        }
        else if(*str1 < *str2)
        {
            return -1;
        }
        str1++;
        str2++;
    }
    return 0;
}

int main()
{
    int C;
    scanf("%d", &C);
    for(int testcase = 0; testcase < C; testcase++)
    {
        char S[15];
        int N, T, L, flag, rflag = 0;
        long long hap = 0;
        scanf("%s %d %d %d", S, &N, &T, &L);
        for(int i = 0; i < 5; i++)
        {
            if(strcmp(S, Time[i]) == 0)
            {
                flag = i;
            }
        }
        switch (flag)
        {
            case 0: hap = N; break;
            case 1: hap = (long long)N * N; break;
            case 2: hap = (long long)N * N * N; break;
        }
        //오버플로우 방지
        if(hap > 100000000000000)
        {
            hap /= 100;
        }
        if(flag == 3)
        {
            hap = 1;
            for(int i = 0; i < N; i++)
            {
                //오버플로우 방지
                if(hap > 1000000000)
                {
                    break;
                }
                hap *= 2;
            }
        }
        if(flag == 4)
        {
            hap = 1;
            for(int i = N; i >= 1; i--)
            {
                //오버플로우 방지
                if(hap > 1000000000)
                {
                    break;
                }
                hap *= i;
            }
        }
        hap *= T;
        //시간 안에 들어오면 정답
        if(hap <= 100000000 * L)
        {
            rflag = 1;
        }
        if(rflag == 1)
        {
            printf("May Pass.\n");
        }
        else
        {
            printf("TLE!\n");
        }
    }
}