#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, Num[100005], Max, Count;
long long result;

/*
해당 가격 배열 인덱스에 카운트를 해주고 다 해준 뒤
큰 가격부터 내려가면서 배열에 저장된 갯수를 더하고 3을 나눈 몫을 해당 가격에 곱해서 
전체 가격에서 빼주면 된다.
다른 방법으로는 정렬 후 제일 큰 가격부터 접근을 하여 3개가 될때마다 하나씩 뺴주면 된다.
*/

int main()
{
    int T;
    scanf("%d", &T);
    for(int testcase = 1; testcase <= T; testcase++)
    {
        for(int i = 0; i <= Max; i++)
        {
            Num[i] = 0;
        }
        Count = 0;
        Max = 0;
        result = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            int price;
            scanf("%d", &price);
            //갯수 더함
            Num[price]++;
            //전체 가격 계산
            result += price;
            Max = max(Max, price);
        }
        int tcount = 0;
        for(int i = Max; i >= 1; i--)
        {
            //뺀 갯수가 전체갯수에서 3을 나눈 몫이면 끝
            if(Count == N / 3)
            {
                break;
            }
            //하나라도 있을 경우
            if(Num[i] != 0)
            {
                //전체 가격에서 뺴줌
                result -= (long long)(tcount + Num[i]) / 3 * i;
                //뺀 갯수 카운트
                Count += (tcount + Num[i]) / 3;
                //3으로 나눈 나머지를 더함
                tcount = (tcount + Num[i]) % 3;
            }
        }
        printf("#%d %ld\n", testcase, result);
    }
}