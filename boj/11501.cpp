#include <cstdio>
#include <iostream>
using namespace std;
int N, Num[1000005], Stack[1000005], Top;
long long result;

/*
각각의 구간들을 나누는게 중요하다.
구간들의 끝은 그 구간의 최대값이다.
스택을 이용해서 구간들의 끝 값만 푸쉬해주면 된다.
최대값보다 작은 값이 있으면 최대값보다 큰 값이 나올때까지 pop 해준다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 0; testcase < T; testcase++)
    {
        Top = -1;
        result = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &Num[i]);
        }
        for(int i = 0; i < N; i++)
        {
            //자기 보다 큰값이 나올때까지 pop 해줌
            while(Top != -1 && Num[Stack[Top]] <= Num[i])
            {
                Top--;
            }
            Stack[++Top] = i;
        }
        int start = 0;
        for(int i = 0; i <= Top; i++)
        {
            long long hap = 0;
            //각 구간들의 값을 구함
            for(int j = start; j < Stack[i]; j++)
            {
                hap += Num[j];
            }
            result += (long long)Num[Stack[i]] * (Stack[i] - start) - hap;
            start = Stack[i] + 1;
        }
        printf("%lld\n", result);
    }
}